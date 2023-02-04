#include<iostream>
#include<cmath>
using namespace std;
int N;
int queenPos[100];
void NQueen(int k);
int main()
{
    cin >>N;
    NQueen(0);
    return 0;
}
void NQueen(int k)
{
    int i;
    if( k==N){
        for(i=0;i<N;i++)
            cout<<queenPos[i] + 1 << " ";
        cout<<endl;
        return ;
    }
    for( i = 0;i<N;i++){  //
        int j;
        for(j=0;j<k;j++){  //与已经摆好的k个皇后的位置比较，看是否冲突
            if(queenPos[j] ==i || abs(queenPos[j] - i) == abs(k-j) ){
                break;
            }
        }
        if( j==k ){
            queenPos[k]=i;
            NQueen(k+1);
        }
    }
}