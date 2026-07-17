class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> mp;
        int left=0, right=0, max_len=1;
        while(right<s.length()){
            if(mp.find(s[right])!=mp.end() && mp[s[right]]>=left) left=mp[s[right]]+1;
            max_len=max(max_len, right-left+1);
            mp[s[right]]=right;
            right++;
        }
        return max_len;
    }
};
