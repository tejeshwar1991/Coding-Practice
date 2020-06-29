#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)  
{ 
    int i; 
    for (i = 0; i < n; i++) 
         printf(" %.2x", start[i]); 
    printf("\n"); 
} 

int main(void)
{
	uint32_t u32X = 0x12345678;
	show_mem_rep((char *)&u32X, sizeof(u32X)); 

   unsigned int i = 1; 
   char *c = (char*)&i; 
   if (*c)     
       printf("Little endian\n"); 
   else
       printf("Big endian\n");	
}