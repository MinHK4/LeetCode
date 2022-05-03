class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int start = -1, end = -1, max = INT_MIN;
        
        for(int i=0; i<nums.size();i++){
            if(max > nums[i]){
                if(start == -1)
                    start = i-1;
                while(start-1 >= 0 && nums[start-1] > nums[i])
                    start--;
                end = i + 1;
            }
            else 
                max = nums[i];
        }
        
        return end - start;  
    }
};

/*
현재까지 찾아온 값의 Max보다 작은 원소 등장하면 unsorted한 상황임
따라서 그때는 그 지점보다 작은 값들을 하나씩 찾아내려가고
그 위치보다 높은 인덱스를 설정해주면 됨
*/