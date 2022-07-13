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
    vector<vector<int>> answer;
    map <int, vector<int>> m;
    
public:
    void dfs(TreeNode* cur, int level){
        
        if(!cur)
            return;
        
        m[level].push_back(cur->val);
        dfs(cur->left, level+1);
        dfs(cur->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root){
            dfs(root, 1);
            for(auto x: m)
                answer.push_back(x.second);      
        }
        
        return answer;
    }
};