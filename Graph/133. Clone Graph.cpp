Given a reference of a node in a connected undirected graph.

Return -> deep copy


class Solution {
public:
    void dfs(Node* node,Node* temp,unordered_map<Node*,Node*> &visited){
        for(Node *i:node->neighbors){
            if(visited.find(i)==visited.end()){
                Node* copy=new Node(i->val,{});
                visited[i]=copy;
                dfs(i,copy,visited);
            }
            temp->neighbors.push_back(visited[i]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> visited;
        Node* temp=new Node(node->val,{});
        visited[node]=temp;
        dfs(node,temp,visited);
        return temp;
    }
};
