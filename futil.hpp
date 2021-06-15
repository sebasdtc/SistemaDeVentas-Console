#pragma once

#include <iostream>
#include <thread>

#if defined(_WIN32)
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>    // for getch() and kbhit()
#include <unistd.h>     // for getch(), kbhit() and (u)sleep()
#include <sys/ioctl.h>  // for getkey()
#include <sys/types.h>  // for kbhit()
#include <sys/time.h>   // for kbhit()
#include <sys/socket.h> // para evitar error en windows con cygwin
#endif

/**
* Console Virtual Terminal Sequences
*/

namespace futil
{

#define PRINT_CONSOLE(str) std::cout << str;

    /**
     * Console Virtual Terminal Sequences
    *	Valido solo para linux o windows terminal
     */
    const std::string CVTS_CLS = "\033[2J\033[3J";
    const std::string CVTS_CONSOLE_TITLE_PRE = "\033]0;";
    const std::string CVTS_CONSOLE_TITLE_POST = "\007";
    const std::string CVTS_ATTRIBUTE_RESET = "\033[0m";
    const std::string CVTS_CURSOR_HIDE = "\033[?25l";
    const std::string CVTS_CURSOR_SHOW = "\033[?25h";
    const std::string CVTS_CURSOR_HOME = "\033[1;1H";
    const std::string CVTS_FONT_BOLD = "\033[1m";
    const std::string CVTS_FONT_FAINT = "\033[2m";
    const std::string CVTS_FONT_ITALIC = "\033[3m";
    const std::string CVTS_FONT_UNDERLINE = "\033[4m";
    const std::string CVTS_RESET_BOLD = "\033[22m";
    const std::string CVTS_RESET_ITALIC = "\033[23m";
    const std::string CVTS_RESET_UNDERLINE = "\033[24m";
    const std::string CVTS_BLACK = "\033[30m";
    const std::string CVTS_RED = "\033[31m";
    const std::string CVTS_GREEN = "\033[32m";
    const std::string CVTS_YELLOW = "\033[33m";
    const std::string CVTS_BLUE = "\033[34m";
    const std::string CVTS_MAGENTA = "\033[35m";
    const std::string CVTS_CYAN = "\033[36m";
    const std::string CVTS_WHITE = "\033[37m";
    const std::string CVTS_BRIGHT_BLACK = "\033[90m";
    const std::string CVTS_BRIGHT_RED = "\033[91m";
    const std::string CVTS_BRIGHT_GREEN = "\033[92m";
    const std::string CVTS_BRIGHT_YELLOW = "\033[93m";
    const std::string CVTS_BRIGHT_BLUE = "\033[94m";
    const std::string CVTS_BRIGHT_MAGENTA = "\033[95m";
    const std::string CVTS_BRIGHT_CYAN = "\033[96m";
    const std::string CVTS_BRIGHT_WHITE = "\033[97m";
    const std::string CVTS_BACKGROUND_BLACK = "\033[40m";
    const std::string CVTS_BACKGROUND_RED = "\033[41m";
    const std::string CVTS_BACKGROUND_GREEN = "\033[42m";
    const std::string CVTS_BACKGROUND_YELLOW = "\033[43m";
    const std::string CVTS_BACKGROUND_BLUE = "\033[44m";
    const std::string CVTS_BACKGROUND_MAGENTA = "\033[45m";
    const std::string CVTS_BACKGROUND_CYAN = "\033[46m";
    const std::string CVTS_BACKGROUND_WHITE = "\033[47m";
    const std::string CVTS_BACKGROUND_BRIGHT_BLACK = "\033[100m";
    const std::string CVTS_BACKGROUND_BRIGHT_RED = "\033[101m";
    const std::string CVTS_BACKGROUND_BRIGHT_GREEN = "\033[102m";
    const std::string CVTS_BACKGROUND_BRIGHT_YELLOW = "\033[103m";
    const std::string CVTS_BACKGROUND_BRIGHT_BLUE = "\033[104m";
    const std::string CVTS_BACKGROUND_BRIGHT_MAGENTA = "\033[105m";
    const std::string CVTS_BACKGROUND_BRIGHT_CYAN = "\033[106m";
    const std::string CVTS_BACKGROUND_BRIGHT_WHITE = "\033[107m";

    /**
    *  Selection Colors
    */
    enum class ConsoleColor
    {
        Black,
        Blue,
        Green,
        Cyan,
        Red,
        Magenta,
        Yellow,
        White,
        Bright_Black,
        Bright_Blue,
        Bright_Green,
        Bright_Cyan,
        Bright_Red,
        Bright_Magenta,
        Bright_Yellow,
        Bright_White
    };

    /**
     * Class Console.
     * 
     */
    class Console
    {
    private:
        static std::string GetForegroundColor(ConsoleColor color)
        {
            switch (color)
            {
            case ConsoleColor::Black:
                return CVTS_BLACK;
            case ConsoleColor::Blue:
                return CVTS_BLUE;
            case ConsoleColor::Green:
                return CVTS_GREEN;
            case ConsoleColor::Cyan:
                return CVTS_CYAN;
            case ConsoleColor::Red:
                return CVTS_RED;
            case ConsoleColor::Magenta:
                return CVTS_MAGENTA;
            case ConsoleColor::Yellow:
                return CVTS_YELLOW;
            case ConsoleColor::White:
                return CVTS_WHITE;
            case ConsoleColor::Bright_Black:
                return CVTS_BRIGHT_BLACK;
            case ConsoleColor::Bright_Red:
                return CVTS_BRIGHT_RED;
            case ConsoleColor::Bright_Green:
                return CVTS_BRIGHT_GREEN;
            case ConsoleColor::Bright_Yellow:
                return CVTS_BRIGHT_YELLOW;
            case ConsoleColor::Bright_Blue:
                return CVTS_BRIGHT_BLUE;
            case ConsoleColor::Bright_Magenta:
                return CVTS_BRIGHT_MAGENTA;
            case ConsoleColor::Bright_Cyan:
                return CVTS_BRIGHT_CYAN;
            case ConsoleColor::Bright_White:
                return CVTS_BRIGHT_WHITE;
            default:
                return "";
            }
        }
        static std::string GetBackgroundColor(ConsoleColor color)
        {
            switch (color)
            {
            case ConsoleColor::Black:
                return CVTS_BACKGROUND_BLACK;
            case ConsoleColor::Blue:
                return CVTS_BACKGROUND_BLUE;
            case ConsoleColor::Green:
                return CVTS_BACKGROUND_GREEN;
            case ConsoleColor::Cyan:
                return CVTS_BACKGROUND_CYAN;
            case ConsoleColor::Red:
                return CVTS_BACKGROUND_RED;
            case ConsoleColor::Magenta:
                return CVTS_BACKGROUND_MAGENTA;
            case ConsoleColor::Yellow:
                return CVTS_BACKGROUND_YELLOW;
            case ConsoleColor::White:
                return CVTS_BACKGROUND_WHITE;
            case ConsoleColor::Bright_Black:
                return CVTS_BACKGROUND_BRIGHT_BLACK;
            case ConsoleColor::Bright_Red:
                return CVTS_BACKGROUND_BRIGHT_RED;
            case ConsoleColor::Bright_Green:
                return CVTS_BACKGROUND_BRIGHT_GREEN;
            case ConsoleColor::Bright_Yellow:
                return CVTS_BACKGROUND_BRIGHT_YELLOW;
            case ConsoleColor::Bright_Blue:
                return CVTS_BACKGROUND_BRIGHT_BLUE;
            case ConsoleColor::Bright_Magenta:
                return CVTS_BACKGROUND_BRIGHT_MAGENTA;
            case ConsoleColor::Bright_Cyan:
                return CVTS_BACKGROUND_BRIGHT_CYAN;
            case ConsoleColor::Bright_White:
                return CVTS_BACKGROUND_BRIGHT_WHITE;
            default:
                return "";
            }
        }

        // visibilidad del cursor
        static void SetCursorVisibility(char visible)
        {
#if defined(_WIN32)
            HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO structCursorInfo;
            GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo); // Get current cursor size
            structCursorInfo.bVisible = (visible ? TRUE : FALSE);
            SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
#else
            PRINT_CONSOLE((visible ? CVTS_CURSOR_SHOW : CVTS_CURSOR_HIDE))
#endif
        }
        static int saveDefaultColor(void)
        {
#if defined(_WIN32) && !defined(RLUTIL_USE_ANSI)
            static char initialized = 0; // bool
            static WORD attributes;
            if (!initialized)
            {
                CONSOLE_SCREEN_BUFFER_INFO csbi;
                GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
                attributes = csbi.wAttributes;
                initialized = 1;
            }
            return (int)attributes;
#else
            return -1;
#endif
        }

    public:
        // Limpiar los datos de entrada
        static void CleanBuffer()
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        static void ShowErrorMessage(const char *str, ConsoleColor color)
        {
            Console::ForegroundColor(color);
            std::cerr << str << "\n";
            Console::ResetColor();
        }

        // Mostrar la visibilidad del cursor
        inline static void Hidecursor(void) { SetCursorVisibility(0); }

        // Ocultaro la visibilidad del cursor
        inline static void Showcursor(void) { SetCursorVisibility(1); }

        /// Function: getch
        static int Getch(void)
        {
#if defined(_WIN32)
            _getch();
#else
            setbuf(stdin, NULL);
            struct termios oldt, newt;
            int ch;
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            return ch;
#endif
        }

        //Reset Color
        inline static void ResetColor()
        {
#if defined(_WIN32)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)saveDefaultColor());
#else
            PRINT_CONSOLE(CVTS_ATTRIBUTE_RESET);
#endif
        }

        //Foreground Color
        //Establece color de primer plano
        static void ForegroundColor(ConsoleColor color)
        {
#if defined(_WIN32)
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)color); // Foreground colors take up the least significant byte
#else
            PRINT_CONSOLE(GetForegroundColor(color));
#endif
        }

        //Background Color
        //Establece el color de fondo
        static void BackgroundColor(ConsoleColor color)
        {
#if defined(_WIN32)
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)color) << 4)); // Background colors take up the second-least significant byte
#else
            PRINT_CONSOLE(GetBackgroundColor(color));
#endif
        }

        //Clear windows
        static void Clear()
        {
#if defined(_WIN32)
            const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            const COORD coordScreen = {0, 0};
            DWORD cCharsWritten;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            const DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
            FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
            SetConsoleCursorPosition(hConsole, coordScreen);
#else
            PRINT_CONSOLE(CVTS_CLS + CVTS_CURSOR_HOME);
#endif
        }

        //Set CursorPosition
        //Establece la posicion del cursor en la consola
        static void SetCursorPosition(int32_t Coord_X, int32_t Coord_Y)
        {
#if defined(_WIN32)
            COORD coord;
            // TODO: clamping/assert for x/y <= 0?
            coord.X = (SHORT)(Coord_X - 1);
            coord.Y = (SHORT)(Coord_Y - 1); // Windows uses 0-based coordinates
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
            PRINT_CONSOLE("\033[" << Coord_Y << ";" << Coord_X << "H");
#endif
        }

        // Establecer el titulo de la consola
        static void SetConsoleTitle(std::string title)
        {
#if defined(_WIN32)
            const char *true_title = title.c_str();
            SetConsoleTitleA(true_title);
#else
            PRINT_CONSOLE(CVTS_CONSOLE_TITLE_PRE + title + CVTS_CONSOLE_TITLE_POST)
#endif
        }

        static void Sleep(int32_t ms)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        }

        /// Function: kbhit
        /// Determines if keyboard has been hit.
        /// Windows has this in conio.h
        static int kbhit(void)
        {
#if defined(_WIN32)
            _kbhit();
#else
            static short first = 1;
            static struct termios newt;
            int bytes = 0;
            if (first)
            {
                setbuf(stdin, NULL);
                tcgetattr(STDIN_FILENO, &newt);
                newt.c_lflag &= ~(ICANON | ECHO);
                tcsetattr(STDIN_FILENO, TCSANOW, &newt);
                first = 0;
            }
            ioctl(STDIN_FILENO, FIONREAD, &bytes);
            return bytes > 0 ? 1 : 0;
#endif
        }

// lectura del teclado
#if defined(_WIN32)

#else
        static void keyboard(unsigned short st)
        {
            static struct termios oldt, newt;
            static short first = 1;
            if (first)
            {
                tcgetattr(STDIN_FILENO, &oldt);
                first = 0;
            }
            if (st)
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            else
            {
                newt = oldt;
                newt.c_lflag &= ~(ICANON | ECHO);
                tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            }
        }
#endif
    }; // fin de la clase
} // namespace futil