#include "Program.hpp"

// Programa principal Administrador
void Program()
{
    uint16_t op{0};
    do
    {
        Console::Clear();
        Console::ForegroundColor(ConsoleColor::Green);
        std::puts("MENU PRINCIPAL");
        std::puts("\n****************************\n");
        std::puts("[1] Almacen");
        std::puts("[2] Compras");
        std::puts("[3] Ventas");
        std::puts("[4] Sistema");
        std::puts("[0] Salir");
        std::puts("\n***************************");
        op = ReadLine();
        while (op < 0 || op > 4)
        {
            ErrorMessage("invalid option");
            op = ReadLine();
        }
        Console::Clear();
        if (op == 0)
        {
            std::cout << "Fin del programa...\n";
            Console::Getch();
            return;
        }
        if (op == 1)
        {
            SystemMenu();
            continue;
        }
        if (op == 2)
        {
            std::cout << "opcion 2\n";
            Console::Getch();
            continue;
        }
        if (op == 3)
        {
            std::cout << "opcion 3\n";
            Console::Getch();
            continue;
        }
        if (op == 4)
        {
            std::cout << "opcion 4\n";
            Console::Getch();
            continue;
        }
    } while (true);
}

//*******************
// Opciones de Menu

// Menu System para configuracion del programa
void SystemMenu()
{
    uint16_t op;
    do
    {
        Console::Clear();
        Console::ForegroundColor(ConsoleColor::Bright_Green);
        std::puts("\tMENU SISTEMA");
        std::puts("-------------------------------");
        std::puts("<1> Registrar Personal\n");
        std::puts("<2> Actualizar Datos de la Empresa\n");
        std::puts("<3> Cambiar Contraseña\n");
        std::puts("<0> Regresar al menu principal\n");
        op = ReadLine();
        while (op < 0 || op > 3)
        {
            ErrorMessage("invalid option");
            op = ReadLine();
        }
        Console::Clear();
        if (op == 0)
            return;

        if (op == 1)
        {
            RegisterPersonal();
            continue;
        }
        if (op == 2)
        {
            std::cout << "opcion 2\n";
            Console::Getch();
            continue;
        }
        if (op == 3)
        {
            std::cout << "opcion 3\n";
            Console::Getch();
            continue;
        }
    } while (true);
}

void RegisterPersonal()
{
    uint16_t op;
    std::string name, lastName, direction, document;
    std::string password;
    Permissions permissions;
    UserKeys userKey;
    uint16_t day, month, year;
    std::puts("Registro De Personal");
    std::cout << "Nombre: ";
    std::getline(std::cin, name);
    std::cout << "Apellido: ";
    std::getline(std::cin, lastName);
    std::cout << "Document: ";
    std::getline(std::cin, document);
    std::cout << "Direccion: ";
    std::getline(std::cin, direction);
    Employees emp(name, lastName, direction, document);
    std::cout << "Fecha de nacimiento\n";
    std::cout << "Dia: ";
    std::cin >> day;
    std::cout << "Mes: ";
    std::cin >> month;
    std::cout << "Año: ";
    std::cin >> year;
    emp.SetDateOfBirth(day, month, year);
    if (SaveDataRegister<Employees>(emp, FILE_STAFF))
    {
        std::cout << "Registro Exitoso!\n";
        std::cout << "Su Codigo generado es: " << emp.GetCode() << std::endl;
        futil::Console::Sleep(1000);
        std::cout << "Este codigo le permitira tener acceso al sistema\n";
    }
    else
    {
        ErrorMessage("Error: No se pudo guardar el registro");
        ErrorMessage("\t.Posiblemente no tiene permisos en la PC");
        ErrorMessage("\t  Deshabilite su antivirus e intente de nuevo");
        ErrorMessage("\t.No tiene suficiente espacio para mas registros");
    }
    std::cout << "Tipo de Usuario( Admin -> (1)/ Local -> (2)): ";
    std::cin >> op;
    while (op != 1 && op != 2)
    {
        ErrorMessage("Opcion invalid!");
        std::cout << "Tipo de Usuario( Admin -> (1)/ Local -> (2)): ";
        std::cin >> op;
    }
    if (op == 1)
        permissions == ADMINISTRATOR;
    else
        permissions == USER_LOCAL;
    userKey.SetTypeAcount(permissions);
    userKey.SetCodeUser(emp.GetCode());
    std::cout << "Contraseña (6-8 caracteres): ";
    std::cin >> password;
    while (!userKey.SetPassword(password))
    {
        ErrorMessage("contraseña fuera de rango\n Ingresar una constraseña de 6 a 8 catacteres\n");
        std::cout << "Contraseña (6-8 caracteres): ";
        std::cin >> password;
    }
    if (SaveDataRegister<UserKeys>(userKey, FILE_USER))
        std::cout << "Registro Exitoso!\n";
    else
    {
        ErrorMessage("Error: No se pudo guardar el registro");
        ErrorMessage("\t.Posiblemente no tiene permisos en la PC");
        ErrorMessage("\t  Deshabilite su antivirus e intente de nuevo");
        ErrorMessage("\t.No tiene suficiente espacio para mas registros");
    }
    futil::Console::Sleep(2000);
}

// Menu Almacen, para manejo de los insumos y/o productos
void Warehouse()
{
    uint16_t op;
    do
    {
        Console::Clear();
        Console::ForegroundColor(ConsoleColor::Bright_Green);
        std::puts("\tMENU ALMACEN");
        std::puts("-------------------------------");
        std::puts("<1> Crear Nuevo Producto\n");
        std::puts("<2> Modificar Producto\n");
        std::puts("<3> Listar Productos\n");
        std::puts("<4> Realizar Ajuste\n");
        std::puts("<0> Regresar al menu principal\n");
        op = ReadLine();
        while (op < 0 || op > 4)
        {
            ErrorMessage("invalid option");
            op = ReadLine();
        }
        Console::Clear();
        if (op == 0)
            return;

        if (op == 1)
        {
            std::cout << "opcion 1\n";
            Console::Getch();
            continue;
        }
        if (op == 2)
        {
            std::cout << "opcion 2\n";
            Console::Getch();
            continue;
        }
        if (op == 3)
        {
            std::cout << "opcion 3\n";
            Console::Getch();
            continue;
        }
        if (op == 4)
        {
            std::cout << "opcion 4\n";
            Console::Getch();
            continue;
        }
    } while (true);
}

// Menu Ventas, sera para realizar la venta al publico
void sales()
{
    uint16_t op;
    do
    {
        Console::Clear();
        Console::ForegroundColor(ConsoleColor::Bright_Green);
        std::puts("\tMENU VENTAS");
        std::puts("-------------------------------");
        std::puts("(1) Registrar Venta\n");
        std::puts("(2) Listar detalle de Ventas\n"); // sera filtrado por fecha
        std::puts("(3) Listar Facturas\n");          // sera filtrado por fecha
        std::puts("(4) Imprimir Facturas\n");
        std::puts("(0) Regresar al menu principal\n");
        op = ReadLine();
        while (op < 0 || op > 4)
        {
            ErrorMessage("invalid option");
            op = ReadLine();
        }
        Console::Clear();
        if (op == 0)
            return;

        if (op == 1)
        {
            std::cout << "opcion 1\n";
            Console::Getch();
            continue;
        }
        if (op == 2)
        {
            std::cout << "opcion 2\n";
            Console::Getch();
            continue;
        }
        if (op == 3)
        {
            std::cout << "opcion 3\n";
            Console::Getch();
            continue;
        }
        if (op == 4)
        {
            std::cout << "opcion 4\n";
            Console::Getch();
            continue;
        }
    } while (true);
}

// Menu Compras, sera solo para administrador
void buy()
{
    uint16_t op;
    do
    {
        Console::Clear();
        Console::ForegroundColor(ConsoleColor::Bright_Green);
        std::puts("\tMENU COMPRAS");
        std::puts("-------------------------------");
        std::puts("<1> Registrar Compras\n");
        std::puts("<2> Buscar Compras\n");
        std::puts("<3> Listar Compras\n");
        std::puts("<0> Regresar al menu principal\n");
        op = ReadLine();
        while (op < 0 || op > 3)
        {
            ErrorMessage("invalid option");
            op = ReadLine();
        }
        Console::Clear();
        if (op == 0)
            return;

        if (op == 1)
        {
            std::cout << "opcion 1\n";
            Console::Getch();
            continue;
        }
        if (op == 2)
        {
            std::cout << "opcion 2\n";
            Console::Getch();
            continue;
        }
        if (op == 3)
        {
            std::cout << "opcion 3\n";
            Console::Getch();
            continue;
        }
    } while (true);
}

//***************
// funciones

// Lee la entra y devuelve un tipo short
uint16_t ReadLine()
{
    uint16_t op;
    std::string opTmp;
    while (true)
    {
        try
        {
            Console::ForegroundColor(ConsoleColor::Green);
            std::cout << "? ";
            std::cin >> opTmp;
            Console::CleanBuffer();
            op = std::stoi(opTmp);
            break;
        }
        catch (const std::exception &e)
        {
            ErrorMessage("invalid option");
        } // Mensaje de error cuando por opcion invalidad
    }
    return op;
} // fin de Read Option

// Funcion mensaje de error
void ErrorMessage(const char *text)
{
    Console::ForegroundColor(ConsoleColor::Red);
    std::cerr << text << '\n';
    Console::ResetColor();
}

bool ExistUser(UserKeys _uKey)
{
    UserKeys u;
    std::ifstream inputFile(FILE_USER, std::ios::in);
    if (inputFile.fail())
        return false;
    inputFile.read(reinterpret_cast<char *>(&u), sizeof(UserKeys));
    while (!inputFile.eof())
    {
        if (u.GetPassword() == _uKey.GetPassword() && u.GetCodeUser() == _uKey.GetCodeUser())
            return true;
        inputFile.read(reinterpret_cast<char *>(&u), sizeof(UserKeys));
    }
    return false;
}

template <class T>
bool SaveDataRegister(T t, const char *text)
{
    std::ofstream outputFile(text, std::ios::out | std::ios::app);
    if (outputFile.fail())
        return false;
    outputFile.write(reinterpret_cast<char *>(&t), sizeof(T));
    outputFile.close();
    return true;
}