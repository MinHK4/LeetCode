class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        // 우선 pivot이 있는 위치를 찾아야 함
        // 이분탐색을 하면서 mid를 가장 왼쪽 끝 값과 비교하면서
        // 값이 정렬되어 있지 않은 포인트를 찾아줌
        int lo = 0;
        int hi = n-1;        
        while(lo < hi){
            int mid = (lo+hi) / 2;
            if(nums[mid] > nums[hi]) lo = mid+1;
            else hi = mid;
        }
        
        // 그러고 나서 평범한 이분탐색을 돌리되
        // 값 참조할때 pivot인덱싱만 추가로 고려해서 돌려주기
        int piv = lo;
        lo = 0;
        hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi) / 2;
            int realmid = (mid+piv) % n;
            if(nums[realmid] == target) return realmid;
            if(nums[realmid] < target)
                lo = mid + 1;
            else
                hi = mid -1;
        }
        return -1;
    }
};