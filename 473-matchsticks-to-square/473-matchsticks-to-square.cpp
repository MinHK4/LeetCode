class Solution {
private:
    vector<int> Square, org;
    
public:
    
    bool dfs(int idx, int target){
        
        // 모든 성냥을 다 사용했을 때 사각형인지 확인
        if(idx == org.size())
            return *min_element(Square.begin(), Square.end()) == *max_element(Square.begin(), Square.end());
        
        // 각 성냥을 모든 변에 사용하는 경우 모두 돌려보기
        for(int i=0; i<4; i++){
            
            // 현재 성냥을 여기다가 넣으면 초과하므로 PASS
            if(Square[i]+org[idx] > target)
                continue;
            
            Square[i] += org[idx];
            if(dfs(idx+1, target))
                return true;
            Square[i] -= org[idx];
        }
        
        // 다 돌려봤는데도 못 찾은 경우
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        // 정사각형이 되기 위해서는 한 변의 길이는 총합의 4분의 1이어야 함
        int sum = 0;
        for(auto x: matchsticks)
            sum += x;
        
        // 한변의 목표치를 넘는지 최대한 빨리 확인하기 위해서 큰 수를 먼저 확인함
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        
        Square.resize(4, 0);
        org = matchsticks;
        
        return dfs(0, sum/4);
    }
};

/*
성냥의 조합을 하나씩 만드는 것보다
변의 조합을 하나씩 만드는 것이 시간복잡도가 훨씬 적어짐
4^15로 2^30안에 해결 가능

----
그래도 시간초과가 발생하기는 하므로 조금 더 세부적으로 케이스 처리해줘야 함


*/