class Solution {
public:
    set<pair<int, int>> result;
    set<pair<int, int>> visited;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool b1, b2;
        result.insert({0, heights[0].size()-1});
        result.insert({heights.size()-1, 0});
        for(int i=0; i<heights.size(); i++){
            pair<int, int> par;
            par.first=i;
            for(int j=0; j<heights[0].size(); j++){
                visited.clear();
                b1=false;
                b2=false;
                par.second=j;
                helper(heights, b1, b2, par, par);
            }
        }

        vector<vector<int>> ans;
        for (auto p : result) {
            ans.push_back({p.first, p.second});
        }
        return ans;

    }

private:
    void helper(vector<vector<int>>& heights, bool& atlantic, bool& pacific, pair<int, int> og, pair<int, int> curr){
        int i=curr.first, j=curr.second;
        int height=heights[curr.first][curr.second];



        if(result.find(curr)!=result.end()) {
            result.insert(og);
            return;
        }

        if(visited.find(curr)!=visited.end()) return;
        else visited.insert(curr);

        if(i == 0) pacific=true;
        else if(j == 0) pacific=true;
        if(i == heights.size()-1) atlantic=true;
        else if(j == heights[0].size()-1) atlantic=true;

        if(atlantic && pacific) {
            result.insert(og);
            return;
        }
        
        curr.second+=1;
        if(curr.second!=heights[0].size() && height>=heights[curr.first][curr.second]) helper(heights, atlantic, pacific, og, curr);
        curr.second-=2;
        if(curr.second >=0 && height>=heights[curr.first][curr.second]) helper(heights, atlantic, pacific, og, curr);
        curr.second+=1;
        curr.first+=1;
        if(curr.second!=heights[0].size() && curr.first!=heights.size() && height>=heights[curr.first][curr.second]) helper(heights, atlantic, pacific, og, curr);
        curr.first-=2;
        if(curr.first>=0 && height>=heights[curr.first][curr.second]) helper(heights, atlantic, pacific, og, curr);

    }

};
