class Solution {
public:
    int candy(vector<int>& ratings) {
        
        stack<pair<int, int>> s;
        s.push({ratings[0], 0});
        
        vector<int> answer(ratings.size(), 1);
        for(int i=1; i<ratings.size(); i++){
            
            // 현재가 이전보다 높거나 같은 순위인 경우
            int prev_rank = s.top().first;
            int prev_idx = s.top().second;
            if(prev_rank <= ratings[i]){
                
                // 지금까지 스택에 쌓아놨던 미정값 처리해주기
                int last = 1;
                while(!s.empty()){
                    pair <int, int> cur = s.top();
                    s.pop();
                    answer[cur.second] = max(answer[cur.second], last);
                    last++;
                }
                
                if(prev_rank == ratings[i])
                    answer[i] = 1;
                if(prev_rank < ratings[i])
                    answer[i] = answer[prev_idx]+1;
            }
            
            s.push({ratings[i], i});
        }
        
        // 남은 스택 값 한번 더 처리
        int last = 1;
        while(!s.empty()){
            pair <int, int> cur = s.top();
            s.pop();
            answer[cur.second] = max(answer[cur.second], last);
            last++;
        }
        
        int sum = 0;
        for(auto x: answer){
            sum += x;
            cout << x << ' ';
        }
        
        return sum;
    }
};