class Solution {
public:
    int rob(vector<int>& nums) { // nums[i] represents the amount of money the ith house has 
        vector<int> DP(nums.size()+1); // maximum amount of money you can rob from ith house
        DP[0]=0;
        DP[1]=nums[0];
        for(int i=2; i<nums.size()+1; i++){
            DP[i]=max(DP[i-1], DP[i-2]+nums[i-1]);
        }
        return DP[nums.size()];
    }
};
