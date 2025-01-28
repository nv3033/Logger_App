#include "Logger_Library.h"

//Конструктор
Logger::Logger(const std::string& filename, SeverityLevel default_level)
    : default_level(default_level), filename(filename) {
    log_file.open(filename, std::ios::app);
}

//Деструктор
Logger::~Logger() {
    if (log_file.is_open()) {
        log_file.close();
    }
}

//Метод записи сообщения в файл
void Logger::log(const std::string& message, SeverityLevel level) {
    if (static_cast<int>(level) >= static_cast<int>(default_level)) {
        log_file << getCurrentTime()
            << " [" << static_cast<int>(level) << "] "
            << message << std::endl;
    }
}

//Метод для изменения стандартного уровня важности
void Logger::setDefaultLevel(SeverityLevel level) {
    default_level = level;
}

//Метод для получения текущего времени
std::string Logger::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

//Методы для доступа к приватным переменным
Logger::SeverityLevel Logger::getDefaultlevel() {
    return default_level;
}

std::string Logger::getFilename() {
    return filename;
}