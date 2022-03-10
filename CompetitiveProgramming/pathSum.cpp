// https://leetcode.com/problems/path-sum/

#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasPathSum(TreeNode* root, int targetSum){
    if(!root) return false;
    else if(!(targetSum -= root->val) && !root->left && !root->right){
        return true;
    }
    else return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int main(){
    return 0;
}