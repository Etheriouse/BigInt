#ifndef BIGINT_H
#define BIGINT_H

#include "linkedlist.h"

/**
 * @struct bUInt
 * @brief Represents an unsigned integer of custom bit-length.
 */
typedef struct
{
    unsigned char *bytes; /**< Raw byte array storing the data in memory. */
    int n_bytes;          /**< Exact size of the integer measured in bits. */
} bUInt;

/**
 * @struct bInt
 * @brief Represents a signed integer of custom bit-length.
 */
typedef struct
{
    unsigned char *bytes; /**< Raw byte array storing the data in memory. */
    int n_bytes;          /**< Exact size of the integer measured in bits. */
} bInt;

/**
 * @brief Allocates and initializes a new signed arbitrary-precision integer (bInt).
 * @param size Target number of bytes for this integer.
 * @return A pointer to the allocated bInt structure, or NULL if allocation fails.
 */
bInt *new_int(unsigned int size);

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

/**
 * @brief Allocates and initializes a new unsigned arbitrary-precision integer (bUInt).
 * @param size Target number of bytes for this integer.
 * @return A pointer to the allocated bUInt structure, or NULL if allocation fails.
 */
bUInt *new_uint(unsigned int size);

/**
 * @brief Safely deallocates the memory used by a bUInt structure and its internal byte array.
 * @param n Pointer to the unsigned integer structure to free.
 */
void free_uint(bUInt **n);

/**
 * @brief Prints the binary representation (0s and 1s) of the bUInt to the standard output.
 * @param n Pointer to the unsigned integer to display.
 */
void print_bit_ui(bUInt *n);

/**
 * @brief Stores a standard unsigned integer value into the bUInt structure.
 * @param n Pointer to the destination unsigned integer.
 * @param value The unsigned int value to assign.
 */
void set_uvalue(bUInt *n, unsigned int value);

/**
 * @brief Stores a standard unsigned long integer value into the bUInt structure.
 * @param n Pointer to the destination unsigned integer.
 * @param value The unsigned long value to assign.
 */
void set_ulvalue(bUInt *n, unsigned long value);

/**
 * @brief Extracts the value from the bUInt and converts it into a standard unsigned int.
 * @param n Pointer to the unsigned integer to read.
 * @return The extracted value converted to a standard unsigned int.
 */
unsigned int get_uint(bUInt *n);

/**
 * @brief Extracts the value from the bUInt and converts it into a standard unsigned long.
 * @param n Pointer to the unsigned integer to read.
 * @return The extracted value converted to a standard unsigned long.
 */
unsigned long get_ulong(bUInt *n);

// return overflow
int add_int(bInt *a, bInt *b);
void sub_int(bInt *a, bInt *b);


#endif