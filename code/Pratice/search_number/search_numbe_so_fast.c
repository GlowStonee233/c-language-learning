//这是一个大幅优化的版本，利用了数字组合的性质，避免了大量不必要的计算。
#include <stdio.h>
// 全局变量，用于递归中共享
int N;
long long power_table[10];
int digit_counts[10]; // 记录当前组合中每个数字(0-9)出现的次数
long long fast_pow(int base, int exp) ;
void dfs(int current_digit, int digits_left, long long current_sum);
void check(long long sum);
int main() 
{
    // 读取输入 N
    scanf("%d", &N);
        // 1. 预计算 0-9 的 N 次幂
    for (int i = 0; i <= 9; i++) 
    {
            power_table[i] = fast_pow(i, N);
    }
        // 2. 初始化计数器
    for (int i = 0; i <= 9; i++) digit_counts[i] = 0;
        // 3. 开始 DFS
        // 从数字 9 开始尝试，初始剩余 N 个空位，初始和为 0
    dfs(9, N, 0);           
    printf("End of Output\n");
    return 0;

}
// 快速幂计算 (仅用于预计算)
long long fast_pow(int base, int exp) 
{
    long long res = 1;
    for (int i = 0; i < exp; i++) res *= base;
    return res;
}

// 检查幂和是否符合条件
void check(long long sum) 
{    
// 1. 计算 sum 的总位数 和 每个数字出现的次数
    long long temp = sum;
    int sum_counts[10] = {0};
    int total_digits = 0;
    while (temp > 0) 
    {
        sum_counts[temp % 10]++;
        temp /= 10;
        total_digits++;
    }
    // 2. 剪枝：如果位数不对，直接返回
    if (total_digits != N) return;
    // 3. 核心验证：比较 sum 的数字统计 与 当前组合的数字统计 是否一致
    for (int i = 0; i <= 9; i++) 
    {
        if (sum_counts[i] != digit_counts[i]) 
        {
            return; // 不匹配
        }
    }
    // 4. 通过验证，输出结果
    printf("%lld\n", sum);
}
/**
 * DFS 搜索所有数字组合
 * @param current_digit 当前正在考虑放入组合的数字 (9 -> 0)
 * @param digits_left   组合中还剩多少个空位
 * @param current_sum   当前组合的幂和
 */
void dfs(int current_digit, int digits_left, long long current_sum) 
{
    // 边界条件：如果所有位置都填满了
    if (digits_left == 0) 
    {
        check(current_sum);
        return;
    }
    // 边界条件：如果数字已经尝试到 -1 了 (不应该发生，但作为保险)
    if (current_digit < 0) return;
    // 剪枝：如果当前和已经超过 N 位数的最大值(10^N - 1)，可以提前停止（可选，视情况而定）
    // 这里简化处理，不做复杂剪枝，直接遍历完组合。
    if (current_digit == 0) 
    {
        // 如果只剩下 0 了，剩下的空位全部填 0
        digit_counts[0] += digits_left;
        // 0 的幂和是 0，所以 current_sum 不变
        check(current_sum);
        digit_counts[0] -= digits_left; // 回溯
        return;
    }

    // 核心递归：尝试当前数字 current_digit 出现 i 次 (i 从 0 到 digits_left)
    for (int i = 0; i <= digits_left; i++)
 {
        digit_counts[current_digit] = i; // 记录当前数字选了 i 个
        
        // 继续递归下一个更小的数字，剩余空位减少 i，幂和增加 i * power_table[current_digit]
        dfs(current_digit - 1, digits_left - i, current_sum + i * power_table[current_digit]);
    }
    // 回溯：恢复状态 (虽然上面的循环每次都覆盖 digit_counts[current_digit]，但好习惯是恢复)
    digit_counts[current_digit] = 0;
}

