
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "../lib/binary_display.h"

// Simple main function to demonstrate binary display normal, with colors and highlighted bit
int main()
{
    unsigned int number;
    printf("Input number to display in binary: \t");
    scanf("%u", &number);

    printf("Binary representation of %u is: \t", number);
    print_binary(number);

    printf("Binary representation of %u is: \t", number);
    print_binary_color(number);

    printf("Highlighting bit 3: \t\t\t");
    print_binary_highlight(number, 3);


    return 0;
}