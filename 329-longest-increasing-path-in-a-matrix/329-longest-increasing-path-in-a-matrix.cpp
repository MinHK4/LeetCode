class Solution {
private:
    vector<vector<int>> dp, dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int row, col;
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        row = matrix.size();
        col = matrix[0].size();
        
        dp.resize(row, vector<int>(col, 0));
        
        int ans = 1;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans = max(ans, dfs(matrix, i, j));
            }
        } 
        return ans;
    }
    
    int dfs(vector<vector<int>>& matrix, int x, int y){
        
        // 이미 탐색을 완료한 경우에는 해당 값 return
        if(dp[x][y])
            return dp[x][y];
        
        // 현재 위치에 도착했으므로 path에 카운트
        dp[x][y] = 1;
        
        // 4가지 방향에 대해서 탐색 돌려보기
        for(auto dir : dirs){
            int nx = x + dir[0];
            int ny = y + dir[1];
            
            // boundary check
            if(nx < 0 || ny < 0 || nx >= row || ny >= col)
                continue;
            // increasing check
            if(matrix[x][y] >= matrix[nx][ny])
                continue;
            
            dp[x][y] = max(dp[x][y], 1+dfs(matrix, nx, ny));
        }
        
        return dp[x][y];
    }
};