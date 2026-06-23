#ifndef BITLIB_H
#define BITLIB_H

static inline void set_n_bit(unsigned char *c, unsigned char n, unsigned int pos)
{
    *c = (*c & ~(1 << pos)) | (n << pos);
}

static inline void set_1_bit(unsigned char *c, unsigned int pos)
{
    *c |= (1 << pos);
}

static inline void set_0_bit(unsigned char *c, unsigned int pos)
{
    *c &= ~(1 << pos);
}

static inline char bin2dec(unsigned char digit)
{
    switch (digit)
    {
    case 0x0:
        return '0';
    case 0x1:
        return '1';
    case 0x2:
        return '2';
    case 0x3:
        return '3';
    case 0x4:
        return '4';
    case 0x5:
        return '5';
    case 0x6:
        return '6';
    case 0x7:
        return '7';
    case 0x8:
        return '8';
    case 0x9:
        return '9';
    default:
        return '0';
    }
}

static inline void cmp2(unsigned char *bytes, size_t n_bytes)
{
    for (size_t i = 0; i < n_bytes; i++)
    {
        bytes[i] = ~bytes[i];
    }
    unsigned int carry = 1, res;
    for (int i = n_bytes-1; i >=0 && carry; i--)
    {
        res = bytes[i] + carry;
        bytes[i] = res & 0xFF;
        carry = res >> 8; // Retenue pour l'octet suivant
    }
}

static inline unsigned char *clone_arr(unsigned char *bytes, size_t n_bytes)
{
    unsigned char *c = (unsigned char *)calloc(n_bytes, sizeof(unsigned char));
    for (size_t i = 0; i < n_bytes; i++)
    {
        c[i] = bytes[i];
    }
    return c;
}

static inline unsigned char *clone_p_arr(unsigned char *bytes, size_t start, size_t n_bytes)
{
    unsigned char *c = (unsigned char *)calloc(n_bytes, sizeof(unsigned char));
    for (size_t i = start; i < n_bytes; i++)
    {
        c[i] = bytes[i-start];
    }
    return c;
}

static inline size_t max_size(size_t a, size_t b) {
    return a>b?a:b;
}

#endif