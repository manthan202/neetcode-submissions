class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1') {
                    grid[i][j]='*';
                    q.push({i,j});
                    bfs(grid, q);
                    result++;
                }
            }
        }
        return result;
    }

    void bfs(vector<vector<char>>& grid, queue<pair<int, int>>& q){
        while(!q.empty()){
            pair<int, int> par=q.front();
            q.pop();
            int i=par.first, j=par.second;
            
            if(i<grid.size()-1 && grid[i+1][j]=='1') {
                q.push({i+1, j});
                grid[i+1][j]='*';
            }
            if(i>0 && grid[i-1][j]=='1') {
                q.push({i-1, j});
                grid[i-1][j]='*';
            }
            if(j<grid[0].size()-1 && grid[i][j+1]=='1') {
                q.push({i, j+1});
                grid[i][j+1]='*';
            }
            if(j>0 && grid[i][j-1]=='1') {
                q.push({i, j-1});
                grid[i][j-1]='*';
            }
        }
    }
};
