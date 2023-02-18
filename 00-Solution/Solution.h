//
//  Solution.h
//  01CPP
//
//  Created by dry on 2023/2/15.
//

#ifndef Solution_h
#define Solution_h
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace::std;



namespace t1 {

vector<int> exchange(vector<int>& nums) {
    if(nums.size() == 0)    return nums;
    int begin = 0, end = nums.size()-1;
    while(begin < end){
        while(  begin < nums.size() && nums[begin]%2 == 1){ //左侧是奇数则++
            ++begin;
        }
        while( end > 0 && nums[end]%2 == 0 ){   //右侧是偶数则--
            --end;
        }
        if(begin < end){
            swap(nums[begin], nums[end]);
        }
        ++begin;
        --end;
    }
    return nums;
}
}
namespace t2{

// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/submissions/
vector<int> twoSum(vector<int>& nums, int target) {
    size_t numsSize = nums.size();
    for(int i = 0; i < numsSize; ++i){
        int aim = target - nums[i];
        if(aim <= 0)    break;  //找不到
        vector<int> ans{nums[i]};
        int begin = i+1, end = numsSize - 1;
        while(begin <= end){
            int mid = begin + (end - begin)/2;
            if(nums[mid] == aim){
                ans.push_back(nums[mid]);
                return ans;
            }else if(nums[mid] < aim){
                begin = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    vector ans{0,0};
    return ans;
}

void t22(){
    unordered_map<int, string> map;
    map[2] = "abc";
    string s = "2";
    
    cout << map[s[0]-'0'] << endl;
    
}
}

namespace t3{
class Solution {
public:
    vector<vector<int>> answer;
    void backtracking(vector<int>& ans, vector<int>& candidates, int target){
        if(target < 0){
            return;
        }
        if(target == 0){
            answer.push_back(ans);
            return;
        }
        for(int i = 0 ; i <= candidates.size() - 1 ; ++i){
            int times = 1;
            int temp = 0;
            while(temp>=0){
                target -= candidates[i] * times;
                temp = target;
                int j = times;
                while(j){
                    ans.push_back(candidates[i]);
                    --j;
                }
                backtracking(ans, candidates, target);
                while(j!=times){
                    ans.pop_back();
                    ++j;
                }
                target += candidates[i] * times;
                ++times;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        backtracking(ans, candidates, target);
        return answer;
    }
};
}

namespace t4{
class Solution {
public:
    vector<vector<int>> answer;
    void backtracking(int index, vector<int>& ans, vector<int>& candidates, int target){
        if(target < 0){
            return;
        }
        if(target == 0){
            answer.push_back(ans);
            cout << 1 << endl;
            return;
        }
        for(int i = index ; (i <= candidates.size() - 1) && (target - candidates[i] >= 0); ++i){
            target -= candidates[i];
            ans.push_back(candidates[i]);
            backtracking(i, ans, candidates, target);
            ans.pop_back();
            target += candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        backtracking(0, ans, candidates, target);
        return answer;
    }
};
}

namespace t5{
bool isHuiWen(const string& s){
    int begin = 0, end = s.size()-1;
    while(s[begin]  ==  s[end] && begin < end){
        ++begin;
        --end;
    }
    if(begin >= end){
        return true;
    }
    return false;
}
void t55(){
    string s = "aabaa";
    cout << isHuiWen(s) << endl;
    
}
}

namespace t6{
class Solution {
public:
    vector<vector<string>>  answer;
    vector<string> ans;

    bool isHuiWen(const string& s){
        int begin = 0, end = s.size()-1;
        while(s[begin]  ==  s[end] && begin < end){
            ++begin;
            --end;
        }
        if(begin >= end){
            return true;
        }
        return false;
    }

    void backtracking(int index, string tempAns, string s){
        // if(index > s.size()-1)  return;
        if(tempAns.size() == s.size()){
            answer.push_back(ans);
            return;
        }
        int size = 1;
        while(size){
            if(index + size > s.size()){
                break;
            }
            string tempstr = s.substr(index,size);
            if( isHuiWen(tempstr) ){
                ans.push_back(tempstr);
                int itempAns = tempAns.size();
                tempAns += tempstr;
                backtracking( index + size, tempAns , s);
                tempAns.erase(itempAns, tempstr.size());
                ans.pop_back();
                ++size;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(0, "", s);
        return answer;
    }
};
}





#endif /* Solution_h */
