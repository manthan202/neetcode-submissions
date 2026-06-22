class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, mid;
        while (i<=j) {
            mid=(i+j)/2;
            if(nums[mid]==target) return mid;
            else if (nums[mid]>=nums[i]) { // left side is sorted
                if (nums[i]<=target && nums[mid]>=target) j=mid-1;
                else i=mid+1;
            } else {
                if (nums[j]>=target && nums[mid]<=target) i=mid+1;
                else j=mid-1;
            }
        }
        return -1;
    }
};
