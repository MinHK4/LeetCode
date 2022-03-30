class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool find = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // 이분탐색을 이용해서 어떤 행에서 봐야할지 먼저 찾고
        // 각 열의 시작점을 잡아서 그것보다는 크다는 전제를 바탕으로 했는데
        // 아예 타겟이 그것보다 작은 경우가 있을 수 있어서 t_row 초기화 0으로 해주기!!
        int lo = 0;
        int hi = rows-1;
        int t_row = 0;
        while(lo <= hi){
            int mid = (lo+hi) / 2;
            if(matrix[mid][0] <= target){
                t_row = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        
        // 이분 탐색을 이용해서 해당 행에서 target이 있는지 열을 훑어보기
        lo = 0;
        hi = cols-1;
        while(lo <= hi){
            int mid = (lo+hi) / 2;
            if(matrix[t_row][mid] == target){
                find = true;
                break;
            }
            else if(matrix[t_row][mid] < target)
                lo = mid + 1;
            else
                hi = mid -1;
        }
        
        return find;
    }
};