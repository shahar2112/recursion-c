#ifndef __RECURSSION_H__ 
#define __RECURSSION_H__

#include <stddef.h>

#include "stack.h"
/* #include "linked_list.h" */

typedef struct node node_t;
struct node
{
    int data;
    node_t *next;
};

int FibonacciIter(int element_index);
int FibonacciRec(int element_index);

node_t *FlipList(node_t *node);
node_t *InsertAfter(node_t *node, int data);

size_t recStrlen(const char *str);
int recStrcmp(const char *s1, const char *s2);
char *recStrcpy(char *dest, const char *src);
char *recstrcat(char *dest, const char *src);
int recStrncmp(const char *s1, const char *s2, size_t n);
char *recstrstr(const char *haystack, const char *needle);

void Stacksort(stack_t *stack);
void SortInsert(stack_t *stack, int *x);


#endif