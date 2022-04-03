class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // STL에 있는 next_permutation 함수 쓰면 한 줄에 해결 가능하긴 함
        // next_permutation(nums.begin(), nums.end());
        
        // 1.
        int size = nums.size(), k, l;
        for(k=size-2; k>=0; k--){
            if(nums[k] < nums[k+1])
                break;
        }
        
        // 1-1)
        if(k<0)
            reverse(nums.begin(), nums.end());
        // 2.
        else{
            for(l=size-1; l>k; l--){
                if(nums[k] < nums[l])
                    break;
            }
            // 3. & 4.
            swap(nums[k], nums[l]);
            // sort(nums.begin()+k+1, nums.end());
            reverse(nums.begin()+k+1, nums.end());

        }
    }
};

/*
1. Find the largest index k such that nums[k] < nums[k + 1]. 
1-1) If no such index exists, just reverse nums and done.
2. Find the largest index l > k such that nums[k] < nums[l].
3. Swap nums[k] and nums[l]
4. Sort or Reverse sub-array nums[k + 1:]
*/