//
//  main.cpp
//  moveZero
//
//  Created by dry on 2023/1/6.
//

#include <iostream>
#include "vector"
using namespace::std;

void moveZeroes(vector<int>& nums) {
    // vector<int> Zero;
    // vector<int>::iterator rZero = Zero.begin();
    int iZero = -1;
    for(int i = 0 ; i< nums.size() ; i++)
    {
        if(nums[i] == 0)
        {
            if(i == 0)
                iZero = 0;
            if(nums[i-1] != 0)
                iZero = i;
        }else{
            // if(rZero != Zero.end() && Zero.empty()){
            if( iZero != -1){
                int temp = nums[iZero];
                nums[iZero] = nums[i];
                nums[i] = temp;

                iZero ++;
                while(nums[iZero]){
                    iZero ++;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    vector<int> nums{0,1,0,3,12};
    moveZeroes(nums);
    for(auto i: nums)
        cout << i << " ";
    cout << endl;
}
