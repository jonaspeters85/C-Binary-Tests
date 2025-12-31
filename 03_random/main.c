
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "../lib/binary_display.h"

#define NL printf("\n");

// random tests
int main()
{
    unsigned int ASCII_A = 65;
    unsigned int ASCII_a = 97;

    printf("Binary representation of ASCII 'A' (%u) is: \t", ASCII_A);
    print_binary_high_is_green(ASCII_A);
    printf("Binary representation of ASCII 'a' (%u) is: \t", ASCII_a);
    print_binary_high_is_green(ASCII_a);

    NL

    printf("check 6th bit (5) of 'A' %u \n", ASCII_A & (1u << 5));
    printf("check 6th bit (5) of 'a' %u \n", ASCII_a & (1u << 5));

    NL

    printf("hightlight 6th bit of 'A': ");
    print_binary_highlight(ASCII_A, 5);
    printf("hightlight 6th bit of 'a': ");
    print_binary_highlight(ASCII_a, 5);



    NL

    printf("set 6th bit (5) high\nASCII_A = ASCII_A | (1u << 5);\n");
    ASCII_A = ASCII_A | (1u << 5);

    printf("hightlight 6th bit of 'A': ");
    print_binary_highlight(ASCII_A, 5);

    NL

    printf("\tshift left tests for better understanding:\n\t--------------‚----------------------------\n");
    printf("\t(1u << 5) : ");
    printf("\t%u\n", 1u << 5);
    printf("\tNumber 1u (unsiged) shifted left by 5 bits results in: ");
    print_binary_high_is_green(1u << 5);
    NL
    printf("\t(2u << 4) : ");
    printf("\t%u\n", 2u << 4);
    printf("\tNumber 2u (unsiged) shifted left by 4 bits results in: ");
    print_binary_high_is_green(2u << 4);
    NL
    printf("\t(4u << 3) : ");
    printf("\t%u\n", 4u << 3);
    printf("\tNumber 4u (unsiged) shifted left by 3 bits results in: ");
    print_binary_high_is_green(4u << 3);
    NL
    printf("etc... is all about shifting bits to the left. The result is always the same (32 for bit 5 set)!\n");
    printf("result is a bitmask with only the desired bit set high. 0010 0000 = 32 decimal\n");
    NL

    printf("\t"COLOR_CYAN"|" COLOR_RESET " is bitwise OR operator\n"); 
    printf("\t0 | 0 = 0\n\t0 | "COLOR_GREEN"1" COLOR_RESET " = "COLOR_GREEN"1" COLOR_RESET "\n\t"COLOR_GREEN"1" COLOR_RESET " | 0 = "COLOR_GREEN"1" COLOR_RESET "\n\t"COLOR_GREEN"1" COLOR_RESET " | "COLOR_GREEN"1" COLOR_RESET " = "COLOR_GREEN"1" COLOR_RESET "\n");

    char* test_str = "Hello, World!";

    return 0;
}

