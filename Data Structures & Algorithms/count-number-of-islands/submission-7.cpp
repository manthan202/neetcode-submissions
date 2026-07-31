class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result=0;
        vector<bool> visited(grid.size()*grid[0].size(), false); // (i,j): grid[0].size()*i+j 
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && !visited[i*grid[0].size()+j]){
                    dfs(grid, i, j, visited);
                    result++;
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<bool>& visited){
        if(i>grid.size()-1 || i<0 || j>grid[0].size()-1 || j<0 || grid[i][j]=='0' || visited[i*grid[0].size() + j]) return;
        visited[i*grid[0].size()+j]=true;
        dfs(grid, i+1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j-1, visited); 
    }

};
