/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include"../head.h"
class Solution {	//dfs的经典之作
	unordered_map<Node*, Node*> nodes;
	Node* dfs(Node* node) {
		if (nodes.count(node)) return nodes[node];
		Node* cur = nodes[node] = new Node(node->val);
		for (const auto& next : node->neighbors) {
			cur->neighbors.push_back(dfs(next));
		}
		return cur;
	}
public:
	Node* cloneGraph(Node* node) {
		if (!node)
			return nullptr;
		return dfs(node);
	}
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<Node*, Node*> old2new;
        unordered_set<Node*> isvisited;
        //dfs
        queue<Node*> nodes;
        nodes.push(node);
        while(!nodes.empty()){
            Node* cur = nodes.front();
            nodes.pop();
            if(isvisited.find(cur) != isvisited.end()) //已访问
                continue;
            isvisited.insert(cur);
            if(old2new.find(cur) == old2new.end()) 
                old2new[cur] = new Node(cur->val);
            for(auto next : cur->neighbors){
                if(old2new.find(next) == old2new.end())
                    old2new[next] = new Node(next->val);
                old2new[cur]->neighbors.push_back(old2new[next]);
                nodes.push(next);
            }
        }
        return old2new[node];
    }
};