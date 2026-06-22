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

static inline char bin2dec(unsigned char digit) {
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

unsigned char shift_array(unsigned char *bytes, size_t size);
unsigned char shift_linked_list(linked_list *l_dec);
unsigned int __double_dabble(unsigned char *bytes, size_t nb_bytes, linked_list *l_dec);

#endif