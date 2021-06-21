#pragma once

#include <iostream>
#include <thread>

#if defined(_WIN32)
#include <windows.h>
#include <conio.h>
#else
#include <termios.h>	// for getch() and kbhit()
#include <unistd.h>		// for getch(), kbhit() and (u)sleep()
#include <sys/ioctl.h>	// for getkey()
#include <sys/types.h>	// for kbhit()
#include <sys/time.h>	// for kbhit()
#include <sys/socket.h> // para evitar error en windows con cygwin
#endif

/**
* Console Virtual Terminal Sequences
*/

namespace ftr
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
		Bright_Red,
		Bright_Green,
		Bright_Yellow,
		Bright_Blue,
		Bright_Magenta,
		Bright_Cyan,
		Bright_White
	};

	enum class ConsoleKey
	{

		Tab = 9,		 //     The TAB key.
		Enter = 10,		 //     The ENTER key.
		Escape = 27,	 //     The ESC (ESCAPE) key.
		Spacebar = 32,	 //     The SPACEBAR key.
		LeftArrow = 37,	 //     The LEFT ARROW key.
		UpArrow = 38,	 //     The UP ARROW key.
		RightArrow = 39, //     The RIGHT ARROW key.
		DownArrow = 40,	 //     The DOWN ARROW key.
		Help = 47,		 //     The HELP key.
		D0 = 48,		 //     The 0 key.
		D1 = 49,		 //     The 1 key.
		D2 = 50,		 //     The 2 key.
		D3 = 51,		 //     The 3 key.
		D4 = 52,		 //     The 4 key.
		D5 = 53,		 //     The 5 key.
		D6 = 54,		 //     The 6 key.
		D7 = 55,		 //     The 7 key.
		D8 = 56,		 //     The 8 key.
		D9 = 57,		 //     The 9 key.
		A = 65,			 //     The A key.
		B = 66,			 //     The B key.
		C = 67,			 //     The C key.
		D = 68,			 //     The D key.
		E = 69,			 //     The E key.
		F = 70,			 //     The F key.
		G = 71,			 //     The G key.
		H = 72,			 //     The H key.
		I = 73,			 //     The I key.
		J = 74,			 //     The J key.
		K = 75,			 //     The K key.
		L = 76,			 //     The L key.
		M = 77,			 //     The M key.
		N = 78,			 //     The N key.
		O = 79,			 //     The O key.
		P = 80,			 //     The P key.
		Q = 81,			 //     The Q key.
		R = 82,			 //     The R key.
		S = 83,			 //     The S key.
		T = 84,			 //     The T key.
		U = 85,			 //     The U key.
		V = 86,			 //     The V key.
		W = 87,			 //     The W key.
		X = 88,			 //     The X key.
		Y = 89,			 //     The Y key.
		Z = 90,			 //     The Z key.
		a = 97,			 //     The b key.
		b = 98,			 //     The b key.
		c = 99,			 //     The c key.
		d = 100,		 //     The d key.
		e = 101,		 //     The e key.
		f = 102,		 //     The f key.
		g = 103,		 //     The g key.
		h = 104,		 //     The h key.
		i = 105,		 //     The i key.
		j = 106,		 //     The j key.
		k = 107,		 //     The k key.
		l = 108,		 //     The l key.
		m = 109,		 //     The m key.
		n = 110,		 //     The n key.
		o = 111,		 //     The o key.
		p = 112,		 //     The p key.
		q = 113,		 //     The q key.
		r = 114,		 //     The r key.
		s = 115,		 //     The s key.
		t = 116,		 //     The t key.
		u = 117,		 //     The u key.
		v = 118,		 //     The v key.
		w = 119,		 //     The w key.
		x = 120,		 //     The x key.
		y = 121,		 //     The y key.
		z = 122,		 //     The z key.
		Backspace = 127, //     The BACKSPACE key.
	};

	/**
	 * Class ConsoleKeyInfo.
	 *
	 */
	struct ConsoleKeyInfo
	{
		ConsoleKey key;
		char keyChar{ ' ' };
		ConsoleKeyInfo() : key(ConsoleKey::A) {};
		ConsoleKeyInfo(ConsoleKey _key) : key(_key) {};
		~ConsoleKeyInfo() {};
		//std::ostream& operator<<(std::ostream& os, const ConsoleKeyInfo& c);
	};

	static std::ostream& operator<<(std::ostream& os, const ConsoleKeyInfo& c)
	{
		os << static_cast<int>(c.key);
		os << static_cast<char>(c.keyChar); // recordar que hay teclas no imprimibles
		return os;
	}

	/**
	 * Class Console.
	 *
	 */
	class Console
	{
		//************************************************************************************
		// Privados

	private:
		// Function GetForegroundColor
		// Obtiene el color de primer plano
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

		// Function GetBackgroundColor
		// Obtiene el color de fondo
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

		// Function SetCursorVisibility
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

		// Function SaveDefaulColo
		// Permite guadar el color por defecto para luego resetear
		static int saveDefaultColor(void)
		{
#if defined(_WIN32)
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

		// Function: getch
		// Lee la tecla pulsada sin esperar la tecla enter
		static int getch(void)
		{
#if defined(_WIN32)
			return _getch();
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

		/// Function: kbhit
		/// Determines if keyboard has been hit.
		/// Windows has this in conio.h
		static int kbhit(void)
		{
#if defined(_WIN32)
			return _kbhit();

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
#if !defined(_WIN32)
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
		//*************************************************************************************
		// publicos

	public:
		// Function Sleep
		// Duerme un tiempo en milisegundos el programa
		static void Sleep(int32_t ms)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		}

		// Function ReadKey
		// Aun falta implementar mas opciones del teclado
		// Uso solo para C++11
		static ConsoleKeyInfo ReadKey()
		{
			int cnt = kbhit();
			int k = getch();
			switch (k)
			{
			case 9:
				return ConsoleKey::Tab;
			case 10:
				return ConsoleKey::Enter;
			case 27:
#if defined(_WIN32)
				return ConsoleKey::Escape;
#else
				if (kbhit())
				{
					k = getch();
					switch (k = getch())
					{
					case 65:
						return ConsoleKey::UpArrow;
					case 66:
						return ConsoleKey::DownArrow;
					case 67:
						return ConsoleKey::RightArrow;
					case 68:
						return ConsoleKey::LeftArrow;
					}
				}
				else
					return ConsoleKey::Escape;
#endif
			case 32:
				return ConsoleKey::Spacebar;
			case 47:
				return ConsoleKey::Help;
			case 48:
				return ConsoleKey::D0;
			case 49:
				return ConsoleKey::D1;
			case 50:
				return ConsoleKey::D2;
			case 51:
				return ConsoleKey::D3;
			case 52:
				return ConsoleKey::D4;
			case 53:
				return ConsoleKey::D5;
			case 54:
				return ConsoleKey::D6;
			case 55:
				return ConsoleKey::D7;
			case 56:
				return ConsoleKey::D8;
			case 57:
				return ConsoleKey::D9;
			case 65:
				return ConsoleKey::A;
			case 66:
				return ConsoleKey::B;
			case 67:
				return ConsoleKey::C;
			case 68:
				return ConsoleKey::D;
			case 69:
				return ConsoleKey::E;
			case 70:
				return ConsoleKey::F;
			case 71:
				return ConsoleKey::G;
			case 72:
				return ConsoleKey::H;
			case 73:
				return ConsoleKey::I;
			case 74:
				return ConsoleKey::J;
			case 75:
				return ConsoleKey::K;
			case 76:
				return ConsoleKey::L;
			case 77:
				return ConsoleKey::M;
			case 78:
				return ConsoleKey::N;
			case 79:
				return ConsoleKey::O;
			case 80:
				return ConsoleKey::P;
			case 81:
				return ConsoleKey::Q;
			case 82:
				return ConsoleKey::R;
			case 83:
				return ConsoleKey::S;
			case 84:
				return ConsoleKey::T;
			case 85:
				return ConsoleKey::U;
			case 86:
				return ConsoleKey::V;
			case 87:
				return ConsoleKey::W;
			case 88:
				return ConsoleKey::X;
			case 89:
				return ConsoleKey::Y;
			case 90:
				return ConsoleKey::Z;
			case 97:
				return ConsoleKey::a;
			case 98:
				return ConsoleKey::b;
			case 99:
				return ConsoleKey::c;
			case 100:
				return ConsoleKey::d;
			case 101:
				return ConsoleKey::e;
			case 102:
				return ConsoleKey::f;
			case 103:
				return ConsoleKey::g;
			case 104:
				return ConsoleKey::h;
			case 105:
				return ConsoleKey::i;
			case 106:
				return ConsoleKey::j;
			case 107:
				return ConsoleKey::k;
			case 108:
				return ConsoleKey::l;
			case 109:
				return ConsoleKey::m;
			case 110:
				return ConsoleKey::n;
			case 111:
				return ConsoleKey::o;
			case 112:
				return ConsoleKey::p;
			case 113:
				return ConsoleKey::q;
			case 114:
				return ConsoleKey::r;
			case 115:
				return ConsoleKey::s;
			case 116:
				return ConsoleKey::t;
			case 117:
				return ConsoleKey::u;
			case 118:
				return ConsoleKey::v;
			case 119:
				return ConsoleKey::w;
			case 120:
				return ConsoleKey::x;
			case 121:
				return ConsoleKey::y;
			case 122:
				return ConsoleKey::z;
			case 127:
				return ConsoleKey::Backspace;
#if defined(_WIN32)
			case 224:
				switch (k = getch())
				{
				case 72:
					return ConsoleKey::UpArrow;
				case 80:
					return ConsoleKey::DownArrow;
				case 77:
					return ConsoleKey::RightArrow;
				case 75:
					return ConsoleKey::LeftArrow;
				}

#endif
			}
			return ConsoleKey::F;
		}

		// Function CleanBuffer
		// Limpiar los datos de entrada hasta un salto de linea
		// su implementacion es solo para casos particulares
		static void CleanBuffer()
		{
			int c;
			while ((c = getchar()) != '\n' && c != EOF)
				;
		}

		// Function Hidecursor
		// Ocultaro la visibilidad del cursor
		inline static void Hidecursor(void) { SetCursorVisibility(0); }

		// Function Showcursos
		// Mostrar la visibilidad del cursor
		inline static void Showcursor(void) { SetCursorVisibility(1); }

		// Function ResetColor
		//Resetea el Color por defecto
		inline static void ResetColor()
		{
#if defined(_WIN32)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)7);// saveDefaultColor()); Corregir este ERROR!!!
#else
			PRINT_CONSOLE(CVTS_ATTRIBUTE_RESET);
#endif
		}

		// Function ForegroundColor
		// Establece color de primer plano
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

		// Function BackgroundColor
		// Establece el color de fondo
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

		// Function Clear
		// Limpia la pantalla y coloca en la posicion 0,0 el cursor
		static void Clear()
		{
#if defined(_WIN32)
			const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			const COORD coordScreen = { 0, 0 };
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

		// Function SetCursorPosition
		//  Establece la posicion del cursor en la consola
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

		// Function Title
		// Establecer el titulo de la consola
		static void Title(std::string title)
		{
#if defined(_WIN32)
			const char* true_title = title.c_str();
			SetConsoleTitleA(true_title);
#else
			PRINT_CONSOLE(CVTS_CONSOLE_TITLE_PRE + title + CVTS_CONSOLE_TITLE_POST)
#endif
		}

	}; // fin de la clase
} // namespace futil
