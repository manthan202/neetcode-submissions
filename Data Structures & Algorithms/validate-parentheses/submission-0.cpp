class Solution {
public:
    bool isValid(string s) {
        stack<char> stak;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') stak.push(s[i]);
            else {
                if (s[i]==')' && !stak.empty() && stak.top()=='(') stak.pop();
                else if (s[i]=='}' && !stak.empty() && stak.top()=='{') stak.pop();
                else if (s[i]==']' && !stak.empty() && stak.top()=='[') stak.pop();
                else return false;
            }
        }
        if (!stak.empty()) return false;
        return true;
    }
};
