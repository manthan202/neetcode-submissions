class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLength = 0;
        int i = 0; // Left pointer
        
        // Let the for-loop push the right pointer (j) forward one step at a time
        for (int j = 0; j < s.length(); j++) {
            
            // 1. If we see a duplicate, AND it's inside our current window...
            if (mp.find(s[j]) != mp.end() && mp[s[j]] >= i) {
                // Move the left pointer just past the old duplicate
                i = mp[s[j]] + 1; 
            }
            
            // 2. Update the map with the character's most recent index
            mp[s[j]] = j;
            
            // 3. The length is always (right - left + 1)
            maxLength = max(maxLength, j - i + 1);
        }
        
        return maxLength;
    }
};