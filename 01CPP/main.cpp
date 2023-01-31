//
//  main.cpp
//  01CPP
//   最长回文子串 
//  Created by dry on 2022/9/28.
//

#include <iostream>
#include "string"
#include "vector"
#include "cctype"
using namespace::std;
//struct Foo { };

/// <#Description#>
/// - Parameters:
///   - it1: <#it1 description#>
///   - it2: <#it2 description#>
bool vaildPalindromic( string::const_iterator it1,string::const_iterator it2)
{
    while(it1<it2)
    {
        if(*it1 == *it2)
        {
            it1++; it2--; // 字符相同则 头iterator向前, 尾iterator向后.
        }else{
            return false;  // 不是回文串, 直接break
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    
    string s = "abb";
//    cout << *s.begin()  << endl; // s.begin() 表示指向第一个元素, int 值为 0 !
    string resultstr ;
    unsigned int  ibegin = 0;
    unsigned int MaxLegth = 0;
    for(auto it1 = s.cbegin(); it1 != s.cend(); it1++)
    {
        
        for(auto it2 = it1 ; it2 !=s.cend(); it2 ++)
        {
            unsigned int tempLegth = it2 - it1 + 1;
            if(vaildPalindromic(it1,it2) && tempLegth > MaxLegth){
                ibegin = it1 - s.cbegin() ;
                MaxLegth = tempLegth;
            }
        }
        
    }
    resultstr = s.substr(ibegin,MaxLegth);  // 获得字符串s中从第ibegin位开始的长度为Maxlength的字符串
    
    cout << resultstr << endl;
    
    
    //    int i = 2;
    //    const int ci = i;
    //    auto d = &i;
    ////    d = 42;
    //    auto &g = ci;
    ////    g = 42;
    //    cout << *d << endl;
    //    cout << ci << endl;
    //
    
}
