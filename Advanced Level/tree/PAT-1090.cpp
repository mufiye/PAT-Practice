#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<iomanip>
#define max_size 100000

using namespace std;

struct Node{
    vector<Node*> children;
}nodes[max_size];

int main(){
    int N;
    float p,r;
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
    int level=-1;
    vector<int> nums;
    while (!q.empty()) {
        level++;
        int number = 0;
        for(int i = 0, l = (int)q.size(); i < l; i++){
            Node* cur = q.front();
            for(auto lt : cur->children){
                    q.push(lt);
                    number++;
            }
            q.pop();
        }
        nums.push_back(number);
    }
    float maxPrice = p * pow((1+r*0.01),level);
    int number;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]!=0){
            number = nums[i];
            break;
        }
    }
    printf("%.2lf",maxPrice);
    printf(" %d\n",number);
    return 0;
}
