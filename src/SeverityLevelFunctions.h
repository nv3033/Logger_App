#pragma once
#include <map>
#include <iostream>
#include <string>

#include <Logger_Library.h>

//ХЕДЕР ДЛЯ УДОБНОГО ВООДА УРОВНЕЙ ВАЖНОСТИ

//Метод, проверяющий корректность ввода
bool valid_for_convertion(std::string sl_string){
	if (sl_string == "INFO" || sl_string == "WARNING" || sl_string == "ERROR") return true;
	return false;
}

//Конвертируем string в enum
Logger::SeverityLevel string_to_sl(std::string sl_string_input) {
	std::map <std::string, int> Severity_Level_Commands;
	Severity_Level_Commands[""] = 0;
	Severity_Level_Commands["INFO"] = 1;
	Severity_Level_Commands["WARNING"] = 2;
	Severity_Level_Commands["ERROR"] = 3;
	int switch_point = Severity_Level_Commands[sl_string_input];
	switch (switch_point)
	{
	case 0:
		return Logger::SeverityLevel::INFO;
	case 1:
		return Logger::SeverityLevel::INFO;
	case 2:
		return Logger::SeverityLevel::WARNING;
	case 3:
		return Logger::SeverityLevel::ERROR;
	default:
		break;
	}
}

//Конвертируем enum в string
std::string sl_to_string(Logger::SeverityLevel level) {
	if (level == Logger::SeverityLevel::WARNING) return "WARNING";
	else if (level == Logger::SeverityLevel::ERROR) return "ERROR";
	return "INFO";
}