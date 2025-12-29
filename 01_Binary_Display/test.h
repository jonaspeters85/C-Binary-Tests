#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include "binary_display.h"
#include "colors.h"

void test01()
{
    printf("Test 01: check if n bit "COLOR_GREEN"is "COLOR_RESET"set\n");
    printf("===========================\n\n");

    int test_value = 7; // Example value
    printf("input value: \n");
    scanf("%d", &test_value);
    getchar(); // Consume the newline character left in the input buffer

    printf("Binary representation of %d is: ", test_value);
    print_binary(test_value);
    printf("\n");

    unsigned int number;
    char line[64];
    printf("Enter bit position ... starting at 0 (blank line to finish):\n");
    while (1)
    {
        printf("bit> ");
        if (!fgets(line, sizeof(line), stdin))
        {
            break; // EOF
        }

        // Stop on empty line (just a newline)
        if (line[0] == '\n' || line[0] == '\0')
        {
            break;
        }

        if (sscanf(line, "%u", &number) != 1)
        {
            printf("Invalid input. Please enter an unsigned integer or blank to exit.\n");
            continue;
        }

        printf("\n"COLOR_CYAN"%i & (1u << %i) = %u"COLOR_RESET"\n", test_value, number, (test_value & (1u << number)));
        
        if (test_value & (1u << number))
        {
            print_binary_highlight(test_value, number);
            printf("Bit "COLOR_BLUE"%u"COLOR_RESET" is"COLOR_GREEN" set "COLOR_RESET"in %d.\n", number, test_value);
        }
        else
        {
            print_binary_highlight(test_value, number);
            printf("Bit "COLOR_BLUE"%u"COLOR_RESET" is"COLOR_RED" not "COLOR_RESET"set in %d.\n", number, test_value);
        }

        printf("\n");
    }
}

void test02()
{
    printf("Test 02: "COLOR_GREEN"set "COLOR_BLUE"n bit "COLOR_RESET"\n");
    printf("===========================\n\n");

    int test_value = 7; // Example value
    printf("input value: \n");
    scanf("%d", &test_value);
    getchar(); // Consume the newline character left in the input buffer

    printf("Binary representation of %d is: ", test_value);
    print_binary(test_value);
    printf("\n");

    unsigned int number;
    char line[64];
    printf("Enter bit position set to "COLOR_GREEN"1"COLOR_RESET" ... starting at 0 (blank line to finish):\n");
    while (1)
    {
        printf("set bit> ");
        if (!fgets(line, sizeof(line), stdin))
        {
            break; // EOF
        }

        // Stop on empty line (just a newline)
        if (line[0] == '\n' || line[0] == '\0')
        {
            break;
        }

        if (sscanf(line, "%u", &number) != 1)
        {
            printf("Invalid input. Please enter an unsigned integer or blank to exit.\n");
            continue;
        }

        printf("\n"COLOR_CYAN"%i |= (1u << %i) "COLOR_RESET"\n", test_value, number);
        test_value |= (1u << number);
        print_binary_highlight(test_value, number);
        printf("After setting : %u\n", test_value);
    

        printf("\n");
    }
}

void test03()
{
    printf("Test 03: "COLOR_RED"clear "COLOR_BLUE"n bit "COLOR_RESET"\n");
    printf("===========================\n\n");

    int test_value = 7; // Example value
    printf("input value: \n");
    scanf("%d", &test_value);
    getchar(); // Consume the newline character left in the input buffer

    printf("Binary representation of %d is: ", test_value);
    print_binary(test_value);
    printf("\n");

    unsigned int number;
    char line[64];
    printf("Enter bit position set to "COLOR_RED"0"COLOR_RESET" ... starting at 0 (blank line to finish):\n");
    while (1)
    {
        printf("clear bit> ");
        if (!fgets(line, sizeof(line), stdin))
        {
            break; // EOF
        }

        // Stop on empty line (just a newline)
        if (line[0] == '\n' || line[0] == '\0')
        {
            break;
        }

        if (sscanf(line, "%u", &number) != 1)
        {
            printf("Invalid input. Please enter an unsigned integer or blank to exit.\n");
            continue;
        }

        printf("\n"COLOR_CYAN"%i &= ~(1u << %i) "COLOR_RESET"\n", test_value, number);
        test_value &= ~(1u << number);
        print_binary_highlight(test_value, number);
        printf("After clearing : %u\n", test_value);
    

        printf("\n");
    }
}


#endif // TEST_H