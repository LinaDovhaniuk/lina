#include "func.h"

const char g_szClassName[] = "myWindowClass";

enum {
    STATIC_ID = 1,
    resButton,
    randButton,
};

HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                  )
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hInst = hInstance;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Pupils",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 400,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND nameStatic,surnameStatic,birthdayStatic,sexStatic,classStatic,specStatic,yearStatic,scoreStatic;
    static HWND name,surname,birthday,sex,Class,spec,year,score;
    static resetButton,randomButton;
    static char buf[100];
    switch(msg)
    {
        case WM_CREATE:
            resetButton = CreateWindowEx(0,
                              WC_BUTTON,
                              "Reset",
                              WS_CHILD | WS_VISIBLE  | WS_TABSTOP | BS_DEFPUSHBUTTON,
                              20, 290, 80, 23,
                              hwnd, (HMENU)resButton, hInst, NULL);
            randomButton = CreateWindowEx(0,
                              WC_BUTTON,
                              "Random",
                              WS_CHILD | WS_VISIBLE  | WS_TABSTOP | BS_DEFPUSHBUTTON,
                              120, 290, 100, 23,
                              hwnd, (HMENU)randButton, hInst, NULL);
            nameStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 20, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(nameStatic, TEXT("Name : "));
            surnameStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 50, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(surnameStatic, TEXT("Surname : "));
            birthdayStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 80, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(birthdayStatic, TEXT("Birthday : "));
            sexStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 110, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(sexStatic, TEXT("Sex : "));
            classStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 140, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(classStatic, TEXT("Class : "));
            specStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 170, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(specStatic , TEXT("Speciality : "));
            yearStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 200, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(yearStatic, TEXT("Year : "));
            scoreStatic = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              20, 230, 80, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(scoreStatic, TEXT("Score : "));


            name = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 20, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(name, TEXT(""));
            surname = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 50, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(surname, TEXT(""));
            birthday = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 80, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(birthday, TEXT(""));
            sex = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 110, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(sex, TEXT(""));
            Class = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 140, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(Class, TEXT(""));
            spec = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 170, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(spec , TEXT(""));
            year = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 200, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(year, TEXT(""));
            score = CreateWindowEx(0,
                              WC_STATIC,
                              "",
                              WS_CHILD | WS_VISIBLE,
                              120, 230, 100, 23,
                              hwnd, (HMENU)STATIC_ID, hInst, NULL);
            SetWindowText(score, TEXT(""));


            break;
        case WM_COMMAND: {
                switch (LOWORD(wParam)) {
                    case resButton: {
                        SetWindowText(name, TEXT(""));
                        SetWindowText(surname, TEXT(""));
                        SetWindowText(birthday, TEXT(""));
                        SetWindowText(sex, TEXT(""));
                        SetWindowText(Class, TEXT(""));
                        SetWindowText(spec , TEXT(""));
                        SetWindowText(year, TEXT(""));
                        SetWindowText(score, TEXT(""));

                        break;
                    }
                    case randButton: {


                        if((rand() % 2) == 0){
                            SetWindowText(sex, TEXT("Female"));
                            SetWindowText(name, TEXT(randFemaleName()));
                        }
                        else{
                            SetWindowText(sex, TEXT("Male"));
                            SetWindowText(name, TEXT(randMaleName()));
                        }
                        SetWindowText(surname, TEXT(randSurname()));
                        SetWindowText(birthday, TEXT(randBirthday()));
                        SetWindowText(Class, TEXT("11"));
                        SetWindowText(spec , TEXT(randSpeciality()));
                        SetWindowText(year, TEXT("2005"));
                        SetWindowText(score, TEXT(randScore()));

                        break;
                    }

                }
                break;
            }
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
