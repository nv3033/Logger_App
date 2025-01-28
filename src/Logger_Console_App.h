#include <map>
#include <iostream>
#include <thread>

#include <Logger_Library.h>
#include "LogQueue.h"
#include "SeverityLevelFunctions.h"

// ХЕДЕР С КОМАНДАМИ ДЛЯ КОНСОЛИ

// Команда хелп
void Help()
{
	std::cout << "[log] - log a message\n";
	std::cout << "[info] - get app setup\n";
	std::cout << "[exit] - exit app\n";
}

// Команда для получени информации об инициализации программы
void Info(Logger *Current_Logger)
{
	// Имя файла, в который будут записываться логи
	std::cout << "File name: " << Current_Logger->getFilename() << "\n";
	// Уровень важности по умолчанию
	std::cout << "Default severity level: " << sl_to_string(Current_Logger->getDefaultlevel()) << "\n";
}

// Команда для записи лога
void Log(Logger *Current_Logger)
{
	// Создаем экземпляр очереди
	LogQueue log_queue;
	// Запускаем поток для обработки логов
	std::thread log_thread(&LogQueue::process, &log_queue, std::ref(*Current_Logger));

	// Вводим данные
	std::string message;
	std::string level;
	std::cout << "Enter message: \n";
	std::cin >> message;
	std::cout << "Enter severity level:\n(invalid code will set default value)\n";
	std::cin >> level;

	// Проверяем корректность данных и добавляем их в очередь
	if (valid_for_convertion(level))
		log_queue.push(message, string_to_sl(level));
	else
		log_queue.push(message, Current_Logger->getDefaultlevel()); // Логируем пользовательский ввод

	// Остановка и завершение потока
	log_queue.stop();
	log_thread.join();
}