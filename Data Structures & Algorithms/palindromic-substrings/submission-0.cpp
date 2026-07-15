class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> DP(s.length(), vector<bool>(s.length(), false));
        int len, res=0;

        //Base Case with length=1
        len=1;
        for(int i=0; i<s.length(); i++) DP[i][i]=true;
        res+=s.length();

        //Base Case with length=2
        len=2;
        for(int i=0; i<s.length()-1; i++) {
            DP[i][i+1]=(s[i]==s[i+1]);
            if(DP[i][i+1]) res++;
        }

        //General case for length=3 to s.length()
        for(int len=3; len<=s.length(); len++){
            for(int i=0; i<s.length()-len+1; i++){
                int j=i+len-1;
                DP[i][j]=DP[i+1][j-1] && (s[i]==s[j]);
                if(DP[i][j]) res++;
            }
        }
        return res;
    }
};
