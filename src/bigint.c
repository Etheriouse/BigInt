#include <stdio.h>
#include <stdlib.h>

#include "bigint.h"
#include "bitlib.h"
#include "linkedlist.h"
#include "macro.h"
#include "string.h"
#include "double_dabble.h"

void free_char_linked_list_dd(void *element)
{
    free(element);
}

bInt *new_int(unsigned int size, bool _signed)
{
    bInt *tmp = (bInt *)malloc(sizeof(bInt));
    if (tmp == NULL)
        return NULL;
    tmp->n_bytes = size;

    tmp->bytes = (unsigned char *)calloc(tmp->n_bytes, sizeof(unsigned char));

    if (tmp->bytes == NULL)
    {
        free(tmp);
        return NULL;
    }

    tmp->_signed = _signed;
    return tmp;
}

void free_int(bInt **n)
{
    CHECK_NOT_NULL_VOID(n);
    CHECK_NOT_NULL_VOID(*n);
    free((*n)->bytes);
    (*n)->bytes = NULL;
    free(*n);
    *n = NULL;
}

void __print_bit_i(bInt *n, char *buffer, size_t buffer_s)
{
    size_t offset = 0;
    unsigned char value;
    offset += snprintf(buffer + offset, buffer_s - offset, "%dbit number:\n", n->n_bytes * 8);
    for (int i = 0; i < n->n_bytes; i++)
    {
        value = n->bytes[i];
        for (int j = 0; j < 8; j++)
        {
            offset += snprintf(buffer + offset, buffer_s - offset, "%d", (value >> 7) & 0x1); // decale de 7 sur la droite, puis mask pour obtenir last bit
            value = value << 1;                                                               // decale la valeur vers la gauche de 1
        }
        offset += snprintf(buffer + offset, buffer_s - offset, " ");
    }
}

void print_bit_i(bInt *n)
{
    CHECK_NOT_NULL_VOID(n);
    size_t size = 12 + 3 + n->n_bytes * 9;
    char buffer[size];
    __print_bit_i(n, buffer, size);
    printf("%s\n", buffer);
}

void print_dec_i(bInt *n)
{
    int neg = (n->bytes[0] & 0x80) != 0;
    unsigned char *copy = clone_arr(n->bytes, n->n_bytes);
    if (neg && n->_signed)
    {
        cmp2(copy, n->n_bytes);
    }
    linked_list *l_dec = create_list();
    unsigned int length = __double_dabble(copy, n->n_bytes, l_dec);
    link_node *current = *l_dec;

    char str[(length * 2) + (neg ? 1 : 0)];
    memset(str, 0, sizeof(str));

    while (current != null)
    {
        unsigned char first_digit = *((unsigned char *)current->data) & 0x0F;
        unsigned char snd_digit = (*((unsigned char *)current->data) >> 4) & 0x0F;
        char _1 = bin2dec(first_digit); // unit
        char _2 = bin2dec(snd_digit);   // diz

        memmove(&str[2], &str[0], strlen(str) + 1);
        str[0] = _2;
        str[1] = _1;
        current = current->next;
    }
    if (neg && n->_signed)
    {
        memmove(&str[1], &str[0], strlen(str) + 1);
        str[0] = '-';
    }
    free_list(l_dec, free_char_linked_list_dd);
    free(copy);
    printf("%s\n", str);
}

void set_value(bInt *n, int value)
{
    CHECK_NOT_NULL_VOID(n);

    for (int i = n->n_bytes - 1; i >= 0; i--)
    {
        n->bytes[i] = value & 0xFF; // chope le dernier octet
        value = value >> 8;         // decale vers la droite pour passer a l'octet suivant
    }
}

void set_lvalue(bInt *n, long value)
{
    CHECK_NOT_NULL_VOID(n);

    for (int i = n->n_bytes - 1; i >= 0; i--)
    {
        n->bytes[i] = value & 0xFF; // chope le dernier octet
        value = value >> 8;         // decale vers la droite pour passer a l'octet suivant
    }
}

void set_llvalue(bInt *n, long long value)
{
    CHECK_NOT_NULL_VOID(n);

    for (int i = n->n_bytes - 1; i >= 0; i--)
    {
        n->bytes[i] = value & 0xFF; // chope le dernier octet
        value = value >> 8;         // decale vers la droite pour passer a l'octet suivant
    }
}

int get_int(bInt *n)
{
    CHECK_NOT_NULL_INT(n);

    int val = 0;
    for (int i = 0; i < n->n_bytes; i++)
    {
        val = (val << 8) | n->bytes[i];
    }

    return val;
}

long get_long(bInt *n)
{
    CHECK_NOT_NULL_INT(n);

    long val = 0;
    for (int i = 0; i < n->n_bytes; i++)
    {
        val = (val << 8) | n->bytes[i];
    }

    return val;
}

long long get_llong(bInt *n)
{
    CHECK_NOT_NULL_INT(n);

    long long val = 0;
    for (int i = 0; i < n->n_bytes; i++)
    {
        val = (val << 8) | n->bytes[i];
    }

    return val;
}

void set_uvalue(bInt *n, unsigned int value)
{
    CHECK_NOT_NULL_VOID(n);

    for (int i = n->n_bytes - 1; i >= 0; i--)
    {
        n->bytes[i] = value & 0xFF; // chope le dernier octet
        value = value >> 8;         // decale vers la droite pour passer a l'octet suivant
    }
}

void set_ulvalue(bInt *n, unsigned long value)
{
    CHECK_NOT_NULL_VOID(n);

    for (int i = n->n_bytes - 1; i >= 0; i--)
    {
        n->bytes[i] = value & 0xFF; // chope le dernier octet
        value = value >> 8;         // decale vers la droite pour passer a l'octet suivant
    }
}

void set_ullvalue(bInt *n, unsigned long long value)
{
    CHECK_NOT_NULL_VOID(n);

    for (int i = n->n_bytes - 1; i >= 0; i--)
    {
        n->bytes[i] = value & 0xFF; // chope le dernier octet
        value = value >> 8;         // decale vers la droite pour passer a l'octet suivant
    }
}

unsigned int get_uint(bInt *n)
{
    CHECK_NOT_NULL_INT(n);

    unsigned int val = 0;
    for (int i = 0; i < n->n_bytes; i++)
    {
        val = (val << 8) | n->bytes[i];
    }

    return val;
}

unsigned long get_ulong(bInt *n)
{
    CHECK_NOT_NULL_INT(n);

    unsigned long val = 0;
    for (int i = 0; i < n->n_bytes; i++)
    {
        val = (val << 8) | n->bytes[i];
    }

    return val;
}

unsigned long long get_ullong(bInt *n)
{
    CHECK_NOT_NULL_INT(n);

    unsigned long long val = 0;
    for (int i = 0; i < n->n_bytes; i++)
    {
        val = (val << 8) | n->bytes[i];
    }

    return val;
}

// take a and add b into, so a is modified
int add_bint(bInt *a, bInt *b)
{
    CHECK_NOT_NULL_INT(a);
    CHECK_NOT_NULL_INT(b);

    unsigned char carry = 0, o1, o2, o3;
    unsigned short sum;

    int length = a->n_bytes > b->n_bytes ? b->n_bytes : a->n_bytes;

    for (int i = 0; i < length; i++)
    {
        o1 = a->bytes[a->n_bytes - i - 1];
        o2 = b->bytes[b->n_bytes - i - 1];

        sum = o1 + o2 + carry;
        o3 = sum & 0xFF;
        carry = sum >> 8;
        a->bytes[a->n_bytes - i - 1] = o3;
    }
    return carry;
}

void sub_bint(bInt *a, bInt *b)
{
    unsigned char* copy = clone_arr(b->bytes, b->n_bytes);
    cmp2(copy, b->n_bytes);
    bInt tmp = {copy, b->n_bytes, b->_signed};
    add_bint(a, &tmp);
    free(copy);
}