//这是一个优化过的找水仙花数的程序，对算法进行微调
#include <stdio.h>
int istrue(long long a, int N, long long power_table[]);
long long simple_pow(int base, int exp);
int main() 
{
    int N;
    scanf("%d", &N);
    // 预计算 0~9 的 N 次方
    long long power_table[10];
    for (int d = 0; d <= 9; d++) 
    {
        power_table[d] = simple_pow(d, N);
    }

    // 只计算一次上下界
    long long start = 1;
    for (int i = 1; i < N; i++) start *= 10; // 10^(N-1)
    long long end = start * 10;                // 10^N
    // 遍历所有 N 位数
    for (long long i = start; i < end; i++) 
    {
        if (istrue(i, N, power_table)) 
        {
            printf("%lld\n", i);
        }
    }

    printf("End of Output\n");
    return 0;
}

// 简单幂函数，适用于小底数和小指数
long long simple_pow(int base, int exp) 
{
    if (exp == 0) return 1;
    long long result = 1;
    for (int i = 0; i < exp; i++) 
    {
        result *= base;
    }
    return result;
}

int istrue(long long a, int N, long long power_table[]) 
{
    long long p = 0;
    long long temp = a;
    while (temp > 0) 
    {
        int b = temp % 10;
        p += power_table[b]; // 直接查表，O(1)
        temp /= 10;
    }
    return (p == a);
}

