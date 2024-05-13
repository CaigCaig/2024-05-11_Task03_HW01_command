#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogConsole : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "LogConsole: " << message << "\n";
    }
};

class LogFile : public LogCommand {
public :
    LogFile(std::string f) { filepath = f; }

    void print(const std::string& message) override {
        std::ofstream fout{ this->filepath, std::ios::app };
        if (fout.is_open())
        {
            fout << "LogFile: " << message << std::endl;
        }
        fout.close();
    }
private:
    std::string filepath;
};

void print(LogCommand& cmd) {
    cmd.print("Hello, world!");
}

int main()
{
    LogConsole log_console;
    LogFile log_file("log.txt");
    print(log_console);
    print(log_file);

    system("pause");
}

/*

Задание 1. Паттерн «Команда»
Пишем команды для системы логирования.

В задании нужно реализовать наследников класса:

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};
таким образом, чтобы один наследник печатал сообщение message в консоль, а другой умел печатать сообщение в файл, по указанному пути.

Далее нужно реализовать функцию: void print(LogCommand&);, которая будет выполнять команды.

*/