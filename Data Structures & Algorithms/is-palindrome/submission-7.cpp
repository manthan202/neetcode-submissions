class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;
        while (j>i) {
            while (!isalnum(s[i])  && i<j) i++;
            while (!isalnum(s[j])  && i<j) j--;
            if (tolower(s[i++])!=tolower(s[j--])) return false;
        }
        return true;
    }
};
