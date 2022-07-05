class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int ans = 0;
        if(nums.size()==0)
            return ans;
        
        set<int> s;
        for(auto num : nums)
            s.insert(num);
        
        int last;
        int cnt = 0;
        for(auto x : s){
            if(cnt == 0){
                cnt = 1;
                last = x;
            }
            else{
                if(last+1 == x){
                    cnt++;
                }
                else{
                    ans = max(ans, cnt);
                    cnt = 1;
                }
                last = x;
            }
        }        
        ans = max(ans, cnt);
        return ans;
    }
};