#include<iostream>
#include<algorithm>

using namespace std;

//呜呜，又不是自己做的，我好菜，我哭了
//本来是一张完整的图，但是由于某些城市被攻占，变成了好几颗树（也就是该图变成了森林），该问题其实就是让你求该森林中树的数量

bool vis[1000];
int G[1000][1000]={0};
int N,M,K;

//如何进行深度优先搜索
void dfs(int node){
    vis[node] = true;
    for(int i=1;i<=N;i++){
        if(vis[i] == false && G[node][i] == 1)  dfs(i);
    }
}

int main(){
    cin>>N>>M>>K;
    for(int i=0;i<M;i++){
        int row,col;
        cin>>row>>col;
        G[row][col] = 1;
        G[col][row] = 1;
    }
    for(int i=0;i<K;i++){
        int cityNum;
        cin>>cityNum;
        fill(vis,vis+1000,false);
        vis[cityNum] = true;
        int num = 0;
        for(int j=1;j<=N;j++){
            if(vis[j] == false){
                dfs(j);
                num++;
            }
        }
        if(i==0) cout<<num-1;
        else cout<<endl<<num-1;
    }
    cout<<endl;
    return 0;
}
