#include <iostream>

int main()
{
    std::cout << "int: " << sizeof(int) << std::endl
              << "short int: " << sizeof(short int) << std::endl
              << "long int: " << sizeof(long int) << std::endl
              << "float: " << sizeof(float) << std::endl
              << "double: " << sizeof(double) << std::endl
              << "long double: " << sizeof(long double) << std::endl
              << "char: " << sizeof(char) << std::endl
              << "bool: " << sizeof(bool) << std::endl;

    int integer = 12345678; // 0 000 0000 1011 1100 0110 0001 0100 1110

    std::cout << "12345678: ";
    unsigned int mask = 1U << 31;
    for (int i = 0; i < 32; i++)
    {
        std::cout << ((integer & mask) ? "1" : "0");

        if (i == 0)
        {
            std::cout << " ";
        }

        if ((i + 1) % 4 == 0)
        {
            std::cout << " ";
        }

        mask >>= 1;
    }

    //float
    mask = 1U << 31;

    std::cout << std::endl
              << "float 3.14: ";

    union
    {
        float one;
        int two;
    } hack;

    hack.one = 3.14;

    for (int i = 0; i < 32; i++)
    {
        std::cout << ((hack.two & mask) ? "1" : "0");

        if (i == 0 || i == 8)
        {
            std::cout << " ";
        }

        mask >>= 1;
    }

    //double
    std::cout << std::endl
              << "double 3.14: ";

    union
    {
        double one;
        int two[2];
    } double_hack;

    double_hack.one = -1234.5678;

    mask = 1U << 31;

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