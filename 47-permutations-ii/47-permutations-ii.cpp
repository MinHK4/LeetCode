class Solution {
private:
    map<int, int>info;
    
    vector<vector<int>> ans;
    vector<int> temp;
    int limit;
    
public:
    void recurs_call(vector<int>& nums, int size){
        
        // end case - 사이즈 다 채웠을 때
        if(size == limit){
            ans.push_back(temp);
            return;
        }
        
        // 순열 만들기 - 현재까지 쓰지 않은 숫자 넣어주기
        // map 자료구조 이용해서 겹치는 숫자는 나온만큼만 활용하기
        for(auto &it : info){
            if(it.second){
                it.second--;
                temp.push_back(it.first);
                
                recurs_call(nums, size+1);
                
                temp.pop_back();
                it.second++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        limit = nums.size();
        
        for(auto x: nums)
            info[x]++;    
        
        recurs_call(nums, 0);
        
        return ans;
    }
};