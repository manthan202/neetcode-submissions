class DictNode {

public:
    unordered_map<char, DictNode*> children;
    bool endOfWord;
    DictNode() {
        endOfWord=false;
    }
};

class WordDictionary {
    DictNode* root;
public:
    WordDictionary() {
        root=new DictNode();
    }
    
    void addWord(string word) {
        DictNode* curr=root;
        for(char c : word){
            if(curr->children.find(c)==curr->children.end()){
                curr->children[c]=new DictNode();
            }
            curr=curr->children[c];
        }
        curr->endOfWord=true;
    }
    
    bool search(string word){
        return search2(word, root);
    }

    bool search2(string word, DictNode* root){
        for(int i=0; i<word.length(); i++){
            if(word[i]!='.'){
                if(root->children.find(word[i])==root->children.end()) return false;
                root=root->children[word[i]];
            } else{
                bool result=false;
                for(auto p : root->children){
                    result=result||search2(word.substr(i+1), p.second);
                    if (result==true) return true;
                }
                return false;
            }
            
        }
        return root->endOfWord;
    }
};
