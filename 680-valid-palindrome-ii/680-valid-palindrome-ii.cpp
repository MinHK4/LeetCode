class Solution {
public:
    bool validPalindrome(string s) {
        
        // 전체 for문은 하나도 걸리는 것이 없는 경우를 체크하기 위함
        for(int i=0, j=s.length()-1; i<j; i++, j--){
            
            // palindrome 아닌 문자 발생시 이 안에서 두 경우 시뮬 돌려보고 ture/false 반환
            if(s[i] != s[j]){
                // case1 : 왼쪽 땡겨서 진행해보기
                int i1 = i+1;
                int j1 = j;
                while(i1 < j1){
                    if(s[i1] != s[j1])
                        break;
                    i1++;
                    j1--;
                }
                
                // case2 : 오른쪽 땡겨서 진행해보기
                int i2 = i;
                int j2 = j-1;
                while(i2 < j2){
                    if(s[i2] != s[j2])
                        break;
                    i2++;
                    j2--;
                }
                
                // 두 경우 중 하나라도 가능하면 true 아니면 false
                if(i1 >= j1 || i2 >= j2)
                    return true;
                return false;
            }
        }
        return true;
    }
};

/*
양쪽 끝에서 확인해오면서 다른 경우 발생 시
한쪽에서 옮겨졌다는 가정 하에 쭉 돌려보기
*/