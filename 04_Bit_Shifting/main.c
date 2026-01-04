
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include "../lib/binary_display.h"
#include "../lib/colors.h"

#define NL printf("\n");



void building_24_bit_value()
{
    unsigned int red = 64u;
    unsigned int green = 89u;
    unsigned int blue = 111u;

    unsigned int color_value = (red << 16) | (green << 8) | (blue << 0);
    printf("res = (%u << 16) | (%u << 8) | (%u << 0).  = %u\n", red, green, blue, color_value);

    printf("Color Value: %u\n", color_value);
    print_binary_high_is_green(color_value);
    print_binary_with_byte_naming(color_value);
}


// Bit Shifting
int main()
{
    printf("Bit shifting\n============\n");

    building_24_bit_value();


    return 0;
}

