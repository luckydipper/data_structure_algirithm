// 1. STL custom sort
// 2. stack frame을 이용한 BST 구현에는 double pointer 혹은 pointer Reference가 쓰인다. 
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x,y, idx;
    Node(int x, int y, int idx):x(x),y(y),idx(idx){;};
    Node(const Node& n) = default;
    Node* l=nullptr;
    Node* r=nullptr;
    static bool cmp(const Node& f, const Node& b) {
        if(f.y < b.y)
            return true;
        else if (f.y == b.y)
            return f.x < b.x;
        else 
            return false;   
    }
};

struct Tree{
    Node* _base_node = nullptr;
    
    void push(Node* n){
        push_impl(n, _base_node);
    }
    
    void push_impl(Node* n, Node* & to){ 
        if(to == nullptr){
            to = n;
            return;
        }
        if(n->x < to->x)
            push_impl(n, to->l);
        else
            push_impl(n, to->r);
        
    }
    vector<int> f, b;
    void forward(){
        forward(_base_node);
    }
    void forward(Node * n ){
        if(n == nullptr)
            return;
        f.push_back(n->idx);
        forward(n->l);
        forward(n->r);
    }
    void backward(){
        backward(_base_node);
    }
    void backward(Node *n){
        if(n == nullptr)
            return;
        backward(n->l);
        backward(n->r);
        b.push_back(n->idx);
    }
};


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++)
        nodes.push_back(Node(nodeinfo[i][0],nodeinfo[i][1],i+1));

    sort(nodes.begin(), nodes.end(), Node::cmp);
    reverse(nodes.begin(), nodes.end());
    Tree t{};
    for(auto& node: nodes)
        t.push(&node);
    
    t.forward();
    t.backward();
    
    return vector< vector<int> > {t.f, t.b};
}
