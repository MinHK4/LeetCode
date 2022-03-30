class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool find = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
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