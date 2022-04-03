class Solution {
public:
    bool isPalindrome(int x) {
        
        /* using STL to_string, reverse
        
        string str = to_string(x);
        string rev = str;
        reverse(rev.begin(), rev.end());
        
        return str == rev;
        */
        
        // 음수이거나 1의 자리수가 0이면 바로 false 반환
        if(x < 0) return false;
        
        // 1의 자리부터 한 자리씩 받아서 올려주는 방식으로 숫자 reverse 구현
        // rev * 10에서 overflow 나올 수 있으므로 long long으로 선언
        long long temp = (long long)x;
        long long rev = 0;
        while(temp){
            rev = rev*10 + temp%10;
            temp /= 10;
        }
        return rev == x;
    }
};