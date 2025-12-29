#include <stdio.h>
#include "binary_display.h"


int main()
{
    unsigned int number;

    printf("Enter a non-negative integer: ");
    if (scanf("%u", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Binary representation: ");
    print_binary(number);


    printf("\n");

    return 0;
}