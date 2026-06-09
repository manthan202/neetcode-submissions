class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strs1;
        for (int i=0; i<strs.size(); i++) {
            string x=strs[i];
            sort(x.begin(), x.end());
            strs1.push_back(x);
        }
        unordered_map<string,vector<int>> map;
        for (int i=0; i<strs1.size(); i++) {
            map[strs1[i]].push_back(i);
        }

        vector<vector<string>> result;
        for (auto i:map) {
            vector<string> ele;
            for (int j=0; j<i.second.size(); j++) ele.push_back(strs[i.second[j]]);
            result.push_back(ele);
        }
        return result;
    }
};
