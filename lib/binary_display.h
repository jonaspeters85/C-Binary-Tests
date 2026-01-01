#ifndef BINARY_DISPLAY_H
#define BINARY_DISPLAY_H

#include <stdio.h>
#include "colors.h"

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

    putchar('\n');
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




#endif // BINARY_DISPLAY_H