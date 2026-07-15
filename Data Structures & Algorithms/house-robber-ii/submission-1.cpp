class Solution {
public:
    int rob(vector<int>& nums) {
        int res1, res2;
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        //Case 1: Assuming last element is absent
        vector<int> arr(nums.size()-1);
        arr[0]=nums[0];
        arr[1]=max(nums[1], nums[0]);
        for(int i=2; i<nums.size()-1; i++) arr[i]=max(arr[i-2]+nums[i], arr[i-1]);
        res1=arr[nums.size()-2];
        
        //Case 2: Assuming first element is absent
        arr[0]=nums[1];
        arr[1]=max(nums[1], nums[2]);
        for(int i=2; i<nums.size()-1; i++) arr[i]=max(arr[i-2]+nums[i+1], arr[i-1]);
        res2=arr[nums.size()-2];

        return max(res1, res2);
    }
};
