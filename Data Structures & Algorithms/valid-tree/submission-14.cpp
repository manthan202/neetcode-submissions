class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1){
            if(edges.empty()) return true;
            if(edges[0][0]==0 && edges[0][1]==0) return false;
            else return false;
        }
        vector<vector<int>> neighbors(n); //here neighbors[0] contains neighbors of 0

        for(int i=0; i<edges.size(); i++){
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0; i<n; i++){
            if(neighbors[i].empty()) return false;
        }

        vector<bool> visited(n, false);
        int components=0;
        
        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            if(components>0) return false;
            components++;
            int j=i;
            vector<int> current(n, 0);
            if(!dfs(j, -1, current, neighbors)) return false;
            else {
                for(int k=0; k<current.size(); k++){
                    if(current[k]) visited[k]=true;
                }
            }
        }
        return true;

    }

    bool dfs(int j, int parent, vector<int>& current, vector<vector<int>>& neighbors){
        if(current[j]) return false;
        current[j]+=1;
        bool res=true;
        if(neighbors[j].size()==1 && neighbors[j][0]==parent) return true;
        for(int i=0; i<neighbors[j].size(); i++){
            if(neighbors[j][i]==parent) continue;
            res=res && dfs(neighbors[j][i], j, current, neighbors);
        }
        return res;
    }
};









