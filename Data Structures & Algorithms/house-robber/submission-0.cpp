class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> arr(nums.size()+1);
        arr[0]=0;
        arr[1]=nums[0];
        for(int i=2; i<nums.size()+1; i++) arr[i]=max(arr[i-2]+nums[i-1], arr[i-1]);
        return arr[nums.size()];
    }
};
