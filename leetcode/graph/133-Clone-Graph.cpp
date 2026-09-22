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
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        //empty graph
        if(node==NULL)
        return NULL;
        //already cloned
        if(mp.find(node)!=mp.end())
        return mp[node];
        //create clone
        Node* clone= new Node(node->val);
        //store it
        mp[node]=clone;
        //clone all the adjoint neighbours
        for(Node* n:node->neighbors)
        clone->neighbors.push_back(cloneGraph(n));
        return clone;
    }
};