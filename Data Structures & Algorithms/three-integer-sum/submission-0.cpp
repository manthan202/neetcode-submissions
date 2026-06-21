class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        set<vector<int>> st;
        for (int i=0; i<nums.size(); i++) mp[nums[i]]++;
        for (int i=0; i<nums.size(); i++) {
            mp.clear();
            for (int j=i+1; j<nums.size(); j++) {
                int ele=-(nums[i]+nums[j]);
                if (mp.find(ele)!=mp.end()) {
                    vector<int> triplet={ele,nums[i],nums[j]};
                    sort(triplet.begin(), triplet.end());
                    st.insert(triplet);
                }
                mp[nums[j]]++;
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
