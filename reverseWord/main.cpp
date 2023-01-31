//
//  main.cpp
//  reverseWord
//
//  Created by dry on 2023/1/7.
//

#include <iostream>
#include "vector"
using namespace::std;

string reverseWords(string s) {
    string::iterator left=s.begin();
    auto right = left;
    while( right < s.end() ){
        if( *(right+1) == ' ' || right+1 == s.end() ){
            auto tempRight = right;
            while(left < tempRight){
                swap(*left, *tempRight);
                left++; tempRight--;
            }
//            right ++;
            left = right = right + 2;
        }else
            right ++;
    }
    return s;
}


int main(int argc, const char * argv[]) {
    
    string s="Let's take LeetCode contest";
    string result = reverseWords(s);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    
}
