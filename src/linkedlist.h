#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @brief Structure representing a single node in the linked list.
 */
typedef struct link_node {
    void *data;               /**< Generic pointer to the stored data */
    struct link_node *next;   /**< Pointer to the next node, NULL if it's the last node */
    unsigned int length;
} link_node;

/**
 * @brief Type definition for the linked list (pointer to the first node).
 */
typedef link_node* linked_list;

/**
 * @brief Creates and initializes a new empty linked list.
 * @return A pointer to the created list (initialized to NULL), or NULL if memory allocation fails.
 */
linked_list* create_list();

/**
 * @brief Frees all the memory allocated for the linked list nodes and optionally its data.
 * * @details This function iterates through the list to free each node structure. 
 * If a custom clean-up function pointer (`free_data`) is provided, it will be called 
 * on each node's generic data pointer before the node itself is freed.
 * The list pointer will be safely set to NULL at the end.
 * * @note 
 * - Pass `free` as the second argument if your data was dynamically allocated via malloc.
 * - Pass `NULL` if your data points to static memory, stack variables, or array elements 
 * that should not be freed.
 * * @param list      Pointer to the linked list to free.
 * @param free_data Pointer to a custom function to free the node's data, or NULL to skip freeing data.
 */
void free_list(linked_list *list, void (*free_data)(void*));

/**
 * @brief Inserts a new element at the end of the list.
 * @param list Pointer to the linked list.
 * @param data Pointer to the data to be stored.
 */
void push(linked_list *list, void *data);

/**
 * @brief Removes and returns the element at the end of the list.
 * @param list Pointer to the linked list.
 * @return A pointer to the node of the removed element, or NULL if the list is empty.
 */
link_node *pop(linked_list *list);

/**
 * @brief Prints the contents of the list (primarily used for debugging purposes).
 * @param list Pointer to the linked list to print.
 */
void print_list(linked_list *list, void(*print) (void*));

/**
 * @brief Sorts the linked list using a custom comparison function.
 * @param list Pointer to the linked list to sort.
 * @param cmp Pointer to the comparison function. It must return a negative integer if a < b, 
 * 0 if a == b, and a positive integer if a > b.
 */
void sort_list(linked_list *list, int (*cmp) (void*, void*));

/**
 * @brief Retrieves the data from a node at a specific index in the list.
 * @param list Pointer to the linked list.
 * @param index The position of the element to retrieve.
 * @return A generic pointer to the data at the specified index, or NULL if the index is out of bounds.
 */
void *get_list(linked_list *list, unsigned int index);

/**
 * @brief Inserts a new element at a specific index in the list.
 * @param list Pointer to the linked list.
 * @param index The position where the new element should be inserted.
 * @param data Pointer to the data to be stored.
 */
void insert_list(linked_list *list, unsigned int index, void *data);

#endif