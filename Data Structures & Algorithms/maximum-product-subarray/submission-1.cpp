class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        int leftPrefix=1;
        int rightPrefix=1;
        for(int i=0; i<n; i++){
            leftPrefix= leftPrefix==0? nums[i]:leftPrefix*nums[i];
            rightPrefix= rightPrefix==0? nums[i]:rightPrefix*nums[n-i-1];
            ans=max(leftPrefix, max(rightPrefix,ans));
        }
        return ans;
    }
};
