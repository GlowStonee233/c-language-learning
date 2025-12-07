#include<stdio.h>
int main(){
  int n,i;
  scanf("%d",&n);
  int a[100],b[100];
  a[0]=2,a[1]=3,b[0]=1,b[1]=2;
  for(i=2;i<n;i++){
    a[i]=a[i-1]+a[i-2];
    b[i]=b[i-1]+b[i-2];
  }
  double sum=0.00;
  for(i=0;i<n;i++){
    sum+=(double)a[i]/(double)b[i];
  }
  printf("%.2f\n",sum);
  return 0;
}
//对于描述一个数列，使用数组是一个好方法
