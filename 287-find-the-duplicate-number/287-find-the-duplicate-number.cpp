class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> cnt(len, 0);
        int ans;        
        for(int i=0; i<len; i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]] == 2){
                ans = nums[i];
                break;
            }            
        }
        
        return ans;
    }
};