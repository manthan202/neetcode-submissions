class Solution {
public:
    int findMin(vector<int> &nums) {
        int res=INT_MAX;
        int left=0;
        int right=nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return min(nums[0], nums[1]);
        while(left<right){
            int mid=left+(right-left)/2 ;
            res=min(res, nums[mid]);
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        return nums[left];
    }
};
