class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0, maxFreq=0, maxLength=0;
        vector<int> hashArray(26,0);
        while (right<s.length()) {
            hashArray[s[right]-'A']++;
            maxFreq=max(maxFreq, hashArray[s[right]-'A']);
            if (right-left+1-maxFreq>k) {
                left++;
                hashArray[s[left-1]-'A']--;
            } else maxLength++;
            right++;
        }
        return maxLength;
    }
};
