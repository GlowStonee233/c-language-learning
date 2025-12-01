/* 2. 国名排序
【问题描述】 给定一系列国家名称，要求使用冒泡排序算法对这些国家名称进行排序。排序过程中，只允许交换指向国家名称的指针，而不是直接交换字符串内容。 

【输入形式】 输入首先给出一个整数n（1 <= n <= 100），表示国家名称的数量。接下来n行，每行给出一个国家名称，国家名称由大写字母组成。 

【输出形式】 按照字典顺序输出排序后的国家名称列表，每个名称占一行。 

【输入样例】

 5 

USA China UK France Russia 

【输出样例】

 China France Russia UK USA 

【样例说明】 输入样例中的国家名称经过冒泡排序后，按照字典顺序排列，依次输出 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char**arr=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        *(arr+i)=(char*)malloc(40*sizeof(char));
        scanf("%s",*(arr+i));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(strcmp(*(arr+j),*(arr+j+1))>0){
                char*temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n",*(arr+i));
    }
    return 0;
}


