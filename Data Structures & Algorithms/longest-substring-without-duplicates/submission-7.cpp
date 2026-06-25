class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0, length=0, maxLength=0;
        unordered_map<int,int> occured; // <ele,index>
        while(right<s.length()) {
            if (occured.find(s[right])!=occured.end() && occured[s[right]]>=left) {
                left=occured[s[right]]+1;
                length=right-left;
            }
            occured[s[right]]=right;
            right++;
            length++;
            maxLength=max(maxLength, length);
        }
        return maxLength;
    }
};
