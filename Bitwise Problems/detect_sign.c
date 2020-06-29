#if 1
#include <stdio.h>
#include <stdbool.h>

#include "/Users/tejeshwarchandrakamaal/Documents/sublime_coding_practise/print/print.h"

typedef enum method 
{
	METHOD_1 = 0,
	METHOD_2 = 1,
	METHOD_3 = 2
}t_method;


bool bCheckIfVariablesHaveOppSign(t_method, int, int);


bool bCheckIfVariablesHaveOppSign(t_method type, int x, int y)
{
	if(type == METHOD_1)
	{
		printf(KCYN"");
		printf("%s : ", (type == 0)? "METHOD_1" : (type==1) ? "METHOD_2": "METHOD_3");

		return ((x^y) < 0); 
	}
	else if(type == METHOD_2)
	{
		printf(KYEL "");
		printf("%s : ", (type == 0)? "METHOD_1" : (type==1) ? "METHOD_2": "METHOD_3");

		return ((x < 0) ? (y >= 0) : (y < 0));
	}
	else if(type == METHOD_3)
	{
		printf(KGRN"");
		printf("%s : ", (type == 0)? "METHOD_1" : (type==1) ? "METHOD_2": "METHOD_3");

		return ((x ^ y) >> 31);
	}
	else 
	{
		printf("Undefined type\r\n");
		return false;
	}
}

int main(void)
{
	int x = 100;
	int y = -1;

	t_method type1 = METHOD_1;
	printf("%d\n" KNRM, bCheckIfVariablesHaveOppSign(type1, x, y));

	x = 100; y =10;
	t_method type2 = METHOD_2;
	printf("%d\n" KNRM, bCheckIfVariablesHaveOppSign(type2, x, y));

	t_method type3 = METHOD_3;
	printf("%d\n" KNRM, bCheckIfVariablesHaveOppSign(type3, x, y));

	return 0;
}

#endif 
