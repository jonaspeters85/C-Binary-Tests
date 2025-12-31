
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "../lib/binary_display.h"

// random tests
int main()
{
    unsigned int number;
    printf("Input number to display in binary: \t");
    scanf("%u", &number);

    printf("Binary representation of %u is: \t", number);
    print_binary_high_is_green(number);




    return 0;
}