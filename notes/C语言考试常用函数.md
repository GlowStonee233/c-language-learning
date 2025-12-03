# 基础数学运算函数

## 整数幂运算
```c
/**
 * 计算base的exponent次幂（exponent为非负整数）
 * @param base 底数
 * @param exponent 指数
 * @return base的exponent次幂
 */
int integer_power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

```
## 2. 阶乘函数
```c
/**
 * 计算n的阶乘（n为非负整数）
 * @param n 需要计算阶乘的数
 * @return n的阶乘
 */
int factorial(int n) {
    int p = 1;
    for (int i = 1; i <= n; i++) {
        p *= i;
    }
    return p;
}
```
# 进制转换相关

## 十进制转K进制（迭代法）
```c
/**
 * 将十进制数num转换为k进制并输出（2≤k≤10）
 * @param num 十进制数
 * @param k 目标进制
 */
void convertToBaseK(int num, int k) {
    if (k < 2 || k > 10) {
        printf("Error: Base must be between 2 and 10\n");
        return;
    }
    
    if (num == 0) {
        printf("0");
        return;
    }
    
    int digits[32];
    int index = 0;
    
    while (num > 0) {
        digits[index++] = num % k;  // 保存余数
        num /= k;                   // 更新商
    }
    
    // 逆序输出
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", digits[i]);
    }
}
```

## 十进制转二进制（递归法）
```c
/**
 * 递归实现十进制转二进制并输出
 * @param n 十进制非负整数
 */
void to_binary(unsigned int n) {
    int r = n % 2;
    if (n >= 2) {
        to_binary(n / 2);
    }
    putchar(r == 0 ? '0' : '1');
}
```
# 数值操作

## 交换两个整数
```c
/**
 * 通过指针交换两个整数的值
 * @param a 第一个整数的地址
 * @param b 第二个整数的地址
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 调用示例
 */
// int x = 5, y = 10;
// swap(&x, &y);  // 调用时需要传入地址
```
# 扩展常用函数
## 判断素数
```c
/**
 * 判断一个数是否为素数
 * @param n 需要判断的数
 * @return 1表示是素数，0表示不是素数
 */
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}
```
## 最大公约数（辗转相除法）
```c
/**
 * 求两个整数的最大公约数
 * @param a 第一个整数
 * @param b 第二个整数
 * @return a和b的最大公约数
 */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```
## 最小公倍数
```c
/**
 * 求两个整数的最小公倍数
 * @param a 第一个整数
 * @param b 第二个整数
 * @return a和b的最小公倍数
 */
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```
## 斐波那契数列
```c
/**
 * 计算第n个斐波那契数
 * @param n 斐波那契数列的项数（从0开始）
 * @return 第n个斐波那契数
 */
int fibonacci(int n) {
    if (n <= 1) return n;
    
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
```
##  数组求和
```c
/**
 * 计算整型数组的和
 * @param arr 整型数组
 * @param size 数组大小
 * @return 数组所有元素的和
 */
int array_sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
```
## 数组查找
```c
/**
 * 在数组中线性查找指定元素
 * @param arr 整型数组
 * @param size 数组大小
 * @param target 目标元素
 * @return 找到返回下标，未找到返回-1
 */
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
```
## 数组最大值
```c
/**
 * 查找数组中的最大值
 * @param arr 整型数组
 * @param size 数组大小
 * @return 数组中的最大值
 */
int array_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
```
## 数组反转
```c
/**
 * 反转数组元素顺序
 * @param arr 整型数组
 * @param size 数组大小
 */
void reverse_array(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
```
## 冒泡排序
```c
/**
 * 冒泡排序算法
 * @param arr 整型数组
 * @param size 数组大小
 */
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```
## 判断回文数
```c
/**
 * 判断一个整数是否为回文数
 * @param n 需要判断的整数
 * @return 1表示是回文数，0表示不是
 */
int is_palindrome(int n) {
    if (n < 0) return 0;
    
    int reversed = 0, original = n;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}
```
# 字符串操作

## 字符串长度
```c
/**
 * 计算字符串长度
 * @param str 字符串
 * @return 字符串长度（不包括结束符'\0'）
 */
int string_length(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
```
##  字符串复制
```c
/**
 * 复制字符串
 * @param dest 目标字符串
 * @param src 源字符串
 */
void string_copy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
```