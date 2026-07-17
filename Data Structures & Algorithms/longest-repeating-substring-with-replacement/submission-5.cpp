class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hashArray(26,0);
        int left=0, right=0, maxfreq=1;
        int maxlen=min((int)s.length(), k);
        while(right<s.length()){
            hashArray[s[right]-'A']++;
            maxfreq = max(maxfreq, hashArray[s[right]-'A']);
            int changes=right-left+1-maxfreq;
            if(changes>k) {
                left++;
                
                hashArray[s[left-1]-'A']--;
            }
            maxlen=max(maxlen, right-left+1);
            
            right++;
        }
        return maxlen;
    }
};
