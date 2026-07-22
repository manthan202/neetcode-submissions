class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> DP(amount+1, amount+1); // size is amount+1 and element values is also amount+1 since we are going to take min of lengths and they will always be less than amount+1 since denominations are not bellow 1 
        //DP[i] min number of coins needed to make up amount i

        sort(coins.begin(), coins.end());
        if(coins[0]>amount) return -1;
        DP[0]=0;
        DP[coins[0]]=1;
        for(int i=coins[0]+1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if (coins[j]<=i && DP[i-coins[j]]!=amount+1){
                    if(i-coins[j]>=coins[0] || i==coins[j]) DP[i]=min(DP[i-coins[j]]+1, DP[i]);
                }
            }
        }
        if(DP[amount]==amount+1) return -1;
        return DP[amount];
    }
};
