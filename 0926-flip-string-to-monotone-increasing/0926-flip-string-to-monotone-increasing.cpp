class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int str_size = s.size();        
        vector<vector<int>> dp(str_size+1, vector<int>(2, 0));

        for(int i=1; i<=str_size; i++){
            dp[i][0] = dp[i-1][0] + (s[i-1] == '1');
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (s[i-1] == '0');    
        }
        
        return min(dp[str_size][0], dp[str_size][1]);
    }
};