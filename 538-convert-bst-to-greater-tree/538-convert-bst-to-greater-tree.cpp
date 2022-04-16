/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* cur){
        
        if(cur == NULL)
            return 0;
        
        int sum = cur->val;
        sum += dfs(cur->left);
        sum += dfs(cur->right);

        return sum;
    }
    
    void left_side_update(TreeNode* cur, int prev_sum){
        
        if(cur == NULL)
            return;
        
        cur->val += prev_sum;
        left_side_update(cur->left, prev_sum);
        left_side_update(cur->right, prev_sum);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {

        if(root == NULL)
            return NULL;
        
        convertBST(root->left);
        root->val += dfs(root->right);
        left_side_update(root->left, root->val);
        convertBST(root->right);

        return root;
    }
};

/*
Traverse

*/