//
//  main.cpp
//  twoSum
//
//  Created by dry on 2023/1/6.
//

#include <iostream>
#include "vector"
using namespace::std;

namespace  t1{

}
int binarySearch(vector<int>& numbers ,int begin ,int target){
    int left = begin , right = numbers.size()-1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(numbers[mid] == target){
            return mid;
        }else if (numbers[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return 0;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int left = 0;
    while (left < numbers.size()){
        int rightValue = target-numbers[left];
        int bSresult = binarySearch( numbers, left+1, rightValue );
        if(bSresult){
            result.push_back(left + 1);
            result.push_back(bSresult + 1);
            return result;
        }else{
            left ++;
        }
    }
    return result;
}
namespace t2{
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int begin = 0, end = numbers.size()-1;
    while(begin != numbers.size()-1){
        int left = begin + 1;
        int right = end;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(numbers[begin] + numbers[mid] == target){
                ans.push_back(begin+1);
                ans.push_back(mid+1);
                return ans;
            }else if(numbers[begin] + numbers[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        begin++;
    }
    return ans;
}
}
int main(int argc, const char * argv[]) {

    vector<int> numbers{5,25,75};
    vector<int> result = t2::twoSum(numbers, 100);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
}
