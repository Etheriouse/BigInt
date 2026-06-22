#include "bint_test.h"
#include "../debugbigint.h"
#include <stdio.h>
#include <string.h>

int i_create_test()
{
    bInt *x = new_int(8);
    if(x->n_bytes != 8) return -1;
    free_int(&x);

    x = new_int(0);
    if(x->n_bytes != 0) return -1;
    free_int(&x);
    return 0;
}
int i_set_test()
{
    bInt *x = new_int(8);
    if(x->n_bytes != 8) return -1;
    set_lvalue(x, 987818343504L);
    if(x->bytes[3] != 229) return -1;
    if(x->bytes[4] != 254) return -1;
    if(x->bytes[5] != 143) return -1;
    if(x->bytes[6] != 188) return -1;
    if(x->bytes[7] != 80) return -1;

    set_value(x, 687865883);
    if(x->bytes[4] != 41) return -1;
    if(x->bytes[7] != 27) return -1;


    set_value(x, -1627891);
    if(x->bytes[0] != 255) return -1;
    if(x->bytes[1] != 255) return -1;
    if(x->bytes[2] != 255) return -1;
    if(x->bytes[3] != 255) return -1;
    if(x->bytes[4] != 255) return -1;
    if(x->bytes[5] != 231) return -1;
    if(x->bytes[6] != 41) return -1;
    if(x->bytes[7] != 13) return -1;

    free_int(&x);
    return 0;
}
int i_get_test()
{
    bInt *x = new_int(8);
    set_value(x, 1843);
    if(get_int(x) != 1843) return -1;

    set_value(x, 0);
    if(get_int(x) != 0) return -1;

    set_value(x, -124);
    if(get_int(x) != -124) return -1;

    set_value(x, -1);
    if(get_int(x) != -1) return -1;

    free_int(&x);
    return 0;
}
int i_print_test()
{
    bInt *n = new_int(4);
    set_value(n, 156);
    
    size_t size = 12 + 3 + n->n_bytes * 9;
    char buffer[size];
    __print_bit_i(n, buffer, size);

    const char *att_res = "32bit number:\n00000000 00000000 00000000 10011100 ";
    if(strcmp(buffer, att_res) != 0) return -1;

    free_int(&n);
    return 0;
}
int i_free_test()
{
    bInt *n = new_int(4);
    free_int(&n);
    if(n != NULL) return -1;
    return 0;
}

int ui_create_test()
{ 
    bUInt *x = new_uint(8);
    if(x->n_bytes != 8) return -1;
    free_uint(&x);

    x = new_uint(0);
    if(x->n_bytes != 0) return -1;
    free_uint(&x);
    return 0;
}
int ui_set_test()
{
    bUInt *x = new_uint(8);
    if(x->n_bytes != 8) return -1;
    set_ulvalue(x, 987818343504L);
    if(x->bytes[3] != 229) return -1;
    if(x->bytes[4] != 254) return -1;
    if(x->bytes[5] != 143) return -1;
    if(x->bytes[6] != 188) return -1;
    if(x->bytes[7] != 80) return -1;

    set_uvalue(x, 687865883);
    if(x->bytes[4] != 41) return -1;
    if(x->bytes[7] != 27) return -1;


    set_uvalue(x, -1627891);
    if(x->bytes[0] != 0) return -1;
    if(x->bytes[1] != 0) return -1;
    if(x->bytes[2] != 0) return -1;
    if(x->bytes[3] != 0) return -1;
    if(x->bytes[4] != 255) return -1;
    if(x->bytes[5] != 231) return -1;
    if(x->bytes[6] != 41) return -1;
    if(x->bytes[7] != 13) return -1;

    free_uint(&x);
    return 0;
}
int ui_get_test()
{
    bUInt *x = new_uint(8);
    set_uvalue(x, 1843);
    if(get_uint(x) != 1843) return -1;

    set_uvalue(x, 0);
    if(get_uint(x) != 0) return -1;

    set_uvalue(x, -124);
    if(get_uint(x) != 0xFFFFFF84) return -1;

    set_uvalue(x, -1);
    if(get_uint(x) != 0xFFFFFFFF) return -1;

    free_uint(&x);
    return 0;
}
int ui_print_test()
{
    bUInt *n = new_uint(4);
    set_uvalue(n, 156);
    
    size_t size = 12 + 3 + n->n_bytes * 9;
    char buffer[size];
    __print_bit_ui(n, buffer, size);

    const char *att_res = "32bit number:\n00000000 00000000 00000000 10011100 ";
    if(strcmp(buffer, att_res) != 0) return -1;

    free_uint(&n);
    return 0;
}
int ui_free_test()
{
    bUInt *n = new_uint(4);
    free_uint(&n);
    if(n != NULL) return -1;
    return 0;
}

void main_test()
{
    printf("No message say, test good\n");
    printf("=============== start test ===============\n");
    if (i_create_test())
    {
        perror("create bInt test don't pass\n");
    }
    if (ui_create_test())
    {
        perror("create bUInt test don't pass\n");
    }
    if (i_free_test())
    {
        perror("free bInt test don't pass\n");
    }
    if (ui_free_test())
    {
        perror("free bUInt test don't pass\n");
    }
    if (i_set_test())
    {
        perror("set bInt test don't pass\n");
    }
    if (ui_set_test())
    {
        perror("set bUInt test don't pass\n");
    }
    if (i_get_test())
    {
        perror("get bInt test don't pass\n");
    }
    if (ui_get_test())
    {
        perror("get bUInt test don't pass\n");
    }
    if (i_print_test())
    {
        perror("print bInt test don't pass\n");
    }
    if (ui_print_test())
    {
        perror("print bUInt test don't pass\n");
    }
    printf("=============== end test ===============\n");
}