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

private: 
    int cnt = 0;
    int key, ans;
    bool found = false;
    
public:
    void inorder(TreeNode* cur){
        if(!found && cur != NULL){
            inorder(cur->left);
            cnt++;
            if(cnt == key){
                ans = cur->val;
                found = true;
                return;
            }
            inorder(cur->right);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        key = k;
        inorder(root);
        return ans;
    }
};

/*
inorder traverse를 이용해서 작은 숫자부터 방문해오기
*/