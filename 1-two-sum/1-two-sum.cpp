class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans(2);
        int len = nums.size();
        bool flag = false;
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if(nums[i]+nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                    flag = true;
                    break;
                }    
            }
            if(flag)
                break;
        }
        return ans;
    }
};