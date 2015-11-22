#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

void background(void);
void coordinateAxis(COORD centr);
void print (COORD centr, int x, int y);
void graph (COORD centr, int k, int gr);
void function (int gr);

int main(){
    int x,y,k=20;
    int c=0,gr=1;
    background();
    COORD centr;
    centr.X=40;
    centr.Y=15;
    coordinateAxis(centr);
    graph(centr,k,gr);
	function(gr);
	    while (c != 27){ //27-esc для завершення роботи
        c = _getch();
        switch (c){
    case '8':
        centr.Y--;
        background();
        coordinateAxis (centr);
        graph (centr,k,gr);
        function(gr);
        break;
    case '5':
        centr.Y++;
        background();
        coordinateAxis (centr);
        graph (centr,k,gr);
        function(gr);
        break;
    case '4':
        centr.X--;
        background();
        coordinateAxis (centr);
        graph (centr, k,gr);
        function(gr);
        break;
    case '6':
        centr.X++;
        background();
        coordinateAxis (centr);
        graph (centr, k,gr);
        function(gr);
        break;
    case '+':
        k--;
        if (k == 0)
            k = 1;
        background();
        coordinateAxis (centr);
        graph (centr, k,gr);
        function(gr);
        break;
    case '-':
        k++;
        if (k == 0)
            k = 1;
        background();
        coordinateAxis (centr);
        graph (centr, k,gr);
        function(gr);
        break;
    case 32: // перехід до другого графіку
        gr = (gr == 1) ? 2 : 1;
		background();
        coordinateAxis (centr);
        graph (centr, k,gr);
        function(gr);
        break;
    }
    }

}

void background(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int color;

    color = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED |  BACKGROUND_INTENSITY;
    SetConsoleTextAttribute(hConsole, color);
    for (pos.Y = 0; pos.Y < 30; pos.Y++){
        for (pos.X = 0; pos.X < 80; pos.X++){
        SetConsoleCursorPosition(hConsole, pos);
        printf(" ");
        }
    }
}

void coordinateAxis(COORD centr){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
    COORD graph;
    SetConsoleTextAttribute(hConsole, color);

    graph.X = centr.X;
    for(graph.Y = 0; graph.Y < 25; graph.Y++){
        SetConsoleCursorPosition(hConsole, graph);
        if (graph.Y % 3 == 0)
            printf("--");
        else printf("|");
    }
    graph.Y = centr.Y;
    for (graph.X = 0; graph.X < 80; graph.X++){
        SetConsoleCursorPosition(hConsole, graph);
        if (graph.X % 4 == 0)
        printf ("|");
        else printf ("-");
    }
}

void print(COORD centr, int x, int y){
    COORD pos;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = BACKGROUND_BLUE | BACKGROUND_GREEN;
    SetConsoleTextAttribute(hConsole, color);
    pos.X = centr.X + x;
    pos.Y = centr.Y - y;
    if (pos.X >= 0 && pos.X <= 79){
    SetConsoleCursorPosition(hConsole, pos);
    printf(" ");
    }
}

void graph (COORD centr, int k, int gr){
    float x, y;
    for (x =-40; x < 40; x+=0.01){
        if(gr==1){
        y =((((-(pow(x,2)))*k/20+3)/3)+9)*k/20;//додала 3^2, щоб підняти графік на 3 одиниці вгору. Тут одиничний відрізок дорівнює двом символам
        } else if(gr==2){
            y = (tan(x*((k+0)/20)+2) +2)*(k+0)/20;
        }
    if (abs(y) <= 13){
        print (centr,x,y);
        }
    }
}

void function (int gr){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=4;
    pos.Y=20;
    SetConsoleCursorPosition(hConsole, pos);
    int cl = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED |  BACKGROUND_INTENSITY;
       SetConsoleTextAttribute(hConsole, cl);
    if (gr == 1)
        printf("F(x) = - x^2 + 3");
    if (gr == 2)
        printf("F(x) = tg(x + 2) + 2");
}


