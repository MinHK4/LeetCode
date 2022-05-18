class Solution {
private:
    
    vector<vector<int>> G, ans;
    vector<int> disc, low;
    int time = 1;
    
public:
    void dfs(int cur, int prev){
        
        disc[cur] = low[cur] = time++;
        
        // 다음 노드 확인해서
        for(auto next : G[cur]){
            // 아직 한 번도 들르지 않았으면
            // 탐색하고 현재의 노드의 깊이 업데이트
            if(disc[next] == 0){
                dfs(next, cur);
                low[cur] = min(low[cur], low[next]);
            }
            // 들르긴 했는데 다음 노드가 이전 노드가 아닌 경우
            // 나를 통해서 온 노드가 아닌 경우이므로 다른 방식으로 도착할 때의 값과
            // 내가 현재 얻는 갈 수 있는 가장 낮은 깊이 비교해서 업데이트
            else if(next != prev)
                low[cur] = min(low[cur], disc[next]);
            
            // 다음 노드가 탐색할 수 있는 가장 낮은 깊이보다 현재 온 깊이가 더 낮을 때
            // 자신으로부터 탐색되고 다른 순환해서 높은 노드로 돌아갈 수 없을 때
            if(low[next] > disc[cur])
                ans.push_back({cur, next});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        G.resize(n);
        disc.resize(n, 0);
        low.resize(n, 0);
        
        for(auto con : connections){
            G[con[0]].push_back(con[1]);
            G[con[1]].push_back(con[0]);
        }
        
        dfs(0, -1);
        
        return ans;
    }
};

/*
Naive하게 BFS로 탐색해서 확인

-- 시간 초과!

사실상 그래프는 개념 및 이론 문제라서 풀이 적용
 Tarjan's Bridge-Finding Algorithm
*/