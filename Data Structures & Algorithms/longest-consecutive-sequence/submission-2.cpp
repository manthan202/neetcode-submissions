class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int,int> mp; // ele,freq
        for (int i=0; i<nums.size(); i++) mp[nums[i]]++;

        int sequence=1, max_sequence=1;
        vector<pair<int,int>> nums_pairs(mp.begin(), mp.end());
        for (int i=1; i<nums_pairs.size(); i++) {
            if (nums_pairs[i].first-nums_pairs[i-1].first==1) {
                sequence++;
                max_sequence=max(max_sequence, sequence);
            } else sequence=1;
        }

        return max_sequence;
    }
};
