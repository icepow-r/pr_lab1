#include <iostream>

int main()
{
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
    std::cout << "Двоичное представление целого числа " << integer << ": ";
    unsigned int mask = 1U << 31;
    for (int i = 0; i < 32; i++)
    {
        std::cout << ((integer & mask) ? "1" : "0");
        if (i == 0 || (i + 1) % 4 == 0)
        {
            std::cout << " ";
        }
        mask >>= 1;
    }
    std::cout << std::endl;
    mask = 1U << 31;

    union
    {
        float one;
        int two;
    } hack;

    std::cout << "Введите вещественное число: ";
    std::cin >> hack.one;
    std::cout << "Двоичное представление вещественного числа " << hack.one << ": ";

    for (int i = 0; i < 32; i++)
    {
        std::cout << ((hack.two & mask) ? "1" : "0");
        if (i == 0 || i == 8)
        {
            std::cout << " ";
        }
        mask >>= 1;
    }
    mask = 1U << 31;
    std::cout << std::endl;

    union
    {
        double one;
        int two[2];
    } double_hack;

    std::cout << "Введите вещественное число двойной точности: ";
    std::cin >> double_hack.one;
    std::cout << "Двоичное представление вещественного числа двойной точности " << double_hack.one << ": ";
    for (int i = 0; i < 64; i++)
    {
        int index = i < 64 / 2;
        std::cout << ((double_hack.two[index] & mask) ? "1" : "0");
        if (i == 0 || i == 11)
        {
            std::cout << " ";
        }
        mask >>= 1;
        if (mask == 0)
        {
            mask = 1U << 31;
        }
    }
}