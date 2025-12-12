// 计算cos(x)的前n项泰勒展开式的和
#include<stdio.h>
double mycos(double x, int n);
int main(){
    int n;
    double x;
    scanf("%lf %d",&x,&n);
    printf("%.8lf",mycos(x,n));
    return 0;
}
double mycos(double x, int n) {
    int i=0;
    double sum=0;
    int down[20];
    double up[20];
    down[0]=1;
    up[0]=1.0;
    for(i=0;i<15;i++){
        down[i+1]=(i+1)*down[i];
        up[i+1]=-x*x*up[i];
    }
    for(i=0;i<n;i++){
        sum+=up[i]/down[2*i];
    }
    return sum;
}

