// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// INCOMPLETE
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedArrayToBST(std::vector<int>& nums){
    size_t rid {nums.size()/2};
    TreeNode* root {new TreeNode{nums[rid]}}, *temp{root};
    if(nums.size() > 1){
        if(nums.size()%2==0){
            for(int i{static_cast<int>(rid-1)}; i > 1; i--){
                temp->left = new TreeNode(nums[i]);
                temp = temp->left;
            }
            temp->left = new TreeNode(nums[0]);
            temp->right = new TreeNode(nums[1]);
        }
        else{
            for(int i{static_cast<int>(rid-1)}; i >=0; i--){
                temp->left = new TreeNode(nums[i]);
                temp = temp->left;
            }
        }
        temp = root;
        for(size_t i{rid+1}; i<nums.size(); i++){
            temp->right = new TreeNode(nums[i]);
            temp = temp->right;
        }
    }
    return root;
}