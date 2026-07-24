class Solution {
public:
    int climbStairs(int n) {
        vector<int> DP(n+1); //DP[i] represents the number of distinct ways needed to climp upto step i
        DP[0]=1;
        DP[1]=1;
        for(int i=2; i<=n; i++){
            DP[i]=DP[i-2]+DP[i-1];
        }
        return DP[n];

    }
};
