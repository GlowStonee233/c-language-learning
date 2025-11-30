#include<stdio.h>

int clearBit(int num, int n);
int isPowerOfTwo(int num);
void getRGB(int color, int *red, int *green, int *blue);
int countOnes(int num);
int XOR(int a, int b);

int main(){
    printf("XOR实现: %d\n", XOR(3, 7));
    printf("直接异或: %d\n", 3 ^ 7);
    
    // 测试其他函数
    printf("清除第1位后的5: %d\n", clearBit(5, 1));  // 5(101) -> 1(001)
    printf("8是2的幂吗: %d\n", isPowerOfTwo(8));
    printf("6是2的幂吗: %d\n", isPowerOfTwo(6));
    
    int red, green, blue;
    getRGB(0xFF3366, &red, &green, &blue);
    printf("颜色分解 - R:%d G:%d B:%d\n", red, green, blue);
    
    printf("7的二进制中1的个数: %d\n", countOnes(7));
    
    return 0;
}

int clearBit(int num, int n){
    int mask = ~(1 << n);
    return num & mask;
}

int isPowerOfTwo(int num){
    if(num <= 0) return 0;
    return (num & (num - 1)) == 0;
}

void getRGB(int color, int *red, int *green, int *blue){
    *red = (color >> 16) & 0xFF;
    *green = (color >> 8) & 0xFF;
    *blue = color & 0xFF;
}

int countOnes(int num){
    int count = 0;
    unsigned int temp = (unsigned int)num;
    while(temp){
        count += temp & 1;
        temp >>= 1;
    }
    return count;
}

int XOR(int a, int b){
    return a ^ b;  // 简单直接的方式
}