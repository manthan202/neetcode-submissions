class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0, right=nums.size()-1, result=INT_MAX;
        while(left<=right){
            int mid=(right-left)/2+left;
            if(nums[mid]<nums[right]){
                result=min(result, nums[mid]);
                right=mid-1;
            }else{
                result=min(result, nums[left]);
                left=mid+1;
            }
        }
        return result;
    }
};
