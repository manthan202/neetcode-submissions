class Solution {
public:
    int findMin(vector<int> &nums) { // Striver way: pick the sorted half and take the minimum of it and discard it after
        int i=0, j=nums.size()-1, mid, ans=INT_MAX;
        while(i<=j) {
            mid=j+(i-j)/2;
            if (nums[i]>=nums[mid]){
                ans=min(nums[mid], ans);
                j=mid-1;
            } else {
                ans=min(nums[i], ans);
                i=mid+1;
            }
        }
        return ans;
    }
};
