#include <stdio.h> 
#include "/Users/tejeshwarchandrakamaal/Documents/sublime_coding_practise/print/print.h"

/**
 * 	The idea is to do following :
	1) Make a local variable in main.
	2) Write another function fun() with its own local variable.
	3) Make a call to fun() from main. Compare addresses of two local variable. 
		If address of fun()’s local variable is more than main’s local variable, 
		then stack grows upward (i.e., addresses increase)

 *	https://www.geeksforgeeks.org/c-program-find-direction-growth-stack/
 */

void checkStack(int *ptr)
{
	int test_1 = 20;

	printf("Main function variable address: %lu\r\n", (unsigned long) ptr);
	printf("%s function local variable address: %lu\r\n", __func__, (unsigned long) &test_1);

	printf(KGRN"");
   	if (ptr < &test_1) 
        printf("Stack grows upward\n"); 
    else
        printf("Stack grows downward\n");	

    printf(KNRM"");

}

int main(void)
{
	int test = 10;
	checkStack(&test);
	return 0;	
}