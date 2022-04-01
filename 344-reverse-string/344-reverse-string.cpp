class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // STL reverse function 이용하면 한 줄에 해결되기는 함
        // return reverse(s.begin(), s.end());  
        
        int len = s.size();
        for(int i=0; i<(len+1)/2; i++){
            char temp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = temp;
        }
    }
};