#include <stdio.h>
#include <stdlib.h>
#include "bitlib.h"

unsigned char __sub(unsigned char *a, size_t na, unsigned char *b, size_t nb);
unsigned char __add(unsigned char *a, size_t na, unsigned char *b, size_t nb);
unsigned char __add_off(unsigned char *a, size_t na, unsigned char *b, size_t nb, size_t offset);


void debug_print_bit(unsigned char *n, size_t nb)
{
    size_t size = 12 + 3 + nb * 9;
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
            value = value << 1;                                                           // decale la valeur vers la gauche de 1
        }
        offset += snprintf(buffer + offset, size - offset, " ");
    }
    printf("%s\n", buffer);
}

// implique a et b meme taille
unsigned char *karatsuba(unsigned char *a, size_t na, unsigned char *b, size_t nb)
{
    printf("karatsuba size a: %lu b: %lu\n", na, nb);
    if (na > 4 && nb > 4)
    {
        size_t _m = na / 2;
        printf("m: %lu\n", _m);

        size_t sp1 = 2*_m;
        size_t sp2 = _m*2;
        size_t sp3 = _m*3;
        unsigned char *p1 = karatsuba(a, _m, b, _m);
        unsigned char *p2 = karatsuba(a + _m, na - _m, b + _m, nb - _m);
        
        unsigned char *copy_p1 = clone_arr(p1, sp1);
        unsigned char *copy_a = clone_arr(a, na);
        unsigned char *copy_b = clone_arr(b, nb);


        unsigned char carry1a= __add(copy_a, _m, a + _m, na - _m); // add of two half of a, if a = 4o, 2o+2o = 3o, so copya = 3o
        copy_a[na-_m-1] = carry1a;
        unsigned char carry2b = __add(copy_b, _m, b + _m, nb - _m); // if a = no, n/2o + n/2o = (n/2 + 1)o
        copy_b[nb-_m-1] = carry2b;
        // a = 8o, 4+4 = 5o carry is in 5eme octet, [. . . (.)  . . . . ]
        // size of copy_a is _m+1

        unsigned char *p3 = karatsuba(copy_a, _m+2, copy_b, _m+2); // no * no = 2*no

        __sub(copy_p1, sp1, p2, sp2);
        size_t scp1 = max_size(sp1, sp2);
        __sub(p3, sp3, copy_p1, scp1);
  
        free(copy_b);
        free(copy_a);
        free(copy_p1);
        unsigned char *res = (unsigned char *)calloc(nb + na, sizeof(unsigned char));

        __add_off(res, nb + na, p2, sp2, 0);
        __add_off(res, nb + na, p3, sp3, _m);
        __add_off(res, nb + na, p1, sp1, _m*2);


        free(p1);
        free(p2);
        free(p3);

        return res;
    }

    __uint128_t p3, res;
    __uint128_t p1, p2;
    __uint32_t ah, al, bh, bl;

    ah = (a[0] << 8) | a[1];
    al = (a[2] << 8) | a[3];
    bh = (b[0] << 8) | b[1];
    bl = (b[2] << 8) | b[3];

    p1 = ah * bh;
    p2 = al * bl;
    p3 = (ah + al) * (bh + bl);
    res = p2 + ((p3 - p1 - p2) << 16) + (p1 << 32);
    
    unsigned char *c = (unsigned char *)calloc(8, sizeof(unsigned char));
    for (int i = 8 - 1; i >= 0; i--)
    {
        c[i] = res & 0xFF;
        res = res >> 8;
    }
    return c;
}

unsigned char __add_off(unsigned char *a, size_t na, unsigned char *b, size_t nb, size_t offset)
{
    unsigned char carry = 0, o1, o2, o3;
    unsigned short sum;

    size_t length = na > nb ? nb : na;

    for (size_t i = 0; i < length; i++)
    {
        o1 = a[na - i - 1 - offset];
        o2 = b[nb - i - 1];

        sum = o1 + o2 + carry;
        o3 = sum & 0xFF;
        carry = sum >> 8;
        a[na - i - 1 - offset] = o3;
    }
    return carry;
}

// return a and modify a
unsigned char __add(unsigned char *a, size_t na, unsigned char *b, size_t nb)
{
    return __add_off(a, na, b, nb, 0);
}

unsigned char __sub(unsigned char *a, size_t na, unsigned char *b, size_t nb)
{
    unsigned char *copy = clone_arr(b, nb);
    cmp2(copy, nb);
    unsigned char carry = __add(a, na, copy, nb);
    free(copy);
    return carry;
}