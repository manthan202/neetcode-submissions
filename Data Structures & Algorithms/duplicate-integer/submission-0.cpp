class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> map;
        for (int i=0; i<n; i++) {
            if (map[nums[i]]) return true;
            map[nums[i]]++;
        }
        return false;
    }
};