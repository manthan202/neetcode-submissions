class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int components=0;
        vector<vector<int>> adjacency_list(n);
        for(int i=0; i<edges.size(); i++){
            adjacency_list[edges[i][0]].push_back(edges[i][1]);
            adjacency_list[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n);
        for(int i=0; i<n; i++){ 
            if(!visited[i]) {
                dfs(i, adjacency_list, visited);
                components++;
            }
        }

        return components;
    }

private:
    void dfs(int i, vector<vector<int>>& adjacency_list, vector<bool>& visited){
        if(visited[i]) return ;
        visited[i]=true;
        for(int j=0; j<adjacency_list[i].size(); j++){
            dfs(adjacency_list[i][j], adjacency_list, visited);
        }
    }
};
