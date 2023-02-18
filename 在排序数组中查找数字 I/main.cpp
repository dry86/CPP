//
//  main.cpp
//  在排序数组中查找数字 I
//
//  Created by dry on 2023/2/6.
//

#include <iostream>
#include <vector>
using namespace::std;

int search(vector<int>& nums, int target) {
    int begin = 0, end = nums.size()-1;
    int mid = -1;
    while( begin <= end ){
        mid = begin + (end - begin)/2;
        if(nums[mid] == target){
            break;
        }else if(nums[mid] > target){
            end = mid - 1;
        }else{
            begin = mid + 1;
        }
    }
    if(begin > end){    // 没有匹配到target
        return 0;
    }
    int count = 1;
    int left = mid - 1, right = mid + 1;
    while( left >= 0  ){    //向左看vector中还有几个Target
        if( nums[left] == target){
            ++count;
            --left;
        }else{
            break;
        }
    }
    while(right <= nums.size() -1 ){    //向右看vector中还有几个Target
        if( nums[right] == target){
            ++count;
            ++right;
        }else{
            break;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,1};
    std::cout << search(nums,1) << std::endl;
    return 0;
}
