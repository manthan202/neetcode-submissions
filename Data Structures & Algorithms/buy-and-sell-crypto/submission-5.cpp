class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int right=1, bestBuy=prices[0], maxProfit=0;
        while(right<prices.size()){
            bestBuy=min(bestBuy, prices[right-1]);
            maxProfit=max(maxProfit, prices[right]-bestBuy);
            right++;
        }
        return maxProfit;
    }
};
