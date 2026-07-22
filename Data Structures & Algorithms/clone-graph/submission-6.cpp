/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, Node*> mp; // maps old nodes to their clones
        return helper(node, mp);
    }

private:
    Node* helper(Node* node, unordered_map<Node*, Node*>& mp){
        
        if(mp.find(node)!=mp.end()) {
            return mp[node];
        }
        Node* newNode=new Node(node->val);
        mp[node]=newNode;
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(helper(neighbor, mp));
        }
        return newNode;
    }
};






