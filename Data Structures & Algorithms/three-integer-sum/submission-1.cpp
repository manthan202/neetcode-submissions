class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size=nums.size();
        for (int k=0; k<size; k++) {
            if (k>0 && nums[k]==nums[k-1]) continue;
            int i=k+1, j=size-1;
            while (i<j) {
                if (nums[i]+nums[j]+nums[k]>0) {
                    j--;
                    while (i<j && nums[j]==nums[j+1]) j--;
                } else if (nums[i]+nums[j]+nums[k]<0) {
                    i++;
                    while (i<j && nums[i]==nums[i-1]) i++;
                } else {
                    vector<int> triplet={nums[k], nums[i], nums[j]};
                    result.push_back(triplet);
                    i++;
                    j--;
                    while (i<j && nums[j]==nums[j+1]) j--;
                    while (i<j && nums[i]==nums[i-1]) i++;
                }
            }
        }
        return result;
    }
};
