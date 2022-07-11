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
    vector<int> answer;
    
public:
    void dfs(TreeNode *cur, int level)
    {
        if(!cur) 
            return ;
        
        // 오른쪽 진행시에는 예외 없이 전부 작동
        // 왼쪽 진행시에는 오른쪽으로 보낸 것보다 무조건 더 깊은 레벨일 경우에만 작동
        if(answer.size()<level) 
            answer.push_back(cur->val);
        
        // 오른쪽을 한칸씩 쭉 진행
        dfs(cur->right, level+1);
        
        // 오른쪽 다 시행하고 난 다음에 추가로 오른쪽보다 긴 왼쪽 있는지 파악해주기
        dfs(cur->left, level+1);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        
        dfs(root, 1);
        
        return answer;
    }
};