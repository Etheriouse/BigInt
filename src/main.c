#include <stdio.h>
#include <stdlib.h>

#include "bigint.h"
#include "bitlib.h"
#include "test/bint_test.h"
#include "linkedlist.h"
#include "karatsuba.h"

void console_log(const char *s)
{
    printf("%s\n", s);
}

void log_char(void *x)
{
    unsigned char value = *((unsigned char *)x);
    for (int j = 0; j < 8; j++)
    {
        printf("%d", (value >> 7) & 0x1); // decale de 7 sur la droite, puis mask pour obtenir last bit
        value = value << 1;               // decale la valeur vers la gauche de 1
    }
}

int cmpint(void *a, void *b)
{
    return *((int *)a) - *((int *)b);
}

void log_debug_print_bit(unsigned char *n, size_t nb)
{
    size_t size = 12 + 3 + nb * 10;
    char buffer[size];
    size_t offset = 0;
    unsigned char value;
    offset += snprintf(buffer + offset, size - offset, "%lubit number:\n", nb * 8);
    for (size_t i = 0; i < nb; i++)
    {
        value = n[i];
        for (int j = 0; j < 8; j++)
        {
            offset += snprintf(buffer + offset, size - offset, "%d", (value >> 7) & 0x1); // decale de 7 sur la droite, puis mask pour obtenir last bit
            value = value << 1;   
            if(j == 3) {
                offset += snprintf(buffer + offset, size - offset, " ");
            }                                                        // decale la valeur vers la gauche de 1
        }
        offset += snprintf(buffer + offset, size - offset, " ");
    }
    printf("%s\n", buffer);
}

int main(int argc, char const *argv[])
{
    main_test();

    bInt *a = new_int(8, false);
    bInt *b = new_int(8, false);

    set_lvalue(a, 0xDCADF798DC);
    set_lvalue(b, 0xC0AD6A07F1);

    print_dec_i(a);
    print_dec_i(b);

    unsigned char *c = karatsuba(a->bytes, a->n_bytes, b->bytes, b->n_bytes);

    log_debug_print_bit(c, 16);

    free_int(&a);
    free_int(&b);
    free(c);

    return 0;
}
