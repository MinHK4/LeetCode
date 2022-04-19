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
    TreeNode* node1 = NULL, *node2 = NULL, *prev = NULL;
    
public:
    void inorder(TreeNode* cur){
        if(cur == NULL)
            return;
        
        inorder(cur->left);
        
        // 정렬되어 있지 않은 노드 찾아주기
        if(node1 == NULL && prev != NULL && prev->val >= cur->val)
            node1 = prev;
        if(node1 != NULL && prev != NULL && prev->val >= cur->val)
            node2 = cur;
        prev = cur;
            
        inorder(cur->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        
        // Find Two nodes
        inorder(root);
        
        // Swap tow nodes
        int temp = node2->val;
        node2->val = node1 -> val;
        node1->val = temp;
    }
};

/*
IDEA : Inorder Traverse로 순서가 맞지 않는 두 부분 찾아주고 그 두 부분 Swap하기

inorder Traverse로 모든 Node의 값을 찍으면 값이 정렬되어 나와야 하고
문제에서 제시된 대로 한번의 Swap만 발생한거면 정렬에 안 맞는 값은 딱 2개여야 함
따라서 이를 인접한 노드끼리 비교하면서 봤을 때 처음 맞지 않는 경우는 앞의 것이 문제이고 두번째 맞지 않는 경우는 뒤의 것이 문제임
*/