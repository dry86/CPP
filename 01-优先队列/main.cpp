//
//  main.cpp
//  01-优先队列
//
//  Created by dry on 2023/2/20.
//

#include <iostream>
#include <queue>

using namespace::std;

/*
 
 priority_queue可以使用数组或链表等数据结构实现，但是标准库中的实现方式是使用堆（Heap）数据结构。
 
 堆是一种特殊的二叉树结构，可以通过维护堆的性质来保证堆中的元素始终按照一定的顺序排列。
 在priority_queue中，通常使用大根堆（Max Heap）实现，这意味着元素的优先级越高，堆中的元素值就越大。

 priority_queue的常用操作包括：

 push：将元素加入队列
 pop：将队列中优先级最高的元素取出并从队列中删除
 top：返回队列中优先级最高的元素
 size：返回队列中的元素个数
 empty：检查队列是否为空
 
 */


int main(int argc, const char * argv[]) {

    //对于基础类型,C++默认是大顶堆,即队头 .top() 总是最大的元素
    priority_queue<int> pqa;    //等同于 priority_queue<int, vector<int>, less<int> > pqa;
    
    
    priority_queue<int, vector<int>, greater<int> > pqb;
    
    for(int i = 0; i < 5 ; ++i){
        pqa.push(i);
        pqb.push(i);
    }
    
    while(!pqa.empty()){    // 4 3 2 1 0
        cout << pqa.top() << " ";
        pqa.pop();
    }
    cout << endl;
    
    
    while(!pqb.empty()){    // 0 1 2 3 4
        cout << pqb.top() << " ";
        pqb.pop();
    }
    
    
    cout << endl;
    
}
