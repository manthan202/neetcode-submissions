class TrieNode{
public:
    bool endOfWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        endOfWord=false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr=root;
        if (word.empty()) return;
        for(char c : word){
            if(curr->children.find(c)!=curr->children.end()) {
                curr=curr->children[c];
                continue;
            }
            curr->children[c]=new TrieNode();
            curr=curr->children[c];
        }
        curr->endOfWord=true;

    }
    
    bool search(string word) {
        if(word.empty()) return true;
        TrieNode* curr=root;
        for(char c : word){
                if(curr->children.find(c)==curr->children.end()) return false;
                curr=curr->children[c];
        }
       return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        if(prefix.empty()) return true;
        TrieNode* curr=root;
        for(char c : prefix){
            if(curr->children.find(c)==curr->children.end()) return false;
            curr=curr->children[c];
        }
        return true;
    }
};
