#include <string>
#include <map>

#include <Logger_Library.h>
#include "Logger_Console_App.h"
#include "SeverityLevelFunctions.h"

// Главная функция консоли
int Console(std::string &command, Logger *Current_Logger)
{
    // Ввод команды
    std::cout << "Enter command (or type [help]):\n";
    std::cin >> command;

    // Запускаем введеную команду (обращаясь к Logger_Console_App.h)
    std::map<std::string, int> existing_commands;
    existing_commands[""] = 0;
    existing_commands["help"] = 1;
    existing_commands["log"] = 2;
    existing_commands["info"] = 3;
    existing_commands["exit"] = 4;
    int switch_point = existing_commands[command];
    switch (switch_point)
    {
    case 0:
        return Console(command, Current_Logger);
    case 1:
        Help();
        return Console(command, Current_Logger);
    case 2:
        Log(Current_Logger);
        return Console(command, Current_Logger);
    case 3:
        Info(Current_Logger);
        return Console(command, Current_Logger);
    case 4:
        return 0;
    default:
        break;
    }
}

// Инициализируем программу
int main()
{
    // Ввод начальных данных
    std::string filename;
    std::string sl_string_input;

    std::cout << "Enter file name:\n";
    std::cin >> filename;
    std::cout << "Enter default severity level code:\n(INFO, WARNING or ERROR)\n";
    std::cin >> sl_string_input;

    // Проверяем на корректный ввод и запускаем основную консоль
    if (valid_for_convertion(sl_string_input))
    {
        Logger Current_Logger(filename, string_to_sl(sl_string_input));
        std::string command;
        return Console(command, &Current_Logger);
    }
    else
    {
        std::cout << "Invalid severity level code!\n";
        return -1;
    }
}