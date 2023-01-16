class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        
        for(auto interval : intervals){
            if(cur_end < interval[0]){
                ans.push_back({cur_start, cur_end});
                cur_start = interval[0];
            }
            cur_end = max(cur_end, interval[1]);
        }
        ans.push_back({cur_start, cur_end});
        
        return ans;
    }
};