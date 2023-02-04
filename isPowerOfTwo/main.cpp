//
//  main.cpp
//  isPowerOfTwo
//
//  Created by dry on 2023/2/1.
//

#include <iostream>

bool isPowerOfTwo(int n) {
    if(n<=0) n = -n;
    int temp = n;
    int times = 0;
    while(temp != 1){
        temp >> 1;
        times += 1;
    }
    if( 2^times == n){
        return true;
    }else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isPowerOfTwo(16);
    return 0;
}
