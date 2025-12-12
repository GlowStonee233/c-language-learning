//计算逆序数
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[100];
    int i=0;    
    int count=0;
    int result=0;
    int temp=n;
    while(temp>0){
        arr[count]=temp%10;
        temp=temp/10;
        count++;
    }//获取n的每一位数字（倒序排列）
    for(i=0;i<count;i++){
        result=10*result+arr[i];
    }//获取逆序数
    if(result%n==0){
        printf("%d*%d=",n,result/n);
        for(i=0;i<count;i++){
            printf("%d",arr[i]);
        }
    }
    else{
        printf("%d ",n);
        for(i=0;i<count;i++){
            printf("%d",arr[i]);
        }
    }
}

