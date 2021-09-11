#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Node{
    int key;
    int priority;
    int left = -1, right = -1; //store the index
};
const int INF = 999999999;
int N;
vector<Node> vec;

bool cmp(Node n1, Node n2){
    return n1.key < n2.key;
}

void getTree(int inL, int inR, int root){ //all is index
    int leftRoot = -1, lminPri = INF;
    for(int i=inL; i <= root-1; i++){
        if(vec[i].priority < lminPri){
            leftRoot = i;
            lminPri = vec[i].priority;
        }
    }
    int rightRoot = -1, rminPri = INF;
    for(int i=root+1; i <= inR; i++){
        if(vec[i].priority < rminPri){
            rightRoot = i;
            rminPri = vec[i].priority;
        }
    }

    if(leftRoot != -1){
        vec[root].left = leftRoot;
        getTree(inL, root-1, leftRoot);
    }
    if(rightRoot != -1){
        vec[root].right = rightRoot;
        getTree(root+1, inR, rightRoot);
    }
    return;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        Node node;
        cin>>node.key>>node.priority;
        vec.push_back(node);
    }
    sort(vec.begin(), vec.end(), cmp);
    int minPri = INF, rootIndex = -1; 
    for(int i=0; i<vec.size(); i++){
        if(vec[i].priority < minPri){
            minPri = vec[i].priority;
            rootIndex = i;
        }
    }
    getTree(0, N-1, rootIndex);
    
    //debug
    //for(int i=0; i<vec.size(); i++){
    //    cout<<"index "<<i<<" left: "<<vec[i].left<<" and right: "<<vec[i].right<<endl;
    //}
    
    //level-order traversal
    queue<int> q;
    q.push(rootIndex);
    while(!q.empty()){
        int f, s = q.size();
        for(int i=0; i<s; i++){
            f = q.front();
            q.pop();
            if(f != rootIndex)  cout<<" "<<vec[f].key;
            else  cout<<vec[f].key;
            if(vec[f].left != -1)  q.push(vec[f].left);
            if(vec[f].right != -1)  q.push(vec[f].right);
        }
    }
    cout<<endl;
    q.push(rootIndex);
    while(!q.empty()){
        int f, s = q.size();
        for(int i=0; i<s; i++){
            f = q.front();
            q.pop();
            if(f != rootIndex)  cout<<" "<<vec[f].priority;
            else  cout<<vec[f].priority;
            if(vec[f].left != -1)  q.push(vec[f].left);
            if(vec[f].right != -1)  q.push(vec[f].right);
        }
    }
    return 0;
}
