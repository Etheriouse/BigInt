#ifndef BIGINT_H
#define BIGINT_H

#include "linkedlist.h"

typedef int bool;
#define true 1
#define false 0

/**
 * @struct bInt
 * @brief Represents a integer of custom bit-length.
 */
typedef struct
{
    unsigned char *bytes; /**< Raw byte array storing the data in memory. */
    int n_bytes;          /**< Exact size of the integer measured in bits. */
    bool _signed;         /**<  */
} bInt;

/**
 * @brief Allocates and initializes a new signed arbitrary-precision integer (bInt).
 * @param size Target number of bytes for this integer.
 * @return A pointer to the allocated bInt structure, or NULL if allocation fails.
 */
bInt *new_int(unsigned int size, bool _signed);

/**
 * @brief Safely deallocates the memory used by a bInt structure and its internal byte array.
 * @param n Pointer to the signed integer structure to free.
 */
void free_int(bInt **n);

/**
 * @brief Prints the binary representation (0s and 1s) of the bInt to the standard output.
 * @param n Pointer to the signed integer to display.
 */
void print_bit_i(bInt *n);

/**
 * @brief Prints the decimal representation of the bInt to the standard output.
 * @param n Pointer to the signed integer to display.
 */
void print_dec_i(bInt *n);

/**
 * @brief Stores a standard integer value into the bInt structure.
 * @param n Pointer to the destination signed integer.
 * @param value The standard 32-bit int value to assign.
 */
void set_value(bInt *n, int value);

/**
 * @brief Stores a standard long integer value into the bInt structure.
 * @param n Pointer to the destination signed integer.
 * @param value The long value to assign.
 */
void set_lvalue(bInt *n, long value);
void set_llvalue(bInt *n, long long value);

/**
 * @brief Extracts the value from the bInt and converts it into a standard int.
 * @param n Pointer to the signed integer to read.
 * @return The extracted value converted to a standard int.
 */
int get_int(bInt *n);

/**
 * @brief Extracts the value from the bInt and converts it into a standard long.
 * @param n Pointer to the signed integer to read.
 * @return The extracted value converted to a standard long.
 */
long get_long(bInt *n);
long long get_llong(bInt *n);

/**
 * @brief Stores a standard unsigned integer value into the bUInt structure.
 * @param n Pointer to the destination unsigned integer.
 * @param value The unsigned int value to assign.
 */
void set_uvalue(bInt *n, unsigned int value);

/**
 * @brief Stores a standard unsigned long integer value into the bUInt structure.
 * @param n Pointer to the destination unsigned integer.
 * @param value The unsigned long value to assign.
 */
void set_ulvalue(bInt *n, unsigned long value);
void set_ullvalue(bInt *n, unsigned long long value);

/**
 * @brief Extracts the value from the bUInt and converts it into a standard unsigned int.
 * @param n Pointer to the unsigned integer to read.
 * @return The extracted value converted to a standard unsigned int.
 */
unsigned int get_uint(bInt *n);

/**
 * @brief Extracts the value from the bUInt and converts it into a standard unsigned long.
 * @param n Pointer to the unsigned integer to read.
 * @return The extracted value converted to a standard unsigned long.
 */
unsigned long get_ulong(bInt *n);
unsigned long long get_ullong(bInt *n);


// return overflow
int add_bint(bInt *a, bInt *b);


void sub_bint(bInt *a, bInt *b);

// mul d'octet (b256) 0 - 100 
// karatsuba 100-10000
// si signer cmp2 et signer avec xor des bit poid fort remetre en cmp2 si res neg
// fft 10000+
int mul_bint(bInt *a, bInt *b);
void div_bint(bInt *a, bInt *b);

#endif


