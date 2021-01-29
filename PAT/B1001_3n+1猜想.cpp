#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int n;
    int step=0;
    scanf("%d",&n);
    while (n!=1)
    {
        /* code */
        if(n%2==0){
            n=n/2;
        }else{
            n=(3*n+1)/2;
        }
        step++;
    }
    printf("%d\n",step);
    
}