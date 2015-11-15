#include <stdio.h>
#include <windows.h>
int main(void)
{
    int i;
	int j;
    int k =0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const long SLEEP_MILLISECONDS = 2;
	COORD pos;  /* структура, що м≥стить позиц≥ю курсора */
    pos.X = 0;  /* номер стовпц€ */
    pos.Y = 0;  /* номер р€дка */
    i = 0;
	j = 24;
	SetConsoleTextAttribute(hConsole, k);
	for (i = 0; i < 25; i++)
		for (j = 0; j < 80; j++)
		{
			pos.X = j;
			pos.Y = i;
			SetConsoleCursorPosition(hConsole, pos);
			putchar(' ');
		}

    while (i < 80 && j >=0) {
  		for (; (j >= 0) && (i >= 0);i--)
		{
			switch (j){
        case 0...4 : k = BACKGROUND_RED | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 5...9:k = BACKGROUND_GREEN |BACKGROUND_RED| FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 10...14 :k = BACKGROUND_BLUE | BACKGROUND_RED | FOREGROUND_BLUE| FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 15...19 :
            k = BACKGROUND_RED | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 20...24:k = BACKGROUND_GREEN |BACKGROUND_RED| FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
            }
			SetConsoleTextAttribute(hConsole, k);
			pos.X = i;
			pos.Y = j;
			SetConsoleCursorPosition(hConsole, pos);
			printf("*");
			Sleep(SLEEP_MILLISECONDS);
			j--;
		}
		i++;
		j++;
		if (i == 0)
		{
			j--;
		}
		else
			i++;
		for (; (i < 80) && (j < 25); i++)
		{
			switch (j){
        case 0...4 : k = BACKGROUND_RED | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 5...9:k = BACKGROUND_GREEN |BACKGROUND_RED| FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
         case 10...14 :k = BACKGROUND_BLUE | BACKGROUND_RED | FOREGROUND_BLUE| FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 15...19 :
            k = BACKGROUND_RED | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        case 20...24:k = BACKGROUND_GREEN |BACKGROUND_RED| FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY;
            break;
        }
			SetConsoleTextAttribute(hConsole, k);
			pos.X = i;
			pos.Y = j;
			SetConsoleCursorPosition(hConsole, pos);
			printf("*");
			Sleep(SLEEP_MILLISECONDS);
			j++;
		}
		if (i == 80)
			j--;
		else
			i++;
		j--;
		i--;
    }
	SetConsoleTextAttribute(hConsole, k);
	return EXIT_SUCCESS;
}
