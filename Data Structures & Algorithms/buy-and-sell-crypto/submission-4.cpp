class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==1) return 0;
        if (prices.size()==2) return max(0,prices[1]-prices[0]);
        int bestBuy=prices[0], sell=1, maxprofit=max(0, prices[1]-bestBuy); // Apna College: imagine we are taking max(profits) considering the best day to buy the stock for each day possible to sell the stock
        while (sell<prices.size()-1){
            
            sell++;
            bestBuy=min(prices[sell-1], bestBuy);
            maxprofit=max(maxprofit, prices[sell]-bestBuy);
        }
        return maxprofit;
    }
};
