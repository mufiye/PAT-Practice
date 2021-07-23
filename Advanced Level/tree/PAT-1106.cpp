//找到一棵树的所有叶子节点

#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<iomanip>

#define max_size 100000

using namespace std;

int recordNum[max_size];//记录零销商(叶子节点)的level
vector<int> recordLeaf;//记录叶子节点的下标

int main(){
    int N;
    double p,r;
    cin>>N>>p>>r;
    vector<vector<int>> tree(N);//记录树的结构
    //读取输入，记录树的结构以及叶子节点的相关信息
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(num == 0)  recordLeaf.push_back(i);
        else{
            for(int j=0;j<num;j++){
                int number;
                cin>>number;
                tree[i].push_back(number);
            }
        }
    }
    
    //遍历树,得到每一个叶子节点的level值
    int level = -1, thresholdValue = 1;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        level++;
        int temp = 0;
        for(int i=0;i<thresholdValue;i++){
            int root = que.front();
            temp += tree[root].size();
            if(tree[root].size() <= 0)  recordNum[root] = level;
            else{
                for(int j=0;j<tree[root].size();j++)  que.push(tree[root][j]);
            }
            que.pop();
        }
        thresholdValue = temp;
    }

    //找到最小层次的叶子节点
    int minLevel = recordNum[recordLeaf[0]];
    int minLeaf = recordLeaf[0];
    for(int i=1;i<recordLeaf.size();i++){
        if(recordNum[recordLeaf[i]] < minLevel){
            minLeaf = recordLeaf[i];
            minLevel = recordNum[recordLeaf[i]];
        }
    }
    int number=0;
    for(int i=0;i<recordLeaf.size();i++){
        if(recordNum[recordLeaf[i]] == minLevel)  number++;
    }
    double totalPrice = p * pow((1+r*0.01), minLevel);
    printf("%.4lf %d\n", totalPrice, number);
    return 0;
}
