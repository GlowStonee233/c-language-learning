/*1. 按字典序排列文本
【问题描述】

对分行输入的若干字符串按字典序（由小到大）进行排序并输出。
【输入形式】

控制台输入多行字符串，各个字符串可能含有空格。
【输出形式】

输出按字典序（由小到大）进行排序后的字符串。
【样例输入】

zwtr
fhoenf
hefe
afe geg
【样例输出】

afe geg
fhoenf
hefe
zwtr
【样例说明】

输入多行字符串：

zwtr
fhoenf
hefe
afe geg
输出字典序的字符串为：

afe geg
fhoenf
hefe
zwtr*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_length 50
#define MAX_width 50
int main(){
   char arr[MAX_length][MAX_width];
   char temp[MAX_width];
   int count=0;
   while(fgets(arr[count],MAX_width,stdin)!=NULL){
        int len = strlen(arr[count]);
        if (arr[count][len-1] =='\n'){
            arr[count][len-1] = '\0';
        }
        count++;
    }
    for(int i=0;i<count;i++){
        for(int j=0;j<count-1;j++){
            if(strcmp(*(arr+j),*(arr+j+1))>0){
            strcpy(temp, *(arr+j));
            strcpy(*(arr+j),*(arr+j+1));
            strcpy(*(arr+j+1),temp);
            }
        }
    }
    for(int i=0;i<count;i++){
        printf("%s\n",*(arr+i));
    }
    return 0;
}

