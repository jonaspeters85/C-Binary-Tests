#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

/* ---------- Binary formatting helpers ---------- */

/* Returns the number of bits needed to represent the value (at least 1) */
static int required_bits_u32(uint32_t value)
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

/* Prints value in binary grouped by 4 bits and with double-space per 8 bits.
   Always prints at least 8 bits, and rounds up to full bytes. */
static void print_binary_u32(uint32_t value)
{
    int bits = required_bits_u32(value);
    int total_bits = ((bits + 7) / 8) * 8;

    if (total_bits < 8)
    {
        total_bits = 8;
    }

    for (int i = total_bits - 1; i >= 0; i--)
    {
        putchar((value & (1u << i)) ? '1' : '0');

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
}

/* ---------- Bit operations ---------- */

static int is_bit_set_u32(uint32_t value, unsigned int n)
{
    if (n >= 32u)
    {
        return 0;
    }

    return (value & (1u << n)) != 0;
}

static void set_bit_u32(uint32_t *value, unsigned int n)
{
    if (n >= 32u)
    {
        return;
    }

    *value |= (1u << n);
}

static void clear_bit_u32(uint32_t *value, unsigned int n)
{
    if (n >= 32u)
    {
        return;
    }

    *value &= ~(1u << n);
}

static void toggle_bit_u32(uint32_t *value, unsigned int n)
{
    if (n >= 32u)
    {
        return;
    }

    *value ^= (1u << n);
}

static void shift_left_u32(uint32_t *value, unsigned int n)
{
    if (n >= 32u)
    {
        *value = 0;
        return;
    }

    *value <<= n;
}

static void shift_right_u32(uint32_t *value, unsigned int n)
{
    if (n >= 32u)
    {
        *value = 0;
        return;
    }

    *value >>= n;
}

/* ---------- UI helpers ---------- */

static void print_state(uint32_t value)
{
    printf("Value: ");
    print_binary_u32(value);
    printf("    (hex: 0x%08X, dec: %u)\n", value, value);
}

/* Reads one line; returns 0 on EOF */
static int read_line(char *buf, size_t buflen)
{
    if (fgets(buf, (int)buflen, stdin) == NULL)
    {
        return 0;
    }

    return 1;
}

/* Detects ANSI arrow escape sequences in the line:
   Left:  ESC [ D
   Right: ESC [ C */
static int is_arrow_left(const char *s)
{
    return (unsigned char)s[0] == 27 && s[1] == '[' && s[2] == 'D';
}

static int is_arrow_right(const char *s)
{
    return (unsigned char)s[0] == 27 && s[1] == '[' && s[2] == 'C';
}

static void print_help(void)
{
    printf("Commands:\n");
    printf("  + n        set bit n to 1\n");
    printf("  - n        set bit n to 0\n");
    printf("  t n        toggle bit n\n");
    printf("  c n        check bit n (prints 0/1)\n");
    printf("  <          shift left by 1   (fallback)\n");
    printf("  >          shift right by 1  (fallback)\n");
    printf("  << n       shift left by n\n");
    printf("  >> n       shift right by n\n");
    printf("  s <num>    set value (decimal by default, 0x.. for hex)\n");
    printf("  z          zero value\n");
    printf("  h          help\n");
    printf("  q          quit\n");
    printf("  Arrow keys: left/right shift by 1 (if terminal sends ANSI ESC sequences)\n");
}

/* ---------- Main loop ---------- */

int biteditor(void)
{
    uint32_t value = 0;
    char line[256];

    print_help();
    print_state(value);

    while (1)
    {
        printf("> ");
        fflush(stdout);

        if (!read_line(line, sizeof(line)))
        {
            putchar('\n');
            break;
        }

        /* Handle arrow keys (line may contain ESC sequences) */
        if (is_arrow_left(line))
        {
            shift_left_u32(&value, 1);
            print_state(value);
            continue;
        }

        if (is_arrow_right(line))
        {
            shift_right_u32(&value, 1);
            print_state(value);
            continue;
        }

        /* Trim leading spaces */
        char *p = line;
        while (*p && isspace((unsigned char)*p))
        {
            p++;
        }

        if (*p == '\0')
        {
            continue;
        }

        /* Single-char commands */
        if ((p[0] == 'q' || p[0] == 'Q') && (p[1] == '\n' || p[1] == '\0'))
        {
            break;
        }

        if ((p[0] == 'h' || p[0] == 'H') && (p[1] == '\n' || p[1] == '\0'))
        {
            print_help();
            continue;
        }

        if ((p[0] == 'z' || p[0] == 'Z') && (p[1] == '\n' || p[1] == '\0'))
        {
            value = 0;
            print_state(value);
            continue;
        }

        if (p[0] == '<' && (p[1] == '\n' || p[1] == '\0'))
        {
            shift_left_u32(&value, 1);
            print_state(value);
            continue;
        }

        if (p[0] == '>' && (p[1] == '\n' || p[1] == '\0'))
        {
            shift_right_u32(&value, 1);
            print_state(value);
            continue;
        }

        /* Shift with count: << n  or  >> n */
        if (p[0] == '<' && p[1] == '<')
        {
            unsigned int n = 0;
            if (sscanf(p + 2, "%u", &n) == 1)
            {
                shift_left_u32(&value, n);
                print_state(value);
            }
            else
            {
                printf("Invalid shift. Example: << 3\n");
            }
            continue;
        }

        if (p[0] == '>' && p[1] == '>')
        {
            unsigned int n = 0;
            if (sscanf(p + 2, "%u", &n) == 1)
            {
                shift_right_u32(&value, n);
                print_state(value);
            }
            else
            {
                printf("Invalid shift. Example: >> 3\n");
            }
            continue;
        }

        /* Set value: s <num>  (strtoul supports 0x.. hex as well) */
        if (p[0] == 's' || p[0] == 'S')
        {
            while (*p && !isspace((unsigned char)*p))
            {
                p++;
            }
            while (*p && isspace((unsigned char)*p))
            {
                p++;
            }

            if (*p == '\0')
            {
                printf("Usage: s 123   or   s 0xFF\n");
                continue;
            }

            char *end = NULL;
            unsigned long tmp = strtoul(p, &end, 0);

            if (end == p)
            {
                printf("Invalid number.\n");
                continue;
            }

            value = (uint32_t)tmp;
            print_state(value);
            continue;
        }

        /* Bit commands: + n, - n, t n, c n */
        {
            char cmd = 0;
            unsigned int n = 0;

            if (sscanf(p, " %c %u", &cmd, &n) == 2)
            {
                if (cmd == '+')
                {
                    set_bit_u32(&value, n);
                    print_state(value);
                    continue;
                }
                else if (cmd == '-')
                {
                    clear_bit_u32(&value, n);
                    print_state(value);
                    continue;
                }
                else if (cmd == 't' || cmd == 'T')
                {
                    toggle_bit_u32(&value, n);
                    print_state(value);
                    continue;
                }
                else if (cmd == 'c' || cmd == 'C')
                {
                    printf("%d\n", is_bit_set_u32(value, n) ? 1 : 0);
                    continue;
                }
            }
        }

        printf("Unknown command. Type 'h' for help.\n");
    }

    return 0;
}
