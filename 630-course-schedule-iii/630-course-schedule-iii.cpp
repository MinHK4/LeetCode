class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        // 제한기간을 기준으로 오름차순으로 정렬
        sort(courses.begin(), courses.end(), 
             [](vector<int> a, vector<int> b){
                 return a[1] < b[1];
             });
        
        for(auto x: courses){
            for(auto y: x)
                cout << y << ' ';
            cout << '\n';
        }
        
        priority_queue <int> pq;
        int sum = 0;
        for(auto course: courses){
            // 제한 기간 안에 되는 강의들 쌓기
            if(sum + course[0] <= course[1]){
                pq.push(course[0]);
                sum += course[0];
            }
            // 안 되는 강의 발생 시 지금까지 모은 강의 중 가장 긴 강의시간 빼고 교체
            else if(!pq.empty() && pq.top() > course[0]){
                sum = sum - pq.top() + course[0];
                pq.pop();
                pq.push(course[0]);
            }
        }        
        
        return pq.size();
    }
};

/*
Greedy 기법으로 접근해서 풀이해야 함!

일단 기본적으로 강의실 문제처럼 제한 시간을 기준으로 오름차순으로 정렬
제한 시간이 지나면 아예 쓸 수 없는 데이터가 되기 때문

그리고 그 제한시간 안에 들어가는 애들을 차곡 차곡 쌓아주는데
이 뜻은 현재의 제한시간보다 현재까지 합친 걸린 시간의 합이 작거나 같다는 것!

따라서 걸리는 시간의 순서는 사실상 무의미하기 때문에
걸리는 시간의 총합이 더 커지는 경우에는 그 중에서 가장 큰 수를 빼주면 된다!

!!!! multiset이나 pq를 이용해서 현재 들어와있는 수 중에서 가장 큰 수를 빼준다 !!!!
*/