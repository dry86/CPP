/*  输入一个数n（1<=n<=200），然后输入n个数值各不相同都数，再输入一个值x，
输出这个值在数组中都下标
输入
4
1 2 3 4
3
输出
2

*/
#include<cstdio>
int main()
{
    int n,data[201]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d",&data[i]);
    }
    int x;
    scanf("%d",&x);
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (x==data[i])
        {
            /* code */
            printf("%d\n",i);
            return 0;
        }
        
    }
    printf("-1\n");
    return 0;
}