class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // We use amount + 1 as our "infinity" because the answer can never 
        // exceed the amount itself (e.g., all 1-cent coins).
        vector<int> DP(amount + 1, amount + 1);
        
        // Base case: 0 coins needed to make amount 0
        DP[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            // Check every coin for the current amount 'i'
            for(int j = 0; j < coins.size(); j++){
                // If the coin is smaller than or equal to the current amount
                if(coins[j] <= i){
                    // Take the minimum of what we have so far, or the 
                    // cost to make the remainder PLUS 1 for the current coin
                    DP[i] = min(DP[i], DP[i - coins[j]] + 1);
                }
            }
        }
        
        // If DP[amount] is still "infinity", we couldn't make the amount
        if (DP[amount] > amount) {
            return -1;
        }
        
        return DP[amount];
    }
};