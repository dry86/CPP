//
//  main.cpp
//  冒泡排序
//
//  Created by dry on 2023/2/20.
//

#include <iostream>
#include <vector>

using namespace::std;

void BubbleSort(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j > i; --j){
            if(nums[j-1] > nums[j]){
                swap(nums[j-1], nums[j]);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
