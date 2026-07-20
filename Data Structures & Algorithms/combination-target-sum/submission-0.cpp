class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backTracking(nums, target, 0, current);
        return result;
    }

    void backTracking(vector<int>& nums, int target, int start, vector<int>& current){
        for(int i=start; i<nums.size(); i++){
            if(nums[i]>target) ;
            else if(nums[i]==target) {
                current.push_back(nums[i]);
                result.push_back(current);
                current.pop_back();
            }else{
                current.push_back(nums[i]);
                backTracking(nums, target-nums[i], i, current);
                current.pop_back();
            }
        }
    }
};