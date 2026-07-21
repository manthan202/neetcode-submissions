class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ele_size=board[0].size();
        vector<pair<int, int>> firstLetter;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<ele_size; j++){
                if(board[i][j]==word[0]) firstLetter.push_back({i,j});
            }
        }
        for(int i=0; i<firstLetter.size(); i++){
            unordered_set<int> current;
            if(exist2(board, word, firstLetter[i].first, firstLetter[i].second, 0, current)){
                return true;
            }
        }
        return false;
    }

private:
    bool exist2(vector<vector<char>>& board, string& word, int i, int j, int start, unordered_set<int>& current){     
        if(board[i][j]==word[start]){

            if(start==word.length()-1) return true;

            current.insert(i*board[0].size()+j);

            if(i<board.size()-1 && current.find((i+1)*board[0].size()+j) == current.end()) {
                if(exist2(board, word, i+1, j, start+1, current)) return true;
            }

            if(i>0 && current.find((i-1)*board[0].size()+j) == current.end()){
                if(exist2(board, word, i-1, j, start+1, current)) return true;
            }

            if(j<board[0].size()-1 && current.find((i)*board[0].size()+j+1) == current.end()){
                if(exist2(board, word, i, j+1, start+1, current)) return true;
            }

            if(j>0 && current.find((i)*board[0].size()+j-1) == current.end()){
                if(exist2(board, word, i, j-1, start+1, current)) return true;
            } 

            current.erase(i*board[0].size()+j);
        }
        
        return false;
    }
};
