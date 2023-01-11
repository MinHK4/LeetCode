class Solution {
public:
    vector<vector<int>> adjList;
    
    int dfs(vector<bool>& hasApple, int cur, int prev, int depth){
        int result = 0;
        
        for(auto next : adjList[cur]){
            if(next != prev){
	            
                int dfs_value = dfs(hasApple, next, cur, depth+1);
                if(dfs_value)
                    result += dfs_value - depth;
            }       
        }

        return result || hasApple[cur] ? result + depth : 0; 
        
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjList.resize(n);
        
        for(vector<int> &e:edges)
            adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
        
        return dfs(hasApple, 0, -1, 0) * 2;
    }
};