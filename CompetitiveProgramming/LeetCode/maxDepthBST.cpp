// https://leetcode.com/problems/maximum-depth-of-binary-tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int countDepth(TreeNode* nd, int depth){
    if(!nd) return depth-1;
    if(!nd->left && !nd->right) return depth;
    if(!nd->left) return countDepth(nd->right, depth+1);
    if(!nd->right) return countDepth(nd->left, depth+1);
    int ld{countDepth(nd->left, depth+1)}, rd{countDepth(nd->right, depth+1)};
    return (ld > rd) ? ld : rd;
}

int maxDepth(TreeNode* root){
    return countDepth(root, 1);
}

int main(){

}