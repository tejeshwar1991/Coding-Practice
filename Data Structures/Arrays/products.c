/*=============================================
=           Question          		     =
=============================================*/
// Given an array of numbers, nums, return an array of numbers products, where products[i] is the product of all nums[j], j != i. 
// Input : [1, 2, 3, 4, 5] Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)] = [120, 60, 40, 30, 24] 
// You must do this in O(N) without using division.
/*=====  End of Section comment block  ======*/

#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int arr[5] = {1, 2, 3, 4, 5};

// O(n2)
int* array_products(int arr[], int size)
{
	int *return_array = (int*) malloc(sizeof(int)*size);
	int product = 1;

	for(int i=0; i<size; i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i != j)
			{
				product *= arr[j];
			}
		}

		return_array[i] = product;
		product = 1;
	}

	return return_array;
}

// O(n)
int* array_products_2(int arr[], int size)
{
	int *return_array = (int*) malloc(sizeof(int)*size);
	int product = 1;	


	int i=0,j=0;

	for( ; i<size; j++)
	{
		if((arr[i]^arr[j]) != 0)
		{
			product *= arr[j];

			printf("product: %d, i: [%d], arr[%i]: %d\r\n", product, i, j, arr[j]);
		}

		if(j == (size-1))
		{
			return_array[i] = product;
			printf("array[%d]:%d\r\n", i, return_array[i]);

			j = 0;
			++i;
			product = 1;
		}
	}

	return return_array;
}

int main(void)
{
	int *return_arr = NULL; 
	// return_arr = array_products(arr, (sizeof(arr)/sizeof(arr[0])));

	return_arr = array_products_2(arr, (sizeof(arr)/sizeof(arr[0])));

	for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++)
	{
		printf("arr[%d]:%d\r\n", i, return_arr[i]);
	}

	return 0;
}
