class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> DP(nums.size(), 1); // each element represents the length of LIS ending at that index
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]) DP[i]=max(DP[i], DP[j]+1);
            }
        }
        int result=0;
        for(int i : DP) result=max(result, i);
        return result;
    }
};
