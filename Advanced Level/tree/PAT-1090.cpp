#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
#define max_size 100000

using namespace std;

struct Node{
    vector<Node*> children;
}nodes[max_size];

int main(){
    int N;
    double p,r;
    cin>>N>>p>>r;
    
    //读取树结构
    int root;
    for(int i=0;i<N;i++){
        int number;
        cin>>number;
        if(number != -1){
            nodes[number].children.push_back(&nodes[i]);
        }
        else  root = i;
    }
    
    queue<Node*> q;
    q.push(&nodes[root]);
    int level=-1, number;
    
    while (!q.empty()) {
        level++;
        number = q.size();
        for(int i = 0, l = (int)q.size(); i < l; i++){
            Node* cur = q.front();
            for(auto lt : cur->children){
                    q.push(lt);
            }
            q.pop();
        }
    }
    double maxPrice = p * pow((1+r*0.01),level);
    printf("%.2lf %d\n",maxPrice,number);
    return 0;
}
