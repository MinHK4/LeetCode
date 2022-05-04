class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int end = len-1;
        int ans = 0;
        while(start < end){
            while(k-nums[start] <= nums[end] && start < end){
                if(k-nums[start] == nums[end]){
                    end--;
                    ans++;
                    break;
                }
                end--;   
            }
            start++;
        }
        
        return ans;
    }
};

/*
sort를 해놓으면 start를 기준으로 K를 만들 수 있는 수 end에 대해서
이후에 다시 살펴볼 필요가 없어지기 때문에 피벗을 점점 떙겨올 수 있음

start는 외부 while문에서 기준점을 잡는 방식으로 하나씩 전진하고
end는 내부 while문에서 기준점과 더했을 때 k보다 작거난 같은 수를 찾을 때까지 전진
*/