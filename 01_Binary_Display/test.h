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
        printf("check bit> ");
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
        printf("After setting : "COLOR_MAGENTA"%u\n"COLOR_RESET, test_value);
    

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
        printf("After clearing : "COLOR_MAGENTA"%u\n"COLOR_RESET, test_value);
    

        printf("\n");
    }
}

void test04()
{
    printf("Test 04: "COLOR_YELLOW"toggle "COLOR_BLUE"n bit "COLOR_RESET"\n");
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
    printf("Enter bit position to "COLOR_YELLOW"toggle"COLOR_RESET" ... starting at 0 (blank line to finish):\n");
    while (1)
    {
        printf("toggle bit> ");
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

        printf("\n"COLOR_CYAN"%i ^= (1u << %i) "COLOR_RESET"\n", test_value, number);
        test_value ^= (1u << number);
        print_binary_highlight(test_value, number);
        printf("After toggling : "COLOR_MAGENTA"%u\n"COLOR_RESET, test_value);
    

        printf("\n");
    }
}

void test05()
{
    printf("Test 05: "COLOR_YELLOW"shift "COLOR_BLUE"n bit "COLOR_RESET"\n");
    printf("===========================\n\n");

    int test_value = 7; // Example value
    printf("input value: \n");
    scanf("%d", &test_value);
    getchar(); // Consume the newline character left in the input buffer

    printf("Binary representation of %d is: ", test_value);
    print_binary(test_value);
    printf("\n");

    int number;
    char line[64];
    printf("Enter bits to "COLOR_YELLOW"shift"COLOR_RESET" ... starting at 0 (blank line to finish):\n");
    while (1)
    {
        printf("shift bit> ");
        if (!fgets(line, sizeof(line), stdin))
        {
            break; // EOF
        }

        // Stop on empty line (just a newline)
        if (line[0] == '\n' || line[0] == '\0')
        {
            break;
        }

        if (sscanf(line, "%d", &number) != 1)
        {
            printf("Invalid input. Please enter an unsigned integer or blank to exit.\n");
            continue;
        }

         printf("number: %d\n", number);

        if (number > 0)
        {
            printf("\n"COLOR_CYAN"%i <<= %i "COLOR_RESET"\n", test_value, number);
            test_value <<= number;
        }
        else
        {
           
            printf("\n"COLOR_CYAN"%i >>= %i "COLOR_RESET"\n", test_value, -number);
            test_value >>= -number;
        }
  
        print_binary(test_value);
        printf("After shifting : "COLOR_MAGENTA"%u\n"COLOR_RESET, test_value);
    

        printf("\n");
    }
}

static int read_key2(void)
{
    struct termios oldt, newt;
    int ch;
    if (tcgetattr(STDIN_FILENO, &oldt) == -1) {
        return getchar();
    }
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void menu_tests()
{
    for (;;)
    {
        printf("\n================ MENU ================\n");
        printf("[1] Test 01: check if n bit is set\n");
        printf("[2] Test 02: set n bit\n");
        printf("[3] Test 03: clear n bit\n");
        printf("[4] Test 04: toggle n bit\n");
        printf("[5] Test 05: shift n bit\n");
        printf("[ESC] End\n");


        int ch = read_key2();
        printf("Selection (1-5 or ESC): ");

        if (ch == EOF)
        {
            break;
        }

        putchar(ch);
        putchar('\n');

        if (ch == 27) // ESC
        {
            printf("Ended.\n");
            break;
        }
        printf("\n");
        switch (ch)
        {
            case '1':
                test01();
                break;
            case '2':
                test02();
                break;
            case '3':
                test03();
                break;
            case '4':
                test04();
                break;
            case '5':
                test05();
                break;
            default:
                printf("Invalid selection. Please enter 1-5 or ESC.\n");
                break;
        }
    }
}


#endif // TEST_H