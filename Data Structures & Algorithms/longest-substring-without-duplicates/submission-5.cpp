class Solution {
public:
    int lengthOfLongestSubstring(string s) { //Brute force
        if (s.empty()) return 0;
        int maxLength=1, length;
        for (int i=0; i<s.length(); i++) {
            length=0;
            unordered_map<char,int> mp;
            for (int j=i; j<s.length(); j++) {
                if (mp.find(s[j])!=mp.end()) break;
                else {
                    length++;
                    maxLength=max(maxLength, length);
                    mp[s[j]]++;
                }
            }
        }
        return maxLength;
    }
};
