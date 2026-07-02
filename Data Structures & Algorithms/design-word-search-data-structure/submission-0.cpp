class DictNode {
    public:
    unordered_map<char, DictNode*> children;
    bool endOfWord=false;
};

class WordDictionary {
    DictNode* root;
public:
    WordDictionary() {
        root=new DictNode();
    }
    
    void addWord(string word) {
        DictNode* cur=root;
        for (char c : word) {
            if(cur->children.find(c)==cur->children.end()) {
                cur->children[c]=new DictNode();
            }
            cur=cur->children[c];
        }
        cur->endOfWord=true;
    }
    
    bool search(string word) {
        return search(word, root);
    }

    bool search(string word, DictNode* cur) {
        for(int i=0; i<word.length(); i++) {
            if(word[i]!='.' && cur->children.find(word[i])==cur->children.end()) return false;
            else if (word[i]!='.' && cur->children.find(word[i])!=cur->children.end()) cur=cur->children[word[i]];
            else {
                bool result=false;
                string temp1=word;
                word.erase(0,i+1);
                string temp2=word;
                word=temp1;
                for(pair<char, DictNode*> P: cur->children) {
                    result=result||search(temp2, cur->children[P.first]);
                }
                return result;
            }
        }
        return cur->endOfWord;
    }
};
