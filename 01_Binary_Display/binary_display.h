#ifndef BINARY_DISPLAY_H
#define BINARY_DISPLAY_H

#include <stdio.h>

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
int print_binary(int value)
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

#endif // BINARY_DISPLAY_H