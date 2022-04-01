class Solution {
public:
    
    // 주어진 cuts 수 안에 key 값을 넘지않는 sum의 부분 집합들로 나눌 수 있는지 체크
    bool solve(vector<int>& nums, int cuts, int key){
        
        int tmp = 0;
        int cnt = 1;
        for(int num : nums){
            if(tmp + num <= key)
                tmp += num;
            else{
                cnt++;
                tmp = num;
            }
            if(cnt > cuts)
                return false;
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        // 최댓값, sum 구하기
        int max_el = 0;
        int sum = 0;
        for(int num : nums){
            max_el = max(max_el, num);
            sum += num;
        }
        
        
        // 최대값 ~ sum 사이에서 이분탐색을 통해 답 구하기
        int left = max_el;
        int right = sum;
        int ans;
        while(left <= right){
            int mid = (left+right) / 2;
            if(solve(nums, m, mid)){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;     
        }
        
        return ans;
    }
};

/*
Paremetirc Search를 이용한 풀이
Array를 여러개의 sub-array로 나눴을 때의 
largest sum의 최솟값은 가장 큰 원소(원소 1개씩 나눴을 때)
largest sum의 최댓값은 모든 원소들의 합(cut이 1인 경우)
따라서 max_element ~ sum의 사이에서 답이 도출된다

여기서 Parametric Search를 이용할 수 있는데
특정한 key 값을 받아서 해당 key보다 큰 sum을 구성하게 되면 집합을 나눠주면서
주어진 cuts 수 안에서 집합을 나눌 수 있는지를 통해  key가 minimal한 largest sum임을 만족하는지
여부를 구할 수 있고 이는 연속적이게 true/false 값이 결정되게 된다
*/ 


