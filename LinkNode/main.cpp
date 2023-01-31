//
//  main.cpp
//  LinkNode
//
//  Created by dry on 2023/1/8.
//

#include <iostream>


struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {  // 这套代码问题在哪里
    ListNode* dummy = new ListNode(0,head);
    ListNode* slow=dummy;
    ListNode* quick=head;
    while(quick != nullptr){
        while(n){
            quick = quick ->next;
            n--;
        }
        if(quick != nullptr){
            slow = slow->next;
            quick = slow->next;
        }else{
            quick = slow->next;
            break;
        }
    }

    slow->next = quick->next;
    free(quick);

    return head;
}

int main(int argc, const char * argv[]) {

    
}
