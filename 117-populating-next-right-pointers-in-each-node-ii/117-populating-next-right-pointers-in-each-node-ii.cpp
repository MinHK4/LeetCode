/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
/*
개인시도 사항

private: 
    // map<int, int> level;
    // stack<Node*> s;
        
public:
    DFS로 한 층씩 내려가면서 각 층의 level 찾아놓기
    void DFS(Node* cur, int now){
        if(cur){
            level[cur->val] = now;
            DFS(cur->left, now+1);
            DFS(cur->right, now+1);
        }
    }
    
    Node* connect(Node* root) {    
        // DFS로 노드의 층 구해주기
        // DFS(root, 1);
        
        queue <Node*> q;
        q.push(root);
        
        Node* last = NULL;
        int cnt = 0;
        int last_cnt;
        while(!q.empty()){
            Node* cur = q.front(); 
            q.pop();
            cnt++;

            // 유효한 노드에 대해서만
            if(cur){
                // 같은 층에 있는 노드에 대해서 next 업데이트
                if(floor(log(cnt)) == floor(log(last_cnt)))
                    cur->next = last;

                // 다음 노드 오른쪽 먼저 채워서 넣어주고 last 업데이트
                q.push(cur->right);
                q.push(cur->left);
                last = cur;
                last_cnt = cnt;
            }
        }
        
        return root;
    }
*/

// level order traversal을 이용한 풀이
public:
    Node* connect(Node* root){
        
        Node* cur = root;
        Node* head = NULL;
        Node* prev = NULL;
        
        // 전체 레벨에 대한 반복문
        while(cur){
            
            // 현재 레벨에 대한 반복문
            while(cur){
                
                // 현재 노드에서 자식 있는지 양쪽 모두 확인하고
                // 각 방향에 대해서 다음 레벨의 next 관계 잡아주고
                // 각 방향에 대해서 다음 레벨의 시작점 잡아주고
                // 다음 레벨에서의 포인트 설정해주고
                
                if(cur->left){
                    if(prev)
                        prev->next = cur->left;
                    else
                        head = cur->left;
                    prev = cur->left;
                }
                
                if(cur->right){
                    if(prev)
                        prev->next = cur->right;
                    else
                        head = cur->right;
                    prev = cur->right;
                }
                
                // 같은 레벨 내에서 이동하기
                cur = cur->next;
            }
            
            // 다음 레벨로 이동하면서 값 초기화해주기
            cur = head;
            head = NULL;
            prev = NULL;
        }
    
        return root;
    }
};

/*
Binary Tree의 특성상 노드가 크기 순서로 정렬되어있음을 이용해 오른쪽 노드부터 BFS로 보면
마지막에 본 유효한 노드의 정보 last에 대해서 val의 크기 비교를 통해서 같은 층인지 여부를 확인할 수 있음

-- 틀렸음
[3,9,20,null,null,15,7]
Binary Tree지 Heap이 아니라서 크기 정렬의 기준이 없음
각 노드의 층을 정해줘야 함
?? 같은 값의 노드가 안 생긴다는 보장이 문제 제시에는 없는 듯?!

-- 시간초과
[0,0,0,0,null,null,0,null,null,null,0]
cnt 잡아서 들르는 노드의 개수 세주고 그걸로 같은 층인지 파악하기
하지만 null에서 파생되는 노드는 못 세주기 때문에 해결 안 됨!!

!! level order traversal 개념 배움!!
*/