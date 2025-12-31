
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "../lib/binary_display.h"




int main()
{
    unsigned int number;
    printf("Input number to display in binary: ");
    scanf("%u", &number);
    printf("Binary representation of %u is: ", number);

    print_binary_color(number);

    return 0;
}