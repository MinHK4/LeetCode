class Solution {
private:
    vector<vector<char>> hash;
    vector<string> ans;
    
public:
    void hash_set(){
        hash.resize(10);
        
        hash[2].push_back('a');
        hash[2].push_back('b');
        hash[2].push_back('c');
        
        hash[3].push_back('d');
        hash[3].push_back('e');
        hash[3].push_back('f');
        
        hash[4].push_back('g');
        hash[4].push_back('h');
        hash[4].push_back('i');
        
        hash[5].push_back('j');
        hash[5].push_back('k');
        hash[5].push_back('l');
        
        hash[6].push_back('m');
        hash[6].push_back('n');
        hash[6].push_back('o');
        
        hash[7].push_back('p');
        hash[7].push_back('q');
        hash[7].push_back('r');
        hash[7].push_back('s');
        
        hash[8].push_back('t');
        hash[8].push_back('u');
        hash[8].push_back('v');
        
        hash[9].push_back('w');
        hash[9].push_back('x');
        hash[9].push_back('y');
        hash[9].push_back('z');
    }
    
    void recurs_comb(string str, int idx){
        
        // end case
        if(idx >= str.size()){
            ans.push_back(str);
            return;
        }
        
        // 각 자리 수에서 넣을 수 있는 문자 다 넣어서 모두 조합하기
        int num = str[idx] - '0';
        for(char x : hash[num]){
            str[idx] = x;
            recurs_comb(str, idx+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        hash_set();
        
        if(digits != "")
            recurs_comb(digits, 0);
        return ans; 
    }
};

/*
BruteForce + Backtracking 기법
*/