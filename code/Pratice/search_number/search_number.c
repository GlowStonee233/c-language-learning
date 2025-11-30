//这是一个寻找水仙花数的程序
#include<stdio.h>
int istrue(long long a, int N);
long long fast_pow(long long base, unsigned int exp); 
int main()
{
	int N = 0;
	long long i;
	scanf("%d", &N);
	for (i = fast_pow(10, N - 1); i < fast_pow(10, N); i++)
	{
		if (istrue(i, N))
			printf("%lld\n", i);
	}
	printf("End of Output\n");
    return 0;
}
int istrue(long long a, int N)
{
	long long p = 0;
	long long temp = a;
	while (temp > 0)
	{
		int b = temp % 10;
		p = p + fast_pow(b, N);
		temp = temp / 10;
	}	
	return (p == a);
}
long long fast_pow(long long base, unsigned int exp) 
{
    long long result = 1;
    while (exp > 0) 
	{
        if (exp & 1) 
		{           
            result *= base;
        }
        base *= base;            
        exp=exp/2;          
    }
    return result;
}
