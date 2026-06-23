#include <stdio.h>
#include "bitlib.h"

// modify a
void karatsuba(unsigned char *a, size_t na, unsigned char *b, size_t nb)
{

    // call katsubara to do a mul
    size_t mid_a = na / 2;
    size_t mid_b = nb / 2;

    if (na > 2 && nb > 2)
    {
        karatsuba(a, mid_a, b, mid_b); // h*h
        karatsuba(a + mid_a + 1, na - mid_a, b + mid_b + 1, nb - mid_b); // l*l

        // a_h*l + b_h*l


    }

    __uint32_t p3, res;
    __uint16_t p1, p2;
    __uint8_t ah, al, bh, bl;

    al = a[na==1?0:1]; // si na == 1, part basse = 1er octet sinon dernier octet
    bl = b[nb==1?0:1]; // si nb == 1, part basse = 1er octet sinon dernier octet
    ah = na==1?0:a[0]; // si na == 1 part haute = 0, sinon 1er octet
    bh = nb==1?0:b[0]; // si nb == 1 part haute = 0, sinon 1er octet

    p1 = ah*bh;
    p2 = al*bl;
    p3 = (ah+al)*(bh+bl);
    res = p2 + ((p3 - p1 - p2 ) << 1) + (p1 << 2);
}

// return a and modify a
unsigned char * __add(unsigned char *a, size_t na, unsigned char *b, size_t nb) {
    unsigned char carry = 0, o1, o2, o3;
    unsigned short sum;

    size_t length = na > nb ? nb : na;

    for (size_t i = 0; i < length; i++)
    {
        o1 = a[na - i - 1];
        o2 = b[nb - i - 1];

        sum = o1 + o2 + carry;
        o3 = sum & 0xFF;
        carry = sum >> 8;
        a[na - i - 1] = o3;
    }
    return a;
}