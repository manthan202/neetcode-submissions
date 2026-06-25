class Solution {
public:
    int characterReplacement(string s, int k) { //brute force
        int maxLength=0;
        for (int i=0; i<s.length(); i++) {
            vector<int> hashArray(26,0);
            int maxFreq=0;
            for (int j=i; j<s.length(); j++) {
                hashArray[s[j]-'A']++;
                maxFreq=max(maxFreq, hashArray[s[j]-'A']);
                if (j-i+1-maxFreq<=k) maxLength=max(maxLength, j-i+1);
                else break;
            }
        }
        return maxLength;
    }
};
