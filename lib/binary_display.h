#ifndef BINARY_DISPLAY_H
#define BINARY_DISPLAY_H

#include <stdio.h>
#include "colors.h"

//#define DEBUG
//#define DEBUG2

// binary_editor() edits and displays binary values ... close with ctrl+c

void print_binary_simple(unsigned int n)
{
    if (n > 1) {
        print_binary_simple(n >> 1);       //right shift ... divide by 2... higher bits first
    }
    putchar((n & 1) ? '1' : '0');   //print least significant bit ... (n & 1) checks if the last bit is 1 or 0
}

static int required_bits(unsigned int value)
{
    int bits = 0;

    do
    {
        bits++;
        value >>= 1;
    }
    while (value != 0);
#ifdef DEBUG
    printf("required_bits: %d\n", bits);
#endif
    return bits;
}

/* Prints an integer as binary, grouped by nibbles and bytes */
void print_binary(int value)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;      /// Always round up to full bytes (8 bits)

#ifdef DEBUG
    printf("\n value = %d", value);
    printf("\n uvalue = %u", uvalue);
    printf("\n bits = %d", bits);
    printf("\n total_bits = %d", total_bits);
#endif

    for (int i = total_bits - 1; i >= 0; i--)
    {
#ifdef DEBUG
        printf("\n        (%u & (1u << %i)) = %u\n", uvalue, i, (uvalue & (1u << i)));
#endif
        putchar((uvalue & (1u << i)) ? '1' : '0');  // Check if the i-th bit is set

        if (i % 8 == 0 && i != 0)
        {
            putchar(' ');
            putchar(' ');
        }
        else if (i % 4 == 0 && i != 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}

/* Prints an integer as binary, grouped by nibbles and bytes ... 0 is red 1 is green*/
void print_binary_color(int value)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;      /// Always round up to full bytes (8 bits)

#ifdef DEBUG
    printf("\n value = %d", value);
    printf("\n uvalue = %u", uvalue);
    printf("\n bits = %d", bits);
    printf("\n total_bits = %d", total_bits);
#endif

    for (int i = total_bits - 1; i >= 0; i--)
    {
#ifdef DEBUG
        printf("\n        (%u & (1u << %i)) = %u\n", uvalue, i, (uvalue & (1u << i)));
#endif
        //putchar((uvalue & (1u << i)) ? '1' : '0');  // Check if the i-th bit is set
        int bit_value = (uvalue & (1u << i)) ? 1 : 0;
        printf("%s%d%s", bit_value ? COLOR_GREEN : COLOR_RED, bit_value, COLOR_RESET);
        if (i % 8 == 0 && i != 0)
        {
            putchar(' ');
            putchar(' ');
        }
        else if (i % 4 == 0 && i != 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}

/* Prints an integer as binary, grouped by nibbles and bytes ... 1 is green*/
void print_binary_high_is_green(int value)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;      /// Always round up to full bytes (8 bits)

#ifdef DEBUG
    printf("\n value = %d", value);
    printf("\n uvalue = %u", uvalue);
    printf("\n bits = %d", bits);
    printf("\n total_bits = %d", total_bits);
#endif

    for (int i = total_bits - 1; i >= 0; i--)
    {
#ifdef DEBUG
        printf("\n        (%u & (1u << %i)) = %u\n", uvalue, i, (uvalue & (1u << i)));
#endif
        //putchar((uvalue & (1u << i)) ? '1' : '0');  // Check if the i-th bit is set
        //int bit_value = (uvalue & (1u << i)) ? 1 : 0;
        printf("%s%d%s", ((uvalue & (1u << i)) ? 1 : 0) ? COLOR_GREEN : COLOR_RESET, ((uvalue & (1u << i)) ? 1 : 0), COLOR_RESET);
        if (i % 8 == 0 && i != 0)
        {
            putchar(' ');
            putchar(' ');
        }
        else if (i % 4 == 0 && i != 0)
        {
            putchar(' ');
        }
    }

    //putchar('\n');
}



void print_binary_highlight(int value, int highlight_bit)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;

#ifdef DEBUG
    printf("\n value = %d", value);
    printf("\n uvalue = %u", uvalue);
    printf("\n bits = %d", bits);
    printf("\n total_bits = %d", total_bits);
    printf("\n highlight_bit = %d", highlight_bit);
#endif

    for (int i = total_bits - 1; i >= 0; i--)
    {
#ifdef DEBUG
        printf("\n        (%u & (1u << %i)) = %u\n", uvalue, i, (uvalue & (1u << i)));
#endif
        
        if (i == highlight_bit)
        {
            int bit_value = (uvalue & (1u << i)) ? 1 : 0;
            printf("%s%d%s", bit_value ? COLOR_GREEN : COLOR_RED, bit_value, COLOR_RESET);
        }
        else
        {
            putchar((uvalue & (1u << i)) ? '1' : '0');
        }

        if (i % 8 == 0 && i != 0)
        {
            putchar(' ');
            putchar(' ');
        }
        else if (i % 4 == 0 && i != 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}

// will be called from print_binary_with_byte_naming()
void print_decimal_8bit_bytes_groups(int value)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;      /// Always round up to full bytes (8 bits)
    int num_bytes = total_bits / 8;

    for (int byte_num = num_bytes - 1; byte_num >= 0; byte_num--)
    {
        unsigned int byte_value = (uvalue >> (byte_num * 8)) & 0xFF;
        printf("%-9u", byte_value);
        if (byte_num > 0)
        {
            printf("  ");  // 2 spaces between bytes to match binary output spacing
        }
    }
}

// will be called from print_binary_with_byte_naming()
void printf_ascci_8bit_bytes_groups(int value)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;      /// Always round up to full bytes (8 bits)
    int num_bytes = total_bits / 8;

    for (int byte_num = num_bytes - 1; byte_num >= 0; byte_num--)
    {
        unsigned int byte_value = (uvalue >> (byte_num * 8)) & 0xFF;
        char c = (byte_value >= 32 && byte_value <= 126) ? (char)byte_value : '.';
        printf("%-9c", c);
        if (byte_num > 0)
        {
            printf("  ");  // 2 spaces between bytes to match binary output spacing
        }
    }
}


void print_binary_with_byte_naming(int value)
{
    unsigned int uvalue = (unsigned int)value;
    int bits = required_bits(uvalue);
    int total_bits = ((bits + 7) / 8) * 8;      /// Always round up to full bytes (8 bits)
    int num_bytes = total_bits / 8;
#ifdef DEBUG2
    printf("print_binary_with_byte_naming(%d)\n", value);
    printf("bits: %d\n", bits);
    printf("total_bits: %d\n", total_bits);
    printf("num_bytes: %d\n\n", num_bytes);
#endif

    // Print byte labels on first line
    for (int byte_num = num_bytes - 1; byte_num >= 0; byte_num--)
    {
        printf("[byte %d] ", byte_num);
        if (byte_num > 0)
        {
            printf("  ");  // 2 spaces between bytes to match binary output spacing
        }
    }
 
    //putchar('\n');

    // Print decimal value
    printf("  Decimal ");
    printf("  Hex");


    putchar('\n');

    // Print the bits with colors
    print_binary_high_is_green(value);

    printf("  %-8d  ", value);
    printf("0x%X  ", (unsigned int)value);

    putchar('\n');
    
    print_decimal_8bit_bytes_groups(value);

    putchar('\n');

    printf_ascci_8bit_bytes_groups(value);

    putchar('\n');
}

#endif // BINARY_DISPLAY_H