class Solution {
private:
    vector<vector<int>> ans;
    vector<int> check;
    int limit, target;
        
public:
    void recurs_call(int idx){
        
        // 현재까지의 배열 상태 확인
        int sum = 0;
        for(auto x: check)
            sum += x;

        // end case - 개수 다 찼는지 + 목표값이랑 맞는지
        if(check.size() == limit){
            if(sum == target)
                ans.push_back(check);
            return;
        }

        // 숫자 하나씩 넣어보면서 체크
        for(int i=idx; i<=9; i++){
            // 이미 목표값 넘으면 체크하지 말기
            if(sum+i > target)
                break;
            
            check.push_back(i);
            recurs_call(i+1);
            check.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {    
        
        limit = k;
        target = n;
        recurs_call(1);
        
        return ans;
    }
};