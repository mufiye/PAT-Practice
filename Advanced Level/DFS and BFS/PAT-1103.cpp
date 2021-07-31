//dfs + 打表
#include<iostream>
#include<math.h>

using namespace std;

vector<int> table;//下标从1开始
table.push_back(-1);
int N,K,P;

//答案应当如何存储?
void dfs(int remain, int index){//remain为还差多少, index为现在是第几个
    for(int i=table.size()-1; i>=1; i--){
        if(table[i] < remain){
            dfs(remain - table[i], index+1);
        }
        else if(table[i] == remain){
            if(index == K){
                //找到了一个答案
            }
        }
        else{
            continue;
        }
    }
}

int main(){
    cin>>N>>K>>P;
    //打表
    int i = 1, number = 1;
    while(number<N){
        table.push_back(number);
        i++;
        number = pow(i,P);
    }
    //DFS
    dfs(N,1);
}
