/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* cur = head;
        ListNode* left = head;
        ListNode* right = head;
        
        // 양쪽에서 k번째 떨어진 노드 찾기
        // 끝에서 k번째는 k가 되기 전까지 이동안시켜서 N-k번을 이동시키면 됨 
        int cnt = 1;
        while(cur != NULL){
            if(cnt < k)
                left = left->next;
            if(cnt > k)
                right = right->next;
            cnt++;
            cur = cur-> next;
        }
        
        // 값만 바꿔주기
        int temp = right->val;
        right->val = left->val;
        left->val = temp;
        
        return head;
    }
};