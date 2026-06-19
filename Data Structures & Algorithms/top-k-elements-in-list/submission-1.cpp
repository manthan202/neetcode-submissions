class Solution {
public:
    pair<int,int> find(int n, vector<vector<int>>& result) { // returns the index of the result array where n is
        for (int i=0; i<result.size(); i++) {
            for (int j=0; j<result[i].size(); j++) {
                if (result[i][j]==n) return {i,j};
            }
        }
        return {-1,-1};
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> result(nums.size() + 1); // index:frequency and value:vector of values
        for (int i=0; i<nums.size(); i++) {
            pair<int,int> j=find(nums[i],result);
            if (j.first==-1) result[1].push_back(nums[i]);
            else {
                result[j.first+1].push_back(nums[i]);
                result[j.first].erase(result[j.first].begin()+j.second);
            }
        }

        vector<int> answer;
        for (int i=result.size()-1; i>=0; i--) {
            for (int j=0; j<result[i].size(); j++) {
                if (k>0) {
                    k--;
                    answer.push_back(result[i][j]) ;
                }
            }
        }
        return answer;
    }
};
