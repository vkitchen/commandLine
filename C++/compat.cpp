#include "compat.hpp"

#ifdef _WIN32
    void msleep(DWORD milliseconds) {
        return Sleep(milliseconds);
    }
#else
    #include <iostream>
    #include <stdio.h>
    #include <sys/select.h>
    #include <sys/ioctl.h>
    #include <termios.h>
    #include <unistd.h>

    HANDLE STD_OUTPUT_HANDLE;
    UINT CP_UTF8;
    int SW_MAXIMIZE;

    void msleep(DWORD milliseconds) {
        usleep(milliseconds * 1000);
    }

    // https://www.flipcode.com/archives/_kbhit_for_Linux.shtml
    int _kbhit() {
        static const int STDIN = 0;
        static bool initialized = false;

        if (! initialized) {
            // Use termios to turn off line buffering and echo
            termios term;
            tcgetattr(STDIN, &term);
            term.c_lflag &= ~ICANON;
            term.c_lflag &= ~ECHO;
            tcsetattr(STDIN, TCSANOW, &term);
            setbuf(stdin, NULL);
            initialized = true;
        }

        int bytesWaiting;
        ioctl(STDIN, FIONREAD, &bytesWaiting);
        return bytesWaiting;
    }

    static int leftArrow = 75;
    static int rightArrow = 77;
    static int upArrow = 72;
    static int downArrow = 80;
    static int enter = 13;
    static int plusSymbol = 61;
    static int minusSymbol = 45;
    static int backspace = 8;
    static int esc = 27;

    // https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
    int _getch() {
        static const int STDIN = 0;
        static bool initialized = false;

        if (! initialized) {
            // Use termios to turn off line buffering and echo
            termios term;
            tcgetattr(STDIN, &term);
            term.c_lflag &= ~ICANON;
            term.c_lflag &= ~ECHO;
            tcsetattr(STDIN, TCSANOW, &term);
            setbuf(stdin, NULL);
            initialized = true;
        }

        int c = getchar();
        switch (c) {
            case '\n':
                return enter;
            case '+':
                return plusSymbol;
            case '-':
                return minusSymbol;
            case 27:
                int c = getchar();
	        if (c == 91) {
                    switch (getchar()) {
                        case 65:
                           return upArrow;
                        case 66:
                           return downArrow;
                        case 67:
                           return rightArrow;
                        case 68:
                           return leftArrow;
	            }
	        }
                break;
	}
	return c;
    }

    HANDLE GetStdHandle(HANDLE) {
        HANDLE h;
        return h;
    }

    void SetConsoleCursorPosition(HANDLE, COORD coord) {
        std::cout << "\033[" << coord.Y << ';' << coord.X << 'H';
    }

    bool GetConsoleCursorInfo(HANDLE, CONSOLE_CURSOR_INFO *) {
	    return true;
    }

    void SetConsoleCursorInfo(HANDLE, CONSOLE_CURSOR_INFO *cursorInfo) {
        if (cursorInfo->bVisible)
            std::cout << "\e[?25h";
        else
            std::cout << "\e[?25l";
    }

    bool GetConsoleScreenBufferInfo(HANDLE, CONSOLE_SCREEN_BUFFER_INFO *csbi) {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        csbi->dwSize.X = w.ws_col;
        csbi->dwSize.Y = w.ws_row;
        csbi->srWindow.Top = 0;
        csbi->srWindow.Right = w.ws_col;
        csbi->srWindow.Bottom = w.ws_row;
        csbi->srWindow.Left = 0;
        return true;
    }

    void SetConsoleScreenBufferInfo(HANDLE, CONSOLE_SCREEN_BUFFER_INFO *) {
    }

    void FillConsoleOutputCharacter(HANDLE handle, TCHAR c, DWORD length, COORD coord, DWORD *) {
        SetConsoleCursorPosition(handle, coord);
        for (DWORD i = 0; i < length; i++)
            std::cout << c;
    }

    void FillConsoleOutputAttribute(HANDLE, WORD, DWORD, COORD, DWORD *) {
    }

    void SetConsoleTextAttribute(HANDLE, WORD) {
    }

    bool SetConsoleOutputCP(UINT) {
        return true;
    }

    bool SetConsoleCP(UINT) {
        return true;
    }

    void ShowWindow(HWND, int) {
    }

    HWND GetConsoleWindow() {
        HWND h;
        return h;
    }
#endif
