#include <iostream>

int main()
{
    int integer;
    short int short_integer;
    long int long_integer;
    float real;
    double double_real;
    long double long_double_real;
    char symbol;
    bool logic;

    std::cout << "int: " << sizeof(integer) << std::endl
              << "short int: " << sizeof(short_integer) << std::endl
              << "long int: " << sizeof(long_integer) << std::endl
              << "float: " << sizeof(real) << std::endl
              << "double: " << sizeof(double_real) << std::endl
              << "long double: " << sizeof(long_double_real) << std::endl
              << "char: " << sizeof(symbol) << std::endl
              << "bool: " << sizeof(logic) << std::endl;

    integer = 12345678; // 0 000 0000 1011 1100 0110 0001 0100 1110

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

    double_hack.one = 3.14;

    unsigned int double_mask[2] = { };
    double_mask[0] = 1U << 31;

    for (int i = 0; i < 64; i++)
    {
        int index = i < 64 / 2;
        std::cout << ((double_hack.two[index] & double_mask[!index]) ? "1" : "0");

        if (i == 0 || i == 8)
        {
            std::cout << " ";
        }

        double_mask[index] >>= 1;

        if (double_mask[index] == 0 && index != 1)
        {
            double_mask[index + 1] = 1U << 31;
        }
    }

    //long double
    std::cout << std::endl
              << "long double 3.14: ";

    union
    {
        long double one;
        int two[3];
    } long_double_hack;

    long_double_hack.one = 3.14;

    unsigned int long_double_mask[3];
    long_double_mask[0] = 1U << 31;

    for (int i = 0; i < 96; i++)
    {
        int index = -1;
        if (i < 96 / 3)
        {
            index = 0;
        } else if (i < 96 / 3 * 2)
        {
            index = 1;
        } else
        {
            index = 2;
        }

        std::cout << ((long_double_hack.two[index] & long_double_mask[index]) ? "1" : "0");

        long_double_mask[index] >>= 1;

        if (long_double_mask[index] == 0 && index != 2)
        {
            long_double_mask[index + 1] = 1U << 31;
        }
    }
}