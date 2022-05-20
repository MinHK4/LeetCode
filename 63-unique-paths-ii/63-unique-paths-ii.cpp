class Solution {
private:
    vector<vector<int>> dp;
    int row, col;
    
public:
    int dfs(vector<vector<int>>& obstacleGrid, int x, int y){
        
        // boundary check
        if(x >= row || y >= col)
            return 0;
        
        // obstacle check
        if(obstacleGrid[x][y])
            return 0;
        
        // memoization
        if(dp[x][y])
            return dp[x][y];
        
        // target check
        if(x==row-1 && y==col-1){
            if(!obstacleGrid[x][y])
                return dp[x][y] = 1;
            return 0;
        }

        // 탐색해온 값들 합쳐서 정복해주기
        dp[x][y] = dfs(obstacleGrid, x+1, y) + dfs(obstacleGrid, x, y+1);
        return dp[x][y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        dp.resize(row, vector<int>(col, 0));
        
        return dfs(obstacleGrid, 0, 0);
    }
};

/*
DFS로 미로 탐색하는 방식과 동일하게 접근

--틀렸습니다!
별이 없는 케이스.. 이게 가능한 예제라는게?!?!

-- 시간초과
dp로 memoization해줘야 함
dp[x][y] : (x, y)지점에서 별까지 갈 수 있는 path의 개수
*/