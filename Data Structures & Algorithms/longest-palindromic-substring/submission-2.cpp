class Solution {
public:
    string longestPalindrome(string s) { 
    //DP[i][j] wil be bool and DP[i][j]=DP[i+1][j-1] && s[i]==s[j]
        if(s.empty() || s.length()==1) return s;

        vector<vector<bool>> DP(s.length(), vector<bool>(s.length()));

        //Base Case
        for(int i=0; i<s.length(); i++) DP[i][0]=true;
        for(int j=1; j<s.length(); j++) DP[s.length()-1][j]=true;

        pair<int, int> par;

        for(int i=0; i<s.length(); i++) {
            DP[i][i]=true;
        }
        for(int i=0; i<s.length()-1; i++) {
            DP[i][i+1]=s[i]==s[i+1];
            if(DP[i][i+1]) {
                par.first=i;
                par.second=i+1;
            }
        }

        for(int len=3; len<=s.length(); len++){
            for(int i=0; i<s.length()-len+1; i++){
                int j=i+len-1;
                DP[i][j]=DP[i+1][j-1] && s[i]==s[j];
                if(DP[i][j]){
                    par.first=i;
                    par.second=j;
                }
            }
        }
        string a;
        for(int i=par.first; i<=par.second; i++){
            a=a+s[i];
        }
        return a;
    }
};
