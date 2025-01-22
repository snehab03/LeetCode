// 1765. Map of Highest Peak
// Link : https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22
// The problem involves assigning heights to land cells such that the height increases with distance from the nearest water cell. Since water 
// cells are the starting points with height 0, we use Multi-Source BFS to propagate heights level by level. All water cells are added to the 
// queue initially, and their neighbors are processed iteratively. At each step, unvisited neighboring cells are assigned a height incremented 
// by 1 from the current cell. This ensures that heights are calculated in the order of increasing distance, guaranteeing correctness and 
// efficiency.


class Solution {
public:
    typedef pair<int,int> p;
    vector<vector<int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> height(m , vector<int> (n,-1));
        queue<p> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int N = q.size();
            while(N--){
                p curr = q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                for(auto &dir:directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];
                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1 ){
                        height[i_][j_] = height[i][j] + 1;
                        q.push({i_,j_});
                    }
                }
            }
        }
        return height;
    }
};
