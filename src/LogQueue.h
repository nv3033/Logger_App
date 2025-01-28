#include <string>
#include <mutex>
#include <queue>
#include <atomic>
#include <condition_variable>

#include <Logger_Library.h>

//ХЕДЕР ДЛЯ КЛАССА ОЧЕРЕДИ

class LogQueue {
public:
    //Метод для добавления данных в очередь
    void push(const std::string& message, Logger::SeverityLevel level) {
        std::lock_guard<std::mutex> lock(mutex);//Захватываем мьютекс для безопасного доступа
        queue.emplace(message, level);//Добавляем сообщение и уровень в очередь
        cv.notify_one();  //Уведомляем один из ожидающих потоков
    }
    //Метод для обработки очереди и логирования сообщений
    void process(Logger& logger) {
        while (running || !queue.empty()) {
            std::unique_lock<std::mutex> lock(mutex);//Захватываем мьютекс
            cv.wait(lock, [&] { return !queue.empty() || !running; }); // жидание наличия сообщений

            //Обработка всех сообщений в очереди
            while (!queue.empty()) {
                auto [message, level] = queue.front();
                queue.pop();
                logger.log(message, level);  // Логируем сообщение
            }
        }
    }

    //Метод для остановки обработки очереди
    void stop() {
        running = false;
        cv.notify_all();  // Уведомляем все ожидающие потоки
    }

private:
    std::queue<std::pair<std::string, Logger::SeverityLevel>> queue;
    std::mutex mutex;
    std::condition_variable cv;
    std::atomic<bool> running{ true };
};

