# Описание приложения

Это приложение предназначено для записи сообщений в файл с поддержкой трех уровней важности: INFO, WARNING и ERROR. Пользователь может указать имя файла, в который будут записываться сообщения, и выбрать уровень важности по умолчанию. 

## Установка

1. Склонируйте репозиторий.
2. Убедитесь, что у вас установлен компилятор C++ (например, g++) и MakeFile.
3. Скомпилируйте приложение, используя команду:
   
   make -f makefile.txt
   

## Использование

1. Запустите приложение командой:
   
   ./Logger_Console_App
   

2. При старте приложение запросит у вас:

   - Имя файла, в который будут записываться сообщения.
   - Уровень важности по умолчанию (INFO, WARNING или ERROR).

### Доступные команды

После инициализации, вы можете вводить следующие команды:

- help: выводит информацию о доступных командах.

- info: выводит текущее имя файла и уровень важности по умолчанию.

- log: позволяет ввести текст сообщения и уровень его важности. Пример ввода:
  
  log
  Enter message: Это обычное сообщение
  Enter severity level:
  (invalid code will set default value) WARNING
  
  Если введён некорректный уровень важности, будет использован уровень по умолчанию.

- exit: завершает работу приложения.

## Пример работы приложения

Enter file name: logs.txt
Enter default severity level code:
(INFO, WARNING or ERROR): INFO
Enter command (or type [help]):

> help
Команды:[log] - log a message
	[info] - get app setup
	[exit] - exit app

> info
File name: logs.txt
Default severity level: INFO

> log
Enter message: Это важное сообщение
Enter severity level:
(invalid code will set default value) ERROR
