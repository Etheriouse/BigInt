#ifndef DOUBlE_DABBLE_H
#define DOUBlE_DABBLE_H

#include "linkedlist.h"
#include "macro.h"

#include <stdio.h>
#include <stdlib.h>

unsigned char shift_array(unsigned char *bytes, size_t size);
unsigned char shift_linked_list(linked_list *l_dec);
unsigned int __double_dabble(unsigned char *bytes, size_t nb_bytes, linked_list *l_dec);

#endif