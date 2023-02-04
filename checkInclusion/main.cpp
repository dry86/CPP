//
//  main.cpp
//  checkInclusion
//
//  Created by dry on 2023/1/9.
//

#include <iostream>
#include "string"
#include "map"
#include <vector>
using namespace::std;

namespace ref1 {
bool checkInclusion(string s1, string s2) {
    int n = s1.length();
    vector<int> a1(26,0);
    for(auto c : s1)
        a1[c -'a']++;
    int left = 0,right = 0;
    vector<int> a2(a1);
    while(right < s2.size()){
        a2[s2[right] - 'a']--;
        while(a2[s2[right] - 'a']< 0){
            a2[s2[left] - 'a']++;
            left++;
        }
        if(n == right - left + 1)return true;
        right++;
    }
    return false;
}
}
bool checkInclusion1(string s1, string s2) {  // 通过测试用例, 超时
    if(s1.size() > s2.size())
        return false;
    map<char,int> map_s1;
    for(auto i : s1)
        map_s1[i]++;
    int s1_length = s1.size();
    for(int i = 0 ; i <= s2.size() - s1_length  ; i++ ){
        int j = i;
        int flag = 0;
        map<char,int> time;
        do{
            if(map_s1.end() != map_s1.find(s2[j])){
                flag++;
                time[s2[j]]++;
            }
            j++;
        }while(j-i != s1_length);
        if( flag == s1_length ){
            while(i < j){
                if( map_s1[s2[j]] != time[s2[j]] ){
                    flag = 0;
                    break;
                }
                j--;
            }
        }
        if( flag == s1_length ){
            return true;
        }
    }
    return false;
}
bool checkInclusion2(string s1, string s2) {
    if(s1.size() > s2.size())
        return false;
    map<char,int> map_s1 ;
    int times_s1 = 0;
    for(auto i : s1){
        map_s1[i]++;
    }
    for(auto i : s1){
        times_s1 += (i - 'a') * map_s1[i];
    }
    int s1_length = s1.size();
    for(int i = 0 ; i <= s2.size() - s1_length  ; i++ ){
        int j = i;
        int flag = 0;
        map<char,int> map_s2;
        int times_s2 = 0;
        do{
            if(map_s1.end() != map_s1.find(s2[j])){
                flag++;
                map_s2[s2[j]]++;
            }
            j++;
        }while(j-i != s1_length);
        for(auto i : map_s2)
            times_s2 += (i.first - 'a') * i.second;
        if( flag == s1_length && times_s1 == times_s2 ){
            return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << ref1::checkInclusion("ab", "bebdba");
    
}
