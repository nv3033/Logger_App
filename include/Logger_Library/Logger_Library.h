#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <mutex>
#include <sstream>

//Основной класс библиотеки
class Logger {
public:
    //Структура уровней важности
    enum class SeverityLevel {
        INFO,
        WARNING,
        ERROR
    };

    Logger(const std::string& filename, SeverityLevel default_level);
    ~Logger();

    //Основные методы (см. Logger_Library.cpp)
    void log(const std::string& message, SeverityLevel level);
    void setDefaultLevel(SeverityLevel level);
    SeverityLevel getDefaultlevel();
    std::string getFilename();
private:
    std::mutex log_mutex; //Мьютекс, принадлежащий текущему экземпляру класса
    std::ofstream log_file; //файл для вывода
    SeverityLevel default_level; //стандартный уровень важности

    std::string getCurrentTime();  //текущее время
    std::string filename; //имя файла для записи сообщений
};

#endif 