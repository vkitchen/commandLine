/*!
 * @file
 * @brief Header file for compat.cpp
 * @details This header file declares functions for a compatibility layer between Window and Linux
 * directly
 */

#pragma once

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

#ifdef _WIN32
    #include <conio.h>
    #include <windows.h>
#else
    typedef char TCHAR;
    typedef short SHORT;
    typedef unsigned short WORD;
    typedef unsigned long DWORD;
    typedef unsigned int UINT;

    typedef struct {} HANDLE;

    typedef struct {
        SHORT X;
        SHORT Y;
    } COORD;

    typedef struct {
        struct {
            SHORT Top, Right, Bottom, Left;
        } srWindow;
        COORD dwSize;
        WORD wAttributes;
    } CONSOLE_SCREEN_BUFFER_INFO;

    typedef struct {
        bool bVisible;
    } CONSOLE_CURSOR_INFO;

    typedef struct {} HWND;

    extern HANDLE STD_OUTPUT_HANDLE;
    extern UINT CP_UTF8;
    extern int SW_MAXIMIZE;

    int _kbhit();
    int _getch();

    HANDLE GetStdHandle(HANDLE);
    void SetConsoleCursorPosition(HANDLE, COORD);
    bool GetConsoleCursorInfo(HANDLE, CONSOLE_CURSOR_INFO *);
    void SetConsoleCursorInfo(HANDLE, CONSOLE_CURSOR_INFO *);

    bool GetConsoleScreenBufferInfo(HANDLE, CONSOLE_SCREEN_BUFFER_INFO *);
    void SetConsoleScreenBufferInfo(HANDLE, CONSOLE_SCREEN_BUFFER_INFO *);

    void FillConsoleOutputCharacter(HANDLE, TCHAR, DWORD, COORD, DWORD *);
    void FillConsoleOutputAttribute(HANDLE, WORD, DWORD, COORD, DWORD *);

    void SetConsoleTextAttribute(HANDLE, WORD);
    bool SetConsoleOutputCP(UINT);
    bool SetConsoleCP(UINT);
    void ShowWindow(HWND, int);

    HWND GetConsoleWindow();
#endif

void msleep(DWORD milliseconds);
