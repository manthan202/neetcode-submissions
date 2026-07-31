class Solution {
public:  //This is O(nlog(n)
    int lengthOfLIS(vector<int>& nums) { //insert the next element after value we are going to insert in the nums
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>temp.back()) temp.push_back(nums[i]);
            else {
                auto ind=lower_bound(temp.begin(), temp.end(), nums[i]);
                *ind=nums[i];
            }
        }
        return temp.size();
    }
};
