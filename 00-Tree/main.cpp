//
//  main.cpp
//  00-Tree
//
//  Created by dry on 2023/2/21.
//

#include "constructTree.h"

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr) return nullptr;
    if(root->val == val){
        return root;
    }
    if(root->val > val){
        return searchBST(root->left, val);
    }else{
        return searchBST(root->right, val);
    }
    return nullptr;
}


    static int countk = 3;
    TreeNode* node;
void searchTree(TreeNode* root){
    if(root->right)  searchTree(root->right);
    if(countk == 1){
        node = root;
        --countk;
        return;
    }else{
        --countk;
    }
    if(root->left)    searchTree(root->left);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    vector<int> nums{4,2,7,1,3};
//    TreeNode* root = construct_binary_tree(nums);
//
//    searchBST(root, 2);
//    vector<int> nums{5,3,6,2,4,-1,-1,1};
//    TreeNode* root = construct_binary_tree(nums);
//    searchTree(root);
//    cout << countk << endl;
//    cout << node->val << endl;
    
    
//    vector<int> nums{1,2,3,-1,-1,4,5};
//    TreeNode* root = construct_binary_tree(nums);
//    cout << serialize(root) <<endl;
//
    
    TreeNode* tn = new TreeNode;
    
    delete tn;
    
    return 0;
}
