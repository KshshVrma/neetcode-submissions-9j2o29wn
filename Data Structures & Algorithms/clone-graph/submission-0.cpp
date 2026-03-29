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
        if(node==NULL)  return node;
        unordered_map<Node*, Node*> mp;
        Node* clone_node=new Node(node->val);
        queue<Node*>q;
        mp[node]=clone_node;
        q.push(node);
        while(!q.empty()){
            Node *n=q.front();
            q.pop();
            for(auto it:n->neighbors){
                if(mp.find(it)==mp.end()){
                    Node* newnode=new Node(it->val);
                    mp[n]->neighbors.push_back(newnode);
                    mp[it]=newnode;
                    q.push(it);

                }else{
                    mp[n]->neighbors.push_back(mp[it]);
                }
            }

        }


        return clone_node;
    }
};
