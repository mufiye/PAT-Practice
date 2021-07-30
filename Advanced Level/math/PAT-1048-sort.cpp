//枚举
#include<iostream>
#include<vector>
#include<algorithm>
#define max_size 100000

using namespace std;

int coins[max_size];
vector<int> res;

int main(){
    int N,M;
    bool isFind = false;
    cin>>N>>M;
    for(int i=0;i<N;i++)  cin>>coins[i];
    sort(coins,coins+N);
    for(int i=0;i<N && !isFind;i++){
        if(coins[i]>=M)  break;
        for(int j=i+1;j<N;j++){
            if(coins[i]+coins[j] == M){
                res.push_back(coins[i]);
                res.push_back(coins[j]);
                isFind = true;
                break;
             }
        }
    }
    if(isFind)  cout<<res[0]<<" "<<res[1];
    else  cout<<"No Solution";
}
