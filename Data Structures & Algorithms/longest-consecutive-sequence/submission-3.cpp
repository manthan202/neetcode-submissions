class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        unordered_map<int,int> mp;
        for (int i=0; i<nums.size(); i++) mp[nums[i]]++; //<ele,freq>

        int sequence=1, max_sequence=1;
        for (int n : nums) {
            while (true) {
                if (mp.find(n+1)!=mp.end()) {
                    sequence++;
                    n++;
                }
                else {
                    max_sequence=max(max_sequence, sequence);
                    sequence=1;
                    break;
                }
            } 
        }

        return max_sequence;

    }
};
