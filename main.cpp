#include <iostream>

int main() {
    std::cout << "Размеры различных типов данных: " << std::endl;
    std::cout << "int: " << sizeof(int) << std::endl
              << "short int: " << sizeof(short int) << std::endl
              << "long int: " << sizeof(long int) << std::endl
              << "float: " << sizeof(float) << std::endl
              << "double: " << sizeof(double) << std::endl
              << "long double: " << sizeof(long double) << std::endl
              << "char: " << sizeof(char) << std::endl
              << "bool: " << sizeof(bool) << std::endl;

    std::cout << "Введите целое число: ";
    int integer;
    std::cin >> integer;
    std::cout << integer << ": ";
    unsigned int mask = 1U << 31;
    for (int i = 0; i < 32; i++) {
        std::cout << ((integer & mask) ? "1" : "0");
        if (i == 0 || (i + 1) % 4 == 0) {
            std::cout << " ";
        }
        mask >>= 1;
    }
    std::cout << std::endl;
    mask = 1U << 31;

    union {
        float one;
        unsigned int two;
    } hack;

    std::cout << "Введите вещественное число: ";
    std::cin >> hack.one;
    std::cout << hack.one << ": ";

    for (int i = 0; i < 32; i++) {
        std::cout << ((hack.two & mask) ? "1" : "0");
        if (i == 0 || i == 8) {
            std::cout << " ";
        }
        mask >>= 1;
    }
    mask = 1U << 31;
    std::cout << std::endl;

    union {
        double one;
        unsigned int two[2];
    } double_hack;

    std::cout << "Введите вещественное число двойной точности: ";
    std::cin >> double_hack.one;
    std::cout << double_hack.one << ": ";
    for (int i = 0; i < 64; i++) {
        int index = i < 64 / 2;
        std::cout << ((double_hack.two[index] & mask) ? "1" : "0");
        if (i == 0 || i == 11) {
            std::cout << " ";
        }
        mask >>= 1;
        if (mask == 0) {
            mask = 1U << 31;
        }
    }
    mask = 1U << 31;

    std::cout << std::endl;
    std::cout << "------" << std::endl;
    std::cout << "ИДЗ №1: возможность изменять произвольные биты на 1 или 0 по указанию пользователя." << std::endl;
    std::cout << "------" << std::endl;

    char choice;
    do {
        std::cout << "Введите номер бита: ";
        int number, value;
        std::cin >> number;
        while (true) {
            std::cout << "Введите значение бита (0 или 1): ";
            std::cin >> value;
            if (value != 0 && value != 1) {
                std::cout << "Ошибка: неверное значение бита." << std::endl;
                continue;
            }
            break;
        }

        if (number >= 64) {
            std::cout << "Слишком большой номер бита. Нет изменений.";
            return 0;
        }

        if (number >= 32) {
            std::cout << "Номер бита выходит за размер в 4 байта. Изменяется только double." << std::endl;
            if (value) {
                double_hack.two[1] |= 1U << (number % 32);
            } else {
                double_hack.two[1] &= ~(1U << (number % 32));
            }
            std::cout << "Новое значение double: " << std::endl;

            std::cout << double_hack.one << ": ";
            for (int i = 0; i < 64; i++) {
                int index = i < 64 / 2;
                std::cout << ((double_hack.two[index] & mask) ? "1" : "0");
                if (i == 0 || i == 11) {
                    std::cout << " ";
                }
                mask >>= 1;
                if (mask == 0) {
                    mask = 1U << 31;
                }
            }

            return 0;
        }


        std::cout << "Бит №" << number << " устанавливается в значение " << value << " для всех типов данных."
                  << std::endl;
        if (value) {
            integer |= 1 << (number % 32);
            hack.two |= 1U << (number % 32);
            double_hack.two[0] |= 1U << (number % 32);
        } else {
            integer &= ~(1 << (number % 32));
            hack.two &= ~(1U << (number % 32));
            double_hack.two[0] &= ~(1U << (number % 32));
        }

        std::cout << std::endl;
        std::cout << "Новое значение int: " << std::endl;
        std::cout << integer << ": ";
        for (int i = 0; i < 32; i++) {
            std::cout << ((integer & mask) ? "1" : "0");
            if (i == 0 || (i + 1) % 4 == 0) {
                std::cout << " ";
            }
            mask >>= 1;
        }
        mask = 1U << 31;

        std::cout << std::endl;
        std::cout << "Новое значение float: " << std::endl;
        std::cout << hack.one << ": ";
        for (int i = 0; i < 32; i++) {
            std::cout << ((hack.two & mask) ? "1" : "0");
            if (i == 0 || i == 8) {
                std::cout << " ";
            }
            mask >>= 1;
        }
        mask = 1U << 31;

        std::cout << std::endl;
        std::cout << "Новое значение double: " << std::endl;
        std::cout << double_hack.one << ": ";
        for (int i = 0; i < 64; i++) {
            int index = i < 64 / 2;
            std::cout << ((double_hack.two[index] & mask) ? "1" : "0");
            if (i == 0 || i == 11) {
                std::cout << " ";
            }
            mask >>= 1;
            if (mask == 0) {
                mask = 1U << 31;
            }
        }
        mask = 1U << 31;

        std::cout << std::endl;
        std::cout << "Изменить ещё один бит? (y/n): ";
        std::cin >> choice;

    } while (choice == 'y');

}