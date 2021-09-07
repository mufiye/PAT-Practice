#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>

using namespace std;

typedef struct Node{
    int id, layer;
    vector<Node*> children;
} Node;

Node* root;
stack<Node*> stk;
unordered_set<int> nodes;
int N, j, K;
string str;
vector<int> path;
bool isFind = false;

void dfs(Node* node, int target){
    if(isFind)  return;
    path.push_back(node->id);
    if(node->id == target){
        for(int i=0; i<path.size(); i++){
            printf("%04d", path[i]);
            if(i < path.size() - 1)  printf("->");
        }
        printf("\n");
        isFind = true;
        return;
    }
    for(auto item : node->children){
        dfs(item, target);
    }
    path.pop_back();
}

int main(){
    cin>>N;
    root = new Node;
    root->id = 0;
    root->layer = 0;
    stk.push(root);
    nodes.insert(0);
    getline(cin, str);
    for(int i=1; i<N; i++){
        getline(cin, str);
        for(j=0; j<str.length(); j++){
            if(str[j] != ' ')  break;
        }
        int id = stoi(str.substr(j,4));
        if(j <= stk.top()->layer){
            while(j <= stk.top()->layer)  stk.pop();
        }else if(j == stk.top()->layer + 2){
            stk.push(stk.top()->children.back());
        }
        nodes.insert(id);
        Node *node = new Node;
        node->layer = j;
        node->id = id;
        stk.top()->children.push_back(node);
    }
    cin>>K;
    for(int i=0; i<K; i++){
        int target;
        cin>>target;
        if(nodes.count(target) == 0)  printf("Error: %04d is not found.\n",target);
        else{
            isFind = false;
            path.clear();
            dfs(root, target);
        }
    }
    return 0;
}
