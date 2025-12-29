#include <stdio.h>
#include "binary_display.h"



void test01()
{
    printf("Test 01: check n bit set\n");
    printf("========================\n\n");

    int test_value = 7; // Example value
    printf("input value: \n");
    scanf("%d", &test_value);
    getchar(); // Consume the newline character left in the input buffer

    printf("Binary representation of %d is: ", test_value);
    print_binary(test_value);
    printf("\n");

    unsigned int number;
    char line[64];
    printf("Enter bit positions startin at 0 (blank line to finish):\n");
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

        printf("%i & (1u << %i) = %u\n", test_value, number, (test_value & (1u << number)));
        
        if (test_value & (1u << number))
        {
            print_binary_highlight(test_value, number);
            printf("Bit %u is set in %d.\n", number, test_value);
        }
        else
        {
            print_binary_highlight(test_value, number);
            printf("Bit %u is not set in %d.\n", number, test_value);
        }

        printf("\n");
    }
}


int main()
{
    unsigned int number;

    test01();

    // printf("Enter a non-negative integer: ");
    // if (scanf("%u", &number) != 1) {
    //     printf("Invalid input.\n");
    //     return 1;
    // }

    // printf("Binary representation: ");
    // print_binary(number);


    printf("\n");

    return 0;
}