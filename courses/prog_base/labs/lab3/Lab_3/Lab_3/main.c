#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

void fillRand(unsigned int n,float mat[n][n],float a,float b);
void printMatrix(unsigned int n,float *mat);
void rotateCW90(unsigned int n,float mat[n][n]) ;
void zero_matrix(unsigned int n,float mat[n][n]);
void display_vertically(unsigned int n, float mat[n][n]);
void display_an_diagonally(unsigned int n, float mat[n][n]);
void SUM(unsigned int n,float mat[n][n]);
void sum_of_the_diagonal(unsigned int n, float *mat);
void SumStr(int n, float mat[n][n],  int row);
void fChanFmaxLmin (unsigned int n,float * mat);
void fChan(unsigned int n,float*mat);
void background(void);
void PrintMatrix(float *mat,unsigned int n);
void index(int eli, int elj, float num,unsigned int n,float mat[n][n]);
void change_the_rows (unsigned int n,float * mat);
void position (int x, int y);
void DeletSpace(char text[78]);
char * DelSp(char text[78]);
void Exit(void);

int main (void){
    int x=0,y=0;
    int sum=0;
    int i,j,input=0;
    unsigned int n;
    int row;
    float a,b,R;
    int eli, elj;
    int count;
    float num;
    char tmp[88];
    srand(time(NULL));
    char text[78];
    char * text1;
    text1=NULL;

    const char *menu[]={
    " ",
    ">     exit              exit the program",
    ">     zeroMat           NULL array",
    ">     fillRand          fill random array",
    ">     chVal             change the entered value",
    ">     flipV             display vertically",
    ">     flipD             display diagonally",
    ">     rotateCW90        turn 90 degrees tj the right",
    ">     SUM               Sum of all the matrix elements",
    ">     SumStr            Sum of the elements specified string of matrix",
    ">     SumDiag           Sum_of_the_diagonal",
    ">     fChan             Change first max and first min elements",
    ">     fChanFmaxLmin     Change first max and last min elements",
    ">     ChRows            Change lines with the most and least amount",
    " ",
    " ",
    "Please press Enter :) "};

    background();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |BACKGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);

    position(0,1);
    printf("*");
    for(x = 1,y = 0;x<79;x++){
        printf("-");
    }
    position(0,19);
    printf("*");
    for(x = 1,y = 19;x<79;x++){
        printf("-");
    }
    position(79,19);
   printf("*");
    position(79,1);
   printf("*");

    position ( 24, 9 );
    printf("Created by Lina Dovhaniuk KP - 51");
    puts("\n");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
   position ( 2, 22 );
   SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
   puts("                                                                             ");
   position(2,22);
   printf("Please enter the size of array (1 - 10) and press Enter twice ");
   int status = 1;
   while(status){
   if( !scanf("%i", &n)){
    fflush(stdin);
     SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
    printf("ERROR!Please enter the size again ");
    SetConsoleTextAttribute(hConsole,7);

    }
   else if (n < 11 && n > 0 ) status =0;

   else printf("\nERROR!Please enter the size again ");
   }
   puts("                                                  ");
   position ( 24, 9 );
   SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |BACKGROUND_RED |FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
    puts("                                                   ");
  // gets(tmp);
   //n=atoi(strpbrk(tmp,"-0123456789"));
    float mat[n][n];
   SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED |FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
   position ( 27, 9 );
   zero_matrix(n,mat);
   printMatrix(n,(float*)mat);
       SetConsoleTextAttribute(hConsole,7 );
            getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=22;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
   do{
    position(0,0);
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    position(2,40);
    printf("->                                                                            ");
    position(8,40);

    gets(text);
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |BACKGROUND_RED |FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    DeletSpace(text);
    position(5,22);
    SetConsoleTextAttribute(hConsole,7);
    for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
        puts("  ");
            }
        }
        if(strncmp(text,"exit",78)==0){
            Exit();
            break;
        }

        else if(strncmp(text,"help",78)==0){
                for (i=0,j=1;j<20;j++){
                position(24,22);
                puts("                                                                          ");
            }
            for(i=1; i<=16; i++){
                SetConsoleTextAttribute(hConsole,7);
                position(8,22+i);
                puts(menu[i]);
            }
            SetConsoleTextAttribute(hConsole,7 );
           /* getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<80;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }*/
        }
        else if(strncmp(text,"zeroMat",78)==0){
            for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
        SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
        zero_matrix(n,mat);
        printMatrix(n,(float*)mat);
        SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }

      else if(strncmp(text,"fillRand",8)==0){
        SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
      int status = 0;
      float min, max;
      position(8,41);
      SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
printf("Please enter the float limits and press Enter ");
    if(!scanf("%f", &min)||!scanf("%f", &max))
      {
          fflush(stdin);
          SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
          printf("\nError");

          status = 1;
      }
      if(max<min){
        float t = max;
        min = max;
        min = t;
      }
      if (!status){
            SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
      fillRand(n,mat,min,max);
      printMatrix(n,(float*)mat);
                }
                SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=35;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        else if(strncmp(text,"chVal",12)==0){
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
     position ( 2, 40 );
     puts("                                                 ");
     int status = 0;
      float num;
      int eli,elj;
      printf("Please ehter the index 'i' and 'j' ");
    if(!scanf("%i", &eli)|| !scanf("%i", &elj)){
          fflush(stdin);
          SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
          printf("error");
          status = 1;
      }
    printf("\nEnter the float value ");
      if(!scanf("%f", &num)){
          fflush(stdin);
          SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
          printf("error");
          status = 1;
      }
      if(eli>n||elj>n){
          fflush(stdin);
          SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
          printf("Error");
          status = 1;
      }

      if (!status){
            SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    index(eli,elj,num,n,mat);
    printMatrix(n,(float*)mat);
                }
                SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
    }

    else if(strncmp(text,"flipV",78)==0){
            for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
    SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
        display_vertically(n,mat);
        printMatrix(n,(float*)mat);
        }
        else if(strncmp(text,"flipD",78)==0){
              for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
            SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    display_an_diagonally(n,mat);
    printMatrix(n,(float*)mat);
    SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        else if(strncmp(text,"rotateCW90",78)==0){
            for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
    SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    rotateCW90(n,mat);
    printMatrix(n,(float*)mat);
    SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        else if(strncmp(text,"SUM",78)==0){
                for (i=0;j<20;j++){
                position(24,9);
                puts("                                                                                 ");
            }
        position(8,41);
         SetConsoleTextAttribute(hConsole,7 );
        SUM(n,mat);
        SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
}
        else if(strncmp(text,"SumStr",6)==0){
            int status = 0;
        int row;
        SetConsoleTextAttribute(hConsole,7 );
            for (i=0,j=0;j<20;j++){
                position(24,20);
                puts("                                                                                 ");
            }
        SetConsoleTextAttribute(hConsole,7 );
        position(8,41);
        printf("Plesae enter the row ");
                if(!scanf("%i", &row)){
                    fflush(stdin);
                    position(8,45);
                    SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    printf("ERROR!");
                    status = 1;
                }
                else
                if(row>n){
                    fflush(stdin);
                    position(8,45);
                    SetConsoleTextAttribute(hConsole,FOREGROUND_RED|FOREGROUND_INTENSITY);
                    printf("ERROR!");
                    status = 1;
                }
      /*  SetConsoleTextAttribute(hConsole,7 );
            for (i=0,j=0;j<20;j++){
                position(24,41);
                puts("                                                                                 ");
            }*/
        SetConsoleTextAttribute(hConsole,7 );
        position(24,41);
                puts("                                                                                 ");
        SumStr(n,mat,row);
        SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf("                             ");
            }
        }
        }


        else if(strncmp(text,"SumDiag",78)==0){
            for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
            position(8,41);
             SetConsoleTextAttribute(hConsole,7 );
            sum_of_the_diagonal(n,(float*)mat);
            SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        else if(strncmp(text,"fChan",78)==0){
             for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
    SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    fChan(n,(float*)mat);
    printMatrix(n,(float*)mat);
    SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        else if(strncmp(text,"fChanFmaxLmin",78)==0){
            for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
    SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    fChanFmaxLmin (n,(float *) mat);
    printMatrix(n,(float*)mat);
    SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        else if(strncmp(text,"ChRows",78)==0){
            for (i=0;j<20;j++){
                position(24,9+i);
                puts("                                                                                 ");
            }
    SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED| FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    change_the_rows (n,(float*)mat);
     printMatrix(n,(float*)mat);
     SetConsoleTextAttribute(hConsole,7 );
        getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=40;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }
        }
        SetConsoleTextAttribute(hConsole,7 );
        /*getch();
            for(pos.X=0;pos.X<80;pos.X++){
            for(pos.Y=22;pos.Y<45;pos.Y++){
            SetConsoleCursorPosition(hConsole,pos);
                printf(" ");
            }
        }*/
}
    while(1);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    position(0,25);
    return 0;
   }


   /* SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
     position ( 2, 22 );
     puts("                                                 ");
   printf("Please enter the limits");
  scanf("%f %f",&a,&b);
  SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE |BACKGROUND_RED |FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
   fillRand(n,(float*)mat,a,b);
   printMatrix(n,(float*)mat);

   rotateCW90(n,(float*)mat);
   printMatrix(n,(float*)mat);

   display_vertically(n,(float*)mat);
   printMatrix(n,(float*)mat);

   display_an_diagonally(n,(float*)mat);
   printMatrix(n,(float*)mat);

   SUM(n,(float*)mat);

   sum_of_the_diagonal(n,(float*)mat);
   SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN |  FOREGROUND_INTENSITY);
    position ( 2, 22 );

    printf("Please enter the row\n");
   gets(tmp);
   r=atoi(strpbrk(tmp,"-0123456789"));
   SumStr(n, (float *)mat,r);

    fChanFmaxLmin (n,(float *) mat);
    printMatrix(n,(float*)mat);

    fChan(n,(float*)mat);
    printMatrix(n,(float*)mat);

    change_the_rows (n,(float*)mat);
     printMatrix(n,(float*)mat);

   printf("Please enter the Index i, Index j, value ");
   scanf("%i %i %f",&eli,&elj,&num);

   index(eli,elj,num,n,(float *)mat);
    printMatrix(n,(float*)mat);
*/



void printMatrix(unsigned int n,float *mat) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    unsigned int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        position ( 38-n*3+j*6+j, 10 - n/2+i );
        printf("%.2f ", *(mat+i*n+j));
        }

    if ( i < n -1)
    printf("\n ");
}
printf("\n\n");
}

void zero_matrix(unsigned int n,float mat[n][n]){
    unsigned int i,j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			mat[i][j] =0;
		}
	}
}

void fillRand(unsigned int n,float mat[n][n],float a,float b){
    int i,j;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			mat[i][j] =(a+(b-a)*(float)rand()/(float)RAND_MAX);
		}
	}
}

void index(int eli, int elj, float num,unsigned int n,float mat[n][n]){
    mat[elj][eli]=num;
}


void display_vertically(unsigned int n, float mat[n][n]) {
    int i, j;
    float tmp;
    for(i = 0; i < n ; i++)
        for(j = 0; j < n/2; j++) {
            tmp = mat[i][j];
            mat[i][j] = mat[i][n-1-j];
            mat[i][n-1-j]= tmp;
        }
}

void display_an_diagonally(unsigned int n, float mat[n][n]) {
    int i, j;
    float p;
    for(i = 0; i < n ; i++)
        for(j = i; j < n; j++) {
            p = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = p;
        }
}

void rotateCW90(unsigned int n,float mat[n][n]){
    int i,j;
    float matrix[n][n];
for (i=0; i<n; i++){
    for (j=0; j<n; j++){
        matrix[i][j]=mat[n-1-j][i];
        }
}for (i=0; i<n; i++){
    for (j=0; j<n; j++){
       mat[i][j]=matrix[i][j];
    }
}
}

void SUM(unsigned int n,float mat[n][n]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i,j;
    float sum=0;

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			sum+=mat[i][j];
		}
	}
	 SetConsoleTextAttribute(hConsole,7 );
	printf("Sum is : %.2f\n\n", sum);
}

//сума елементів рядка
void SumStr(int n, float mat[n][n], int row){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int j;
    float sumStr=0;

    for (j=0; j<n; j++){
        sumStr+= mat[row][j];
    }
     SetConsoleTextAttribute(hConsole,7 );
     position(8,41);
    printf("SumStr is : %.2f \n\n", sumStr);
}


//сума елементів гол діагоналі і над нею
void sum_of_the_diagonal(unsigned int n, float *mat){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i,j;
    float summ=0;

    for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                if(i<=j){
                summ+= *(mat+i*n+i);
                }
            }
    }
     SetConsoleTextAttribute(hConsole,7 );
     position(8,41);
    printf("Sum is : %.2f\n\n", summ);
}

//перший мінімальний і перший максимальний
void fChan (unsigned int n,float * mat){
    int i,j;
    float tmp;
    float Fmax=*mat,Fmin=*mat;
    int k=0,x=0,q=0,m=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(Fmax<*(mat+i*n+j))
            {
                Fmax=*(mat+i*n+j);
                k=i;
                x=j;
            }
            else if(Fmin>*(mat+i*n+j)){
                Fmin=*(mat+i*n+j);
                q=i;
                m=j;
            }
    tmp=*(mat+k*n+x);
    *(mat+k*n+x)=*(mat+q*n+m);
    *(mat+q*n+m)=tmp;
}

void fChanFmaxLmin (unsigned int n,float * mat){
    int i,j;
    float t;
    float Fmax=*mat,Lmin=*mat;
    int k=0,x=0,q=0,m=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(Fmax<=*(mat+i*n+j))
            {
                Fmax=*(mat+i*n+j);
                k=i;
                x=j;
            }
            else if(Lmin<*(mat+i*n+j)){
                Lmin=*(mat+i*n+j);
                q=i;
                m=j;
            }
    t=*(mat+k*n+x);
    *(mat+k*n+x)=*(mat+q*n+m);
    *(mat+q*n+m)=t;
}



void change_the_rows (unsigned int n,float * mat){
    int i,j, mindex=0, Mindex=0;
    double msum = 0, Msum = 0, sum = 0;
    for (i=0; i<n; i++){
        for(j=0; j<n; j++){
            sum+=*(mat + n*i + j);
        }
        if(i==0){
            msum = sum;
            Msum= sum;
        }
        else{
            if(sum<msum){
                msum = sum;
                mindex = i;
            }
            else if(sum>Msum){
                Msum = sum;
                Mindex = i;
            }
         }
    }
for(j=0; j<n;j++){
    float tmp = *(mat +n*Mindex+j);
    *(mat + n*Mindex +j) = *(mat + n*mindex + j);
    *(mat+ n*mindex +j) = tmp;

}
}

void background(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;

    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE |BACKGROUND_RED );
    for (pos.Y = 1; pos.Y < 20; pos.Y++){
        for (pos.X = 0; pos.X < 80; pos.X++){
        SetConsoleCursorPosition(hConsole, pos);
        printf(" ");
        }
    }

    puts("\n");
}

void position (int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void DeletSpace(char text[78]){
    while(text[0]==' ')
    {
        for(int i=0; i<=77; i++)
            text[i]=text[i+1];
    }
    text[78]=' ';
}
char * DelSp(char text[78]){
    int i,j;
    static char test[78];
    for(i = j = 0; i<78; i++)
        if(text[i] != ' ')
            test[j++] = text[i];
    test[j] = '\0';
    return test;
}

void Exit(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    for(int i=0; i<80; i++)
        for(int j=0; j<60; j++)
        {
            position(i,j);
            SetConsoleTextAttribute(hConsole,7);
            printf(" ");
        }
}







