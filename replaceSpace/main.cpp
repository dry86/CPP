//
//  main.cpp
//  replaceSpace
//
//  Created by dry on 2023/2/5.
//

#include <iostream>
using namespace::std;
string replaceSpace(string s) {
    int count = 0;
    for(auto c : s){
        if( c == ' ')
            ++count;
    }
    auto srbegin1 = s.rbegin();
    s.resize(s.size() + count*2);
    auto srbegin2 = s.rbegin();
//    srbegin1 += count;
//    cout << *srbegin1 << endl;
//    cout << *srbegin2 << endl;
    while(srbegin1 != srbegin2 ){
        if( *srbegin1 == ' '){
            *srbegin2 = '0'; ++srbegin2;
            *srbegin2 = '2'; ++srbegin2;
            *srbegin2 = '%';
        }else{
            *srbegin2 = *srbegin1;
        }
        ++srbegin1;
        ++srbegin2;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << replaceSpace("We are happy.") << endl;
    return 0;
}
