#include <assert.h> /* assert */
#include <stdlib.h> /* malloc */
#include <stdio.h> /* fprintf */
#include <stddef.h> /* size_t */

#include "stack.h"

#include "recurssion.h"

static size_t Strlen(const char *str, size_t ctr);
static char *Strcpyhelp(char *dest, const char *src, int ctr);
static char *Strcathelp(char *dest, const char *src, size_t ctr, int len);
static int Strncmphelp(const char *s1, const char *s2, size_t n, size_t ctr);
static char *recstrstrhelp(const char *haystack, const char *needle, size_t len );
node_t *FlipListRec(node_t *prev, node_t *curr);



int FibonacciIter(int element_index)
{
    size_t i = 0;
    int element_0 = 0;
    int element_1 = 1;
    int element_3 = 0;
    
    for(i=1; i<element_index; i++)
    {
        element_3 = element_0 + element_1;
        element_0 = element_1;
        element_1 = element_3;
    }    

    return element_3;
}

int FibonacciRec(int element_index)
{
    if(element_index <= 1)
    {
        return element_index;
    }

    return FibonacciRec(element_index - 1) + FibonacciRec(element_index -2);
}


/******************** list ************************/


/* node_t *FlipList(node_t *node)
{
    node_t *next;
    static node_t *prev = NULL;

    if (NULL == node)
    {
        return prev;
    }

    next = node->next;
    node->next = prev;
    prev = node;
    node = next;

    return FlipList(node);
}
 */
node_t *FlipList(node_t *node)
{
    node_t *prev = NULL;
    node_t *curr = node;

    return FlipListRec(prev, node);
}

node_t *FlipListRec(node_t *prev, node_t *curr)
{
    node_t *next = NULL;

    if(curr->next == NULL)
    {
        curr->next = prev;
        return curr;
    }

    next = curr->next;
    curr->next = prev;

    return FlipListRec(curr, next);
}


node_t *InsertAfter(node_t *node, int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    new_node->data = data;

    node->next = new_node;
    return new_node;
}

/******************** str ************************/
size_t recStrlen(const char *str)
{
    size_t ctr = 0;

    return Strlen(str, ctr);
}


static size_t Strlen(const char *str, size_t ctr)
{
    if(*str == '\0')
    {
        return ctr ;
    }
    return Strlen(str + 1, ctr + 1);
}



int recStrcmp(const char *s1, const char *s2)
{
    if(*s2 - *s1 != 0 || *s2 == '\0')
    {
        return *s2-*s1;
    }

    return recStrcmp(s1+1, s2+1);
}


char *recStrcpy(char *dest, const char *src)
{
    int index = 0;

    return Strcpyhelp(dest, src, index);
}

static char *Strcpyhelp(char *dest, const char *src, int index)
{
    if(*src == '\0')
    {
        *dest = '\0';
        return dest - index;
    }
    *dest = *src;
    return Strcpyhelp(dest + 1, src + 1, index+1);
}


char *recstrcat(char *dest, const char *src)
{
    int len = recStrlen(dest);

    dest[len] = *src;

    if(*src == '\0')
    {
        dest[len] = '\0';
        return dest;
    }

    return recstrcat(dest+ 1 , src +1);
}
  /*
 
char *recstrcat(char *dest, const char *src)
{
    size_t ctr = 0;

    int len = recStrlen(dest);

    return Strcathelp(dest, src, ctr, len);
}


static char *Strcathelp(char *dest, const char *src, size_t ctr, int len)
{
    if(src[ctr] == '\0')
    {
        dest[len + ctr] = '\0';
        return dest;
    }

    dest[len + ctr] = src[ctr];
    return Strcathelp(dest, src, ctr+1, len);
}
 */

/* int recStrncmp(const char *s1, const char *s2, size_t n)
{

    if(*s2 - *s1 != 0 || n > 0)
    {
        return *s2-*s1;
    }

     return recStrncmp(s1+1, s2+1, n-1);

} */

int recStrncmp(const char *s1, const char *s2, size_t n)
{
    size_t ctr = 1;

     return Strncmphelp(s1, s2, n , ctr);

}

static int Strncmphelp(const char *s1, const char *s2, size_t n, size_t ctr)
{
    if(*s2 - *s1 != 0 || ctr == n)
    {
        return *s2-*s1;
    }

    return Strncmphelp(s1+1, s2+1, n , ctr+1);

}


char *recstrstr(const char *haystack, const char *needle)
{
    size_t len = recStrlen(needle);

    if(recStrncmp(haystack, needle, len) == 0)
    {
        return (char*)haystack;
    }
    if(*haystack == '\0')
    {
        return NULL;
    }
    
    return recstrstr(haystack +1, needle);
}
/* char *recstrstr(const char *haystack, const char *needle)
{

    size_t len = recStrlen(needle);

    return recstrstrhelp(haystack, needle, len );
}

static char *recstrstrhelp(const char *haystack, const char *needle, size_t len )
{

    if(*haystack == '\0')
    {
        return NULL;
    }

    if(recStrncmp(haystack , needle, len) == 0)
    {
        return (char*)haystack;
    }

    return recstrstrhelp(haystack +1, needle, len );
} */


/******************** stack ************************/

void Stacksort(stack_t *stack)
{
    int *x = 0;

    if(!StackIsEmpty(stack))
    {
        /* remove top item */
        x = (int*)StackPeek(stack);
        StackPop(stack);
        
        /*sort remaining stack */
        Stacksort(stack);

        /*push the top item back in sorted stack */
        SortInsert(stack, x);
    }
}

void SortInsert(stack_t *stack, int *x)
{
     int *tmp = 0;

    if(*x > *(int*)StackPeek(stack) || StackIsEmpty(stack))
    {
        StackPush(stack, x);
        return;
    }

    tmp = (int*)StackPeek(stack);
    StackPop(stack);

    SortInsert(stack, x);
    StackPush(stack, tmp);
}
 
/* 
     if(StackIsEmpty(stack) || *x > *(int*)StackPeek(stack))
    {
        StackPush(stack, x);
        return;
    }
    
    tmp = (int*)StackPeek(stack);
    StackPop(stack); */

    /* push the top item back in sorted stack */
    /*  SortInsert(stack, x);  */

    /*put back the top item */
    /* StackPush(stack, tmp); 

}  */