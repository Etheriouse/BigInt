#include "double_dabble.h"

unsigned char shift_array(unsigned char *bytes, size_t size)
{
    unsigned char last_carry = 0;
    unsigned char carry = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        carry = (bytes[i] & 0x80) >> 7;
        bytes[i] = bytes[i] << 1;
        bytes[i] += last_carry;
        last_carry = carry;
    }
    return last_carry;
}


unsigned char shift_linked_list(linked_list *l_dec)
{
    unsigned char last_carry = 0;
    unsigned char carry = 0;
    link_node *current = *l_dec;
    while (current != null)
    {
        unsigned char bytes = *((unsigned char *)current->data);
        carry = (bytes & 0x80) >> 7;
        bytes = bytes << 1;
        bytes += last_carry;
        last_carry = carry;
        *((unsigned char *)current->data) = bytes;
        current = current->next;
    }
    return last_carry;
}


// list of unsigned char, one char eq 2 digit
unsigned int __double_dabble(unsigned char *bytes, size_t nb_bytes, linked_list *l_dec)
{
    unsigned int len = 1;
    if (*l_dec == null)
    {
        push(l_dec, calloc(1, sizeof(unsigned char)));
    }
    for (size_t i = 0; i < nb_bytes * 8; i++)
    {
        link_node *current = *l_dec;
        while (current != null)
        {
            unsigned char first_digit = *((unsigned char *)current->data) & 0x0F;
            unsigned char snd_digit = (*((unsigned char *)current->data) >> 4) & 0x0F;

            if (first_digit >= 5)
            {
                first_digit += 3;
            }
            if (snd_digit >= 5)
            {
                snd_digit += 3;
            }

            // remettre les digit dans le char de la list;
            unsigned char _2digit = first_digit | (snd_digit << 4);
            *((unsigned char *)current->data) = _2digit;
            current = current->next;
        }

        unsigned char fcarry = shift_array(bytes, nb_bytes);
        unsigned char carry = shift_linked_list(l_dec);
        *((unsigned char *)(*l_dec)->data) += fcarry;
        if (carry)
        {
            unsigned char *tmp = malloc(sizeof(unsigned char));
            *tmp = carry;
            push(l_dec, tmp);
            len+=1;
        }
    }
    return len;
}