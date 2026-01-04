
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include "../lib/binary_display.h"
#include "../lib/colors.h"

#define NL printf("\n");

// Bit Shifting
int main()
{
    printf("Bit shifting\n============\n");

    int n = 7;
    //printf("n = %u   (n << 1) = %u \n", n, (n << 1));

    printf("Builing a 24 bit Value with 3 8bit Values i.e. for RGB Colores\n");
    unsigned int res = (254u << 16) | (1u << 8) | (3 << 0);
    printf("res = (254u << 16) | (1u << 8) | (2 << 0).  = %u\n", res);

    print_binary_high_is_green(res);

    return 0;
}

