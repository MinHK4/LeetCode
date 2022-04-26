class Edge{
public: 
    int src, dst, cost;
};

class sortby{
public:
    bool operator()(const Edge a, const Edge b){
        return a.cost < b.cost;
    }  
};

class Solution {
private:
    vector<int> rank;
    vector<int> parent;

public:
    
    int Find(int cur){
        if(parent[cur] != cur)
            parent[cur] = Find(parent[cur]);
        return parent[cur];
    }
    
    void Union(int a, int b){
        if(rank[a] < rank[b])
            parent[a] = b;
        else if(rank[a] > rank[b])
            parent[b] = a;
        else{
            parent[b] = a;
            rank[a]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // Graph edge info and sort by cost
        vector<Edge> v;
        int nums = points.size();
        for(int i=0; i<nums; i++){
            for(int j=i+1; j<nums; j++){
                Edge temp;
                temp.src = i;
                temp.dst = j;
                temp.cost = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back(temp);
            }
        }
        sort(v.begin(), v.end(), sortby());
        
        // Disjoint Set + MST
        rank.resize(nums, 0);
        parent.resize(nums);
        for(int i=0; i<nums; i++)
            parent[i] = i;
        
        int ans = 0;
        for(Edge x : v){
            int roota = Find(x.src);
            int rootb = Find(x.dst);
            if(roota == rootb)
                continue;            
            ans += x.cost;
            Union(roota, rootb);
        }
        
        return ans;
    }
};

/*
MST 풀이 with Disjoint Set
*/