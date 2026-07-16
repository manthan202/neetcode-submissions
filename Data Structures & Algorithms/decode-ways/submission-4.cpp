class Solution {
public:
    int numDecodings(string s) {
        vector<int> DP(s.length());
        if(s.empty() || s[0]=='0') return 0;
        if(s.length()==1){
            if(s[0]-'0'==0) return 0;
            return 1;
        }

        DP[0]=1;
        if(s[1]=='0'){
            DP[1]=0;
            if((s[0]-'0')*10 <= 26) DP[1]+=1;
            else return 0;
        } else{
            DP[1]=1;
            if((s[0]-'0')*10 + (s[1]-'0') <= 26) DP[1]+=1;
        }

        for(int i=2; i<s.length(); i++){
            if(s[i]-'0'==0){
                DP[i]=0;
                if(s[i-1]!='0'){
                    if((s[i-1]-'0')*10 + s[i]-'0' <= 26) DP[i]+=DP[i-2];
                } else return 0;
            } else {
                DP[i]=DP[i-1];
                if (s[i-1]!='0'){
                    if((s[i-1]-'0')*10 + s[i]-'0' <= 26) DP[i]+=DP[i-2];
                }
            }

        }

        return DP[s.length()-1];
    }
};
