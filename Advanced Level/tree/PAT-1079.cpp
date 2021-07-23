//找到一棵树的所有叶子节点

#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<iomanip>

#define max_size 100000

using namespace std;

int recordNum1[max_size];//记录零销商(叶子节点)卖出去的货品数量
int recordNum2[max_size];//记录零销商(叶子节点)的level
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
        if(num == 0){
            cin>>num;
            recordNum1[i] = num;
            recordLeaf.push_back(i);
        }
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
            if(tree[root].size() <= 0)  recordNum2[root] = level;
            else{
                for(int j=0;j<tree[root].size();j++)  que.push(tree[root][j]);
            }
            que.pop();
        }
        thresholdValue = temp;
    }
    
    //最后计算钱
    double ans = 0.0;
    for(int i=0;i<recordLeaf.size();i++){
        int leafId = recordLeaf[i];
        ans += recordNum1[leafId] * p * pow((1+r*0.01),recordNum2[leafId]);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(1)<<ans<<endl;
    return 0;
}
