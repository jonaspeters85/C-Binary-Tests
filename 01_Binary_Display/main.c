
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "binary_display.h"
#include "test.h"

static int read_key(void)
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

int main()
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


        int ch = read_key();
        printf("Selection (1-5 or ESC): ");

        //int ch = getchar();
        if (ch == EOF)
        {
            break;
        }

        // Konsumiere Rest der Zeile
        //flush_line();
        putchar(ch);
        putchar('\n');

        if (ch == 27) // ESC
        {
            printf("Ended.\n");
            break;
        }

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

    return 0;
}