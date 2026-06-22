#ifndef __MACRO_H
#define __MACRO_H

#define CHECK_NOT_NULL_VOID(ptr)                                                                               \
    do                                                                                                         \
    {                                                                                                          \
        if ((ptr) == NULL)                                                                                     \
        {                                                                                                      \
            fprintf(stderr, "[CRITICAL] '%s' is NULL in %s() at %s:%d\n", #ptr, __func__, __FILE__, __LINE__); \
            return;                                                                                            \
        }                                                                                                      \
    } while (0)

#define CHECK_NOT_NULL_PTR(ptr)                                                                                \
    do                                                                                                         \
    {                                                                                                          \
        if ((ptr) == NULL)                                                                                     \
        {                                                                                                      \
            fprintf(stderr, "[CRITICAL] '%s' is NULL in %s() at %s:%d\n", #ptr, __func__, __FILE__, __LINE__); \
            return NULL;                                                                                         \
        }                                                                                                      \
    } while (0)

#define CHECK_NOT_NULL_INT(ptr)                                                                                \
    do                                                                                                         \
    {                                                                                                          \
        if ((ptr) == NULL)                                                                                     \
        {                                                                                                      \
            fprintf(stderr, "[CRITICAL] '%s' is NULL in %s() at %s:%d\n", #ptr, __func__, __FILE__, __LINE__); \
            return -1;                                                                                         \
        }                                                                                                      \
    } while (0)

#define UNUSED(x) (void)(x)
#define null NULL


#endif