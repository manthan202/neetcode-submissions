class Solution {
public:
    int minLength=INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        helper(coins, amount, 0, 0);
        if(minLength==INT_MAX) return -1;
        return minLength;
    }

private:
    void helper(vector<int>& nums, int amount, int start, int length){
        for(int i=start; i<nums.size(); i++){
            if(nums[i]==amount){
                minLength=min(minLength, length+1);
            }else if(nums[i]>amount){
                continue;
            }else{
                helper(nums, amount-nums[i], i, length+1);
            }
        }
    }
};
