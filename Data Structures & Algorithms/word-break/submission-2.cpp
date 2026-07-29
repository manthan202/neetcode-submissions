class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> hashSet(wordDict.begin(), wordDict.end());

        int maxLen=0;
        for(string u : wordDict) maxLen=max(maxLen, (int)u.length());

        vector<bool> DP(s.length()+1, false);
        DP[0]=true;

        for(int i=1; i<=s.length(); i++){
            for(int j=i-1; j>=max(0, i-maxLen); j--){
                if(DP[j] && hashSet.find(s.substr(j,i-j))!=hashSet.end()) {
                    DP[i]=true;
                    break;
                }
            }
        }
        return DP[s.length()];
    }
};
