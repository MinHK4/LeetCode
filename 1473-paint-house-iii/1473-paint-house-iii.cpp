class Solution {
private:
    int dp[101][101][21] = {};
    
    
public:
    int dfs(vector<int>& houses, vector<vector<int>>& cost,
            int idx, int left, int last_clr) {
        
        // 바운더리 체크 [남은 타겟이 0이면 성공 아니면 실패]
        if (idx >= houses.size() || left < 0)
            return left == 0 ? 0 : 1000001;
        
        // 현재 집이 이미 칠해져 있는 경우
        // 다음 집으로 넘어가는데 target만 체크해주기 (이전 집과 다른 색깔이면 제거)
        if (houses[idx] != 0)
            return dfs(houses, cost, idx + 1, left-(last_clr!=houses[idx]), houses[idx]);      
        
        // Memoization 기법
        if (dp[idx][left][last_clr])
            return dp[idx][left][last_clr];
        
        // 현재 집에서 각각의 칼라를 칠해보고 그에 따른 탐색을 추가로 진행해보고
        // 그중에서 최소값을 찾아서 현재의 dp에 저장
        int res = 1000001;
        for (int clr = 1; clr <= cost[idx].size(); clr++) {
            res = min(res, cost[idx][clr-1] + dfs(houses, cost, idx + 1, left-(last_clr!=clr), clr));
        }
        return dp[idx][left][last_clr] = res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        
        int res = dfs(houses, cost, 0, target, 0);
        
        return res > 1000000 ? -1 : res;
    }
};

/*
DP Top-Down Approach

DP[idx][left][last_color] 
: i번째 집에서 taget이 left만큼 남아있고 이전에 들렀던 집의 색깔이 last_color였을 때 페인트 칠하는데 필요한 최소값

last-color까지 총 3차원 DP여야 하는 이유는 같은 위치에 같은 left의 경우라고 하더라도
이전까지 어떤 방식으로 칠해왔는지가 다를 수 있기 때문에 각각의 경우를 다 구분하고 통합해 최소값을 만들기 위해서 필요함
*/