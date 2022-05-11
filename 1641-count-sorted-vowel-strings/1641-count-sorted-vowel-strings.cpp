class Solution {
private:
    int limit;
    int ans = 0;
    
public:
    void recurs_call(int size, int idx){
        // end case
        if(size == limit){
            ans++;
            return;
        }
        
        for(int i=idx; i<5; i++)
              recurs_call(size+1, i);  
    }
    
    int countVowelStrings(int n) {
        
        limit = n;
        recurs_call(0, 0);
        
        return ans;
    }
};