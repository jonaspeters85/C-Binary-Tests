
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include "../lib/binary_display.h"
#include "../lib/colors.h"

#define NL printf("\n");

void building_16_bit_value()
{
    printf(COLOR_BLUE"building_16_bit_value \n=============================\n"COLOR_RESET);

    unsigned int green = 3u;
    unsigned int blue = 7u;

    unsigned int color_value =  (green << 8) | (blue << 0);
    printf("res = (%u << 8) | (%u << 0) = %u\n",  green, blue, color_value);

    printf("Color Value: %u\n", color_value);

    NL
    
    print_binary_with_byte_naming(color_value);
}

void building_24_bit_value()
{
        printf(COLOR_BLUE"building_24_bit_value \n=============================\n"COLOR_RESET);

    unsigned int red = 64u;
    unsigned int green = 89u;
    unsigned int blue = 111u;

    unsigned int color_value = (red << 16) | (green << 8) | (blue << 0);
    printf("res = (%u << 16) | (%u << 8) | (%u << 0) = %u\n", red, green, blue, color_value);

    printf("Color Value: %u\n", color_value);

    NL
    
    print_binary_with_byte_naming(color_value);
}

void extract_8bits(int value)
{
    printf(COLOR_BLUE"Extract_8bits value: %d \n=============================\n"COLOR_RESET, value);

    printf("(%d >> 8) = %d \n", value, (value >> 8));


    print_binary_high_is_green(value);
    putchar('\n');
    print_binary_high_is_green((value >> 8));

    putchar('\n');
    putchar('\n');
    for (int i = 0; i < 3; i++)
    {
        unsigned int byte_value = (value >> (i * 8)) & 0xFF;
        print_binary_high_is_green(byte_value);
        putchar('\n');
    }
}

void extract_bytes(int value)
{
    printf(COLOR_BLUE"Extract_bytes value: %d \n=============================\n"COLOR_RESET, value);
    int res = value;
    int bytes = (required_bits(value)/8) + 1;
    print_binary_with_byte_naming(res);
    NL
    NL
    for (int i = 0; i < bytes; i++)
    {
        print_binary_high_is_green((res >> (i * 8)) & 255);
        if (i == 0)
            printf("  LSB");
        if (i == bytes -1)
            printf("  MSB");
        putchar('\n');
    }

    printf("\n"COLOR_GREEN"Explanation:"COLOR_RESET"\n");
    printf("Extracted byte %d: (value >> (%d * 8)) & 0xFF = (%d >> %d) & 255 = %d\n", 0, 0, res, 0, (res >> 0) & 255);
    printf("Extracted byte %d: (value >> (%d * 8)) & 0xFF = (%d >> %d) & 255 = %d\n", 1, 1, res, 8, (res >> 8) & 255);
    printf("Extracted byte %d: (value >> (%d * 8)) & 0xFF = (%d >> %d) & 255 = %d\n\n", 2, 2, res, 16, (res >> 16) & 255);  
    
    printf("Where "COLOR_CYAN"LSB" COLOR_RESET " = Least Significant Byte and "COLOR_PURPLE"MSB" COLOR_RESET " = Most Significant Byte\n");
    printf(COLOR_YELLOW"(value >> (i * 8))" COLOR_RESET " shifts the value right by i bytes, & 0xFF masks to get the lowest 8 bits.\n");
    printf("0xFF is 255 in decimal, which is 11111111 in binary, effectively "COLOR_YELLOW"isolating" COLOR_RESET " the "COLOR_GREEN"desired byte" COLOR_RESET ". The rest will be deleted.\n");
    printf("If you mask with 0xFFFF (11111111 11111111) you would get 16 bits instead of 8 bits. "COLOR_PURPLE"MSB" COLOR_RESET " will "COLOR_RED"deleted.\n"COLOR_RESET);

    putchar('\n');
}

void extract_bytes_16bit(int value)
{
    printf(COLOR_BLUE"Extract_bytes_16bit value: %d \n=============================\n"COLOR_RESET, value);
    printf("using bitmask 0xFFFF to extract 16 bits per group\n\n");
    
    int res = value;
    int bytes = (required_bits(value)/8) + 1;
    print_binary_with_byte_naming(res);

    putchar('\n');
    putchar('\n');

    print_binary_high_is_green(res);
    putchar('\n');
    putchar('\n');
    for (int i = 0; i < bytes; i++)
    {
        print_binary_high_is_green((res >> (i * 8)) & 0xFFFF);
        if (i == 0)
            printf("  LSB");
        if (i == bytes -1)
            printf("  MSB");
        putchar('\n');
    }
}

// Bit Shifting
int main()
{
    printf("Bit shifting\n============\n");
    building_16_bit_value();

NL
NL

    building_24_bit_value();
NL
NL

    extract_8bits(4217199);
NL
NL
    extract_bytes(4217199);

NL
NL
    extract_bytes_16bit(4217199);
    return 0;
}

