class Solution {
private:
    vector<string> hash = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    vector<string> ans;
    
public:
    void recurs_comb(string str, int idx){
        // end case
        if(idx >= str.size()){
            ans.push_back(str);
            return;
        }
        
        // 각 자리 수에서 넣을 수 있는 문자 다 넣어서 모두 조합하기
        int num = str[idx] - '0';
        for(auto x : hash[num]){
            str[idx] = x;
            recurs_comb(str, idx+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {     
        if(digits != "")
            recurs_comb(digits, 0);
        return ans; 
    }
};

/*
BruteForce + Backtracking 기법
*/