//
//  main.cpp
//  迭代器
//
//  Created by dry on 2022/12/31.
//

#include <iostream>
#include "string"
#include "vector"
#include "cctype"
using namespace::std;

int main(int argc, const char * argv[]) {
    
    
    
    vector<int> nums1{1};
    vector<int> nums2{2,3,4};
    vector<int> target;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
//    cout << "inums : "<< inums<<endl;
    if(nums1.size() == 0){
        target = nums2;
    }else if(nums2.size() == 0){
        target = nums1;
    }else{
        auto inums = nums1.size()+nums2.size();
        while(inums--)
        {
            if(it1==nums1.end() )
            {
                target.push_back(*it2++);
                continue;
            }
            if(it2==nums2.end() )
            {
                target.push_back(*it1++);
                continue;
            }
            if(*it1 <= *it2)
            {
                target.push_back(*it1);
                it1++;
            }
            else
            {
                target.push_back(*it2);
                it2++;
            }
        }
    }
    for (auto i : target)
        cout << i <<endl;
    double rvaule = 0.0;
    auto mid = target.begin() + (target.end() - target.begin()) / 2;
    if(target.size() % 2 == 0)
    {
        rvaule = (*mid + *(mid-1)) / 2.0;
    }
    else{
        rvaule = *mid ;
    }
    cout << "return : "<< rvaule<<endl;
    
    
    
//    vector<int> vi{1,3,7};
////    for(auto i = vi.begin() ; i != vi.end() ; i++)
////    {
////        *i *= 2;
////        cout << *i << endl;
////    }
//    auto mid = vi.begin() + vi.size() / 2 ;
//    cout << *mid << endl;
    
    
}

