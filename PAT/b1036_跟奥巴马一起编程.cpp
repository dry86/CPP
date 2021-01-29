#include<iostream>
using namespace std;
int main(){
    int col,row;
    cin>>col;
    if(col%2){
        row=col/2 +1;
    }else{
        row=col/2;
    }
    char c;
    cin>>c;
    for (int i = 0; i < row; i++)
    {
        if(i==0 || i==row-1){
            if(i==row-1){
                cout<<endl;
            }
            for(int j=0;j<col;j++){
                cout<<c;
            }
        }else{
            cout<<endl;
            for(int j=0;j<col;j++){
                if(j==0 || j==col-1){
                    cout<<c;
                }else{
                    cout<<" ";
                }
            }
        }
    }

    return 0;
}