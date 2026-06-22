#include <stdio.h>
#include <stdlib.h>

#include "bigint.h"
#include "test/bint_test.h"
#include "linkedlist.h"

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

int main(int argc, char const *argv[])
{
    bInt *eheh = new_int(4);
    set_value(eheh, -2459);
    print_bit_i(eheh);
    print_dec_i(eheh);
    free_int(&eheh);
    return 0;
}
