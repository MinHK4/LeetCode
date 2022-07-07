class Solution {
    
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        
        // 글자 수가 맞아떨어지지 않는 경우
        if(s3.length() != s1.length() + s2.length())
            return false;

        // dp[i][j]는 str1의 i, str2의 j에서 InterLeaving 할 수 있는가 판단
        bool dp[s1.length()+1][s2.length()+1];
        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                
                // 베이스 케이스 아무것도 없는 상태
                if(i==0 && j==0)
                    dp[i][j] = true;
                
                // str1에서 아무것도 안 쓴 상태
                else if(i == 0)
                    dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                
                // str2에서 아무것도 안 쓴 상태
                else if(j == 0)
                    dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                
                // 양쪽 모드 체크해줘야 하는 상태
                else
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1] );
            }

        return dp[s1.length()][s2.length()];
    }  
};