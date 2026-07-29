class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //DP[i+1]=true if s from index 0 to i can be segememted
        vector<bool> DP(s.length()+1, false);
        DP[0]=true;
        for(int i=1; i<s.length()+1; i++){ // To find the DP[i+1]
            for(int j=0; j<wordDict.size(); j++){ // Checking if any word from wordDict matches
                if(DP[i]) break;
                int copy_i=i-1;
                for(int k=wordDict[j].length()-1; k>=0; k--){ // Traversing one word at a time
                    if(wordDict[j][k]==s[copy_i]){
                        if(k==0) {
                            DP[i]=DP[i-wordDict[j].length()];
                        }
                        copy_i--;
                        if(copy_i==-1) break;
                    } else break; // moving on to the next word
                }
            }
        }
        return DP[s.length()];
    }
};
