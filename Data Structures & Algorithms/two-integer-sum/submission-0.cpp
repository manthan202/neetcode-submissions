class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for (int i=0; i<nums.size(); i++) {
            if (mp.find(target-nums[i])!=mp.end()) {
                int ele1=min(mp[target-nums[i]],i);
                int ele2=max(mp[target-nums[i]],i);
                return {ele1,ele2};
            } else mp[nums[i]]=i;
        }
    }
};
