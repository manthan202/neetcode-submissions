class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        vector<int> nums(26,0);
        for (int i=0; i<s.length(); i++) {
            nums[s[i]-'a']++;
            nums[t[i]-'a']--;
        }
        for (int i : nums) {
            if (i!=0) return false;
        }
        return true;
    }
};
