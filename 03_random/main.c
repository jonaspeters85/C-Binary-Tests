
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include "../lib/binary_display.h"
#include "../lib/colors.h"

#define NL printf("\n");

int check_ifalpha(unsigned int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void to_lowercaser(char *s)
{
    while(*s != '\0')
    {
        if (check_ifalpha(*s))
            *s = *s | (1u << 5);
        s++;
    }
}

void to_uppercaser(char *s)
{
    while(*s != '\0')
    {
        if (check_ifalpha(*s))
            *s = *s & ~(1u << 5);
        s++;
    }
}

void switch_lower_upper_caser(char *s)
{
    while(*s != '\0')
    {
        if (check_ifalpha(*s))
            *s = *s ^ (1u << 5);
        s++;
    }
}

void test_bit_set()
{
    printf("----------------------------------------------------------------\n");
    printf(COLOR_GREEN "Using bitshifting and bit mask to set a Captial letter to lowercase letter\n" COLOR_RESET);
    unsigned int ASCII_A = 65;
    unsigned int ASCII_a = 97;

    NL

    printf("Binary representation of ASCII 'A' (%u) is: \t", ASCII_A);
    print_binary_high_is_green(ASCII_A);
    printf("Binary representation of ASCII 'a' (%u) is: \t", ASCII_a);
    print_binary_high_is_green(ASCII_a);

    NL
    printf("the difference between 'A' and 'a' is the 6th bit (bit 5, starting at 0)\n");
    NL

    printf("check 6th bit (5) of 'A' with  ASCII_A & (1u << 5) = %u \n", ASCII_A & (1u << 5));
    printf("check 6th bit (5) of 'a' with  ASCII_a & (1u << 5) = %u \n", ASCII_a & (1u << 5));

    NL

    printf("hightlight 6th bit of 'A': ");
    print_binary_highlight(ASCII_A, 5);
    printf("hightlight 6th bit of 'a': ");
    print_binary_highlight(ASCII_a, 5);

    NL

    printf("set 6th bit (5) high\nASCII_A = "COLOR_PURPLE"ASCII_A | (1u << 5);\n" COLOR_RESET);
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

    NL  
    printf(""COLOR_YELLOW"\n");
    printf("if in the mask is a 1, the resulting bit is set to 1\n");
    printf("if in the mask is a 0, the resulting bit remains unchanged\n");
    printf(""COLOR_RESET"\n");

    char test_str[] ="Hello, World!";

    printf("Test String: %s\n", test_str); 
    to_lowercaser(test_str);
    printf("\nresult: %s\n", test_str);

    NL
    NL
}

void test_clear_bit()
{
    printf("----------------------------------------------------------------\n");

    printf(COLOR_RED "Using bitshifting and bit mask to clear a lowercase letter to Capital letter\n" COLOR_RESET);
    unsigned int ASCII_A = 65;
    unsigned int ASCII_a = 97;

    NL

    printf("Binary representation of ASCII 'A' (%u) is: \t", ASCII_A);
    print_binary_high_is_green(ASCII_A);
    printf("Binary representation of ASCII 'a' (%u) is: \t", ASCII_a);
    print_binary_high_is_green(ASCII_a);

    NL
    printf("the difference between 'A' and 'a' is the 6th bit (bit 5, starting at 0)\n");
    NL

    printf("check 6th bit (5) of 'A' with  ASCII_A & (1u << 5) = %u \n", ASCII_A & (1u << 5));
    printf("check 6th bit (5) of 'a' with  ASCII_a & (1u << 5) = %u \n", ASCII_a & (1u << 5));

    NL

    printf("hightlight 6th bit of 'A': ");
    print_binary_highlight(ASCII_A, 5);
    printf("hightlight 6th bit of 'a': ");
    print_binary_highlight(ASCII_a, 5);

    NL

    printf("clear 6th bit (5) low\nASCII_a = "COLOR_PURPLE"ASCII_a & ~(1u << 5);\n" COLOR_RESET);
    ASCII_a = ASCII_a & ~(1u << 5);

    printf("hightlight 6th bit of 'a': ");
    print_binary_highlight(ASCII_a, 5);

    NL

    char test_str[] ="Hello, World!";

    printf("Test String: %s\n", test_str); 
    to_uppercaser(test_str);
    printf("\nresult: %s\n", test_str);
}

void test_switch_case()
{
    printf("----------------------------------------------------------------\n");
    printf(COLOR_YELLOW "Using bitshifting and bit mask to switch case of letters\n" COLOR_RESET);
    
    NL
    printf("Using XOR (^) operator to toggle the 6th bit (5) to switch case\n");
    printf("number = number ^ (1u << 5)");
    
    char test_str[] ="Hello, World!";

    printf("Test String: %s\n", test_str); 
    switch_lower_upper_caser(test_str);
    printf("\nresult: %s\n", test_str);
}

// random tests
int main()
{
    test_bit_set();
    test_clear_bit();
    test_switch_case();
    return 0;
}

