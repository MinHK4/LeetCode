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
    int cur_sum = 0;
    
public:
    
    /*
    내 풀이 방식
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
    */
    
    // modification of Inorder Traverse
    void traverse(TreeNode* root){
        if (!root) return;
        
        traverse(root->right);
        root->val = (cur_sum += root->val);
        traverse(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};

/*
Original Inorder Traverse
: 작은 수부터 들르면서 자신보다 큰 값들을 찾아서 다 더해주고
그리고 그것들을 자기보다 작은 수들에게도 동일하게 적용해주기

Modificatoin of Inorder Traverse
: 큰 수(오른쪽)부터 먼저 들르면서 해당 노드의 값을 sum에 누적시켜놓으면
어떤 노드에 도착했을 때 sum은 그것보다 큰 수의 누적합으로 저장되어있음
따라서 그 순서로 traverse만 해주고 도착했을 때 현재 노드에 sum을 더해주기만 하면 됨
*/