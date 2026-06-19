class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for (int i=0; i<strs.size(); i++) {
            encoded_string+=to_string(strs[i].size()) + '*' + strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> decoded_strs;
        while(i<s.length()) {
            int num=0;
            while(s[i]!='*') {
                num*=10;
                num+=s[i]-'0';
                i++;
            }
            i++;
            string str;
            for (int j=i; j<num+i; j++) {
                str+=s[j];
            }
            i+=num;
            decoded_strs.push_back(str);

        }
        return decoded_strs;
    }
};
