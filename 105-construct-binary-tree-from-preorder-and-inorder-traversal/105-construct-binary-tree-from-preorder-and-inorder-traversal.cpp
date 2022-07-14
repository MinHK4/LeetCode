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
    int rootIdx;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        rootIdx = 0;
        
        return build(preorder, inorder, 0, inorder.size()-1);
    }
    
    // 
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        
        // 인덱싱 바운더리 처리
        if (l > r) 
            return NULL;
        
        // preorder의 순서대로 하나씩 보면서
        // 해당하는 노드의 inorder를 탐색해서 더 sub트리가 형성될 수 있는지 좌우 브랜치 여부를 통해서 판단
        int pivot = l;  
        while(inorder[pivot] != preorder[rootIdx]) 
            pivot++;
        rootIdx++;
        
        // pivot으로 subtree의 루트 노드를 하나씩 잡아주고 이를 재귀적으로 더 탐색함
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, l, pivot-1);
        newNode->right = build(preorder, inorder, pivot+1, r);
        
        return newNode;
    }
};

/*
Preorder의 경우 방문한 순서대로 찍히기 때문에 기본적인 순서 흐름을 알 수 있고
Inorder의 경우 현재 노드 idx를 기준으로 0~idx-1 왼쪽, idx+1~size()-1 오른쪽 이런 방식으로 나눠지는 것을 알 수 있음
*/