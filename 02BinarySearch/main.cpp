//
//  main.cpp
//  02BinarySearch
//
//  Created by dry on 2023/1/4.
//

#include <iostream>
#include "vector"
using namespace::std;
int search(vector<int>& nums, int target) {   // 二分查找使用氛围: 查找整数,且知道范围
    int begin = 0, end = nums.size()-1;
    while( begin < end )
    {
        int mid = begin + (end-begin)/2;    // 求中间点
        if( nums[mid] == target)
        {
            return mid;
        }else if(nums[mid]<target)
        {
            begin = mid +1;
        }else
        {
            end = mid -1;
        }
    }
    return -1 ;
}

int searchInsert(vector<int>& nums, int target) {
    int begin = 0 , end = nums.size()-1;
    while(begin < end){
        int mid = begin + (end-begin)/2;
        int values = nums[mid];
        if(values == target)
        {
            return mid;
        }else if(values < target){
            begin = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return end + 1;
}

int main(int argc, const char * argv[]) {

    vector<int> nums{1,3,5,6};
    cout << searchInsert(nums,2) << endl;
}
