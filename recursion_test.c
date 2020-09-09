#include <assert.h> /* assert */
#include <stdlib.h> /* malloc */
#include <stdio.h> /* fprintf */
#include <string.h> /*strcpy */

#include "recurssion.h"



#define TEST(real,expected) (real == expected ? printf("%d, Pass\n", expected) : printf("%d, Fail\n",expected))

#define RED	printf("\033[1;31m")
#define BLUE printf("\033[1;36m")
#define MAGENTA printf("\033[1;35m")
#define YELLOW printf("\033[1;33m")
#define DEFAULT	printf("\033[0m")


int main()
{
    int element = 0;
    int element_index = 6;
    node_t *node1;
    node_t *node2;
    node_t *node3;
    node_t *node4;
    size_t ctr = 0;
    int arr[]={1,4,7,3,8};
    int cmp = 0;
    char dest[] = "hello";
    char *destcat = NULL;
    char *p = NULL;
    stack_t *stack = NULL;
    int status = 0;


    destcat = (char*)malloc(20);

    strcpy(destcat, "hellotoyou");

    element = FibonacciIter(element_index);
    TEST(element, 8);
    element = FibonacciRec(element_index);
    TEST(element, 8);

    node1 = malloc(sizeof(node_t));
    node1->data = 1;
    node2 = InsertAfter(node1, 2);
    node3 = InsertAfter(node2, 3);
    node4 = InsertAfter(node3, 4);

    printf ("the data next to node 3 is: %d\n\n", node3->next->data);
    TEST(node3->next->data, 4);

    FlipList(node1);

    printf ("the data next to node 3 after flip is: %d\n\n", node3->next->data);
    TEST(node3->next->data, 2);

    ctr = recStrlen("hello");
    printf("\nctr is %ld\n", ctr);
    TEST(ctr, 5);

    cmp = recStrcmp("hi", "hello");
    printf("cmp is %d\n", cmp);
    TEST(cmp, -4);

    cmp = recStrcmp("hi", "hi");
    printf("cmp is %d\n", cmp);
    TEST(cmp, 0);


    recStrcpy(dest, "hi");
    printf("dest after strcpy is %s\n", dest);

    recstrcat(destcat, "hooo");
    printf("dest after strcat is %s\n", destcat);

    cmp = recStrncmp("hemmo", "hello", 2);
    printf("cmp is %d\n", cmp);

    p = recstrstr("hi shahar how are you?", "how");
    printf("First occurrence of string is %s\n", p); 

    p = recstrstr("hishaharhowareyou", "false");
    printf("First occurrence of string is %s\n", p); 

    stack = StackCreate(10);
    if(stack == NULL)
	{
		printf("Error. Allocation was unsuccessful. \n");
		exit(1);
	}
	
    status = StackPush(stack, &arr[0]);
    status = StackPush(stack,&arr[1]);
    status = StackPush(stack,&arr[2]);
    status = StackPush(stack, &arr[3]);
	printf("top value is: %d \n", *(int *)StackPeek(stack));

    Stacksort(stack);

	printf("top value is: %d \n", *(int *)StackPeek(stack));


    StackDestroy(stack); 

    return 0;
}