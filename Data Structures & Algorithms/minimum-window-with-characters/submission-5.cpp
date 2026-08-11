class Solution {
public:
/*Follow this exact blueprint every time for sliding window:

Always process s[j].

Always increment j.

While the window is valid, process s[i] and increment i.*/

    string minWindow(string s, string t) {
        int i = 0, j = 0;
        
        // Track the best coordinates instead of building strings repeatedly
        int min_start = 0;
        int min_len = INT_MAX; 
        
        unordered_set<int> master_tstr;
        unordered_set<int> tstr; 
        vector<int> tstring(128, 0); 
        
        for(int k = 0; k < t.length(); k++) {
            tstr.insert(t[k]);
            tstring[t[k]]++;
        }
        master_tstr = tstr;

        while(j < s.length()){
            // 1. EXPAND: Always process s[j] if it's in the target
            if(master_tstr.find(s[j]) != master_tstr.end()) {
                tstring[s[j]]--;
                if(tstring[s[j]] == 0) tstr.erase(s[j]);
            }
            
            // 2. EXPAND: Always increment j
            // Note: After this line, the current window is from index `i` to `j-1`.
            // Therefore, the length of the window is exactly `j - i`.
            j++;

            // 3. SHRINK: Squeeze out extra characters from the left
            while(tstr.empty()){
                
                // If this is the smallest valid window so far, record its coordinates
                if(j - i < min_len) {
                    min_len = j - i;
                    min_start = i;
                }
                
                // If the character we are removing is a target character...
                if(master_tstr.find(s[i]) != master_tstr.end()){
                    tstring[s[i]]++;
                    // Only break the window if we actually ran out of this character
                    if(tstring[s[i]] > 0) {
                        tstr.insert(s[i]);
                    }
                }
                
                // Shrink the window
                i++;
            }
        }

        // If min_len was never updated, no valid window was found
        if(min_len == INT_MAX) return "";
        
        // Build and return the substring exactly ONCE
        return s.substr(min_start, min_len);
    }
};
