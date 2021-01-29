#include<cstdio>
int main (){
    int n,score[100001]={0};
    scanf("%d",&n);
    int school,grade,max=0;    //max store max school
    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d%d",&school,&grade);
        score[school] +=grade;
        if(score[max]<score[school])
        {
            max=school;
        }
    }
    printf("%d %d\n",max,score[max]);
    return 0;
}
//100000