#include <stdio.h>

void karatsuba(unsigned char *a, size_t na, unsigned char *b, size_t nb)
{
    size_t mid_a = na / 2;
    size_t mid_b = nb / 2;

    if (na > 2 && nb > 2)
    {
        karatsuba(a, mid_a, a + mid_a + 1, na - mid_a);
        karatsuba(b, mid_b, b + mid_b + 1, nb - mid_b);
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