class Solution {
public:
/*Follow this exact blueprint every time for sliding window:

Always process s[j].

Always increment j.

While the window is valid, process s[i] and increment i.*/

    string minWindow(string s, string t) {
        vector<int> tstring(128, 0);
        
        // Count frequencies of chars in t
        for(char c : t) {
            tstring[c]++;
        }
        
        int i = 0, j = 0;
        int min_start = 0, min_len = INT_MAX;
        
        // Counter tracks how many characters we still need to match
        int counter = t.length(); 
        
        while(j < s.length()) {
            // EXPAND: If s[j] is a character we still need, decrement counter
            if(tstring[s[j]] > 0) {
                counter--;
            }
            // Always decrement the frequency (surplus chars go negative)
            tstring[s[j]]--;
            j++;
            
            // SHRINK: When counter is 0, our window has all required characters
            while(counter == 0) {
                // Update minimum window
                if(j - i < min_len) {
                    min_len = j - i;
                    min_start = i;
                }
                
                // Remove s[i] from the window
                tstring[s[i]]++;
                
                // If it goes above 0, it means we actually needed this character
                if(tstring[s[i]] > 0) {
                    counter++; // This breaks the while loop
                }
                i++;
            }
        }
        
        if(min_len == INT_MAX) return "";
        return s.substr(min_start, min_len);
    }
};
