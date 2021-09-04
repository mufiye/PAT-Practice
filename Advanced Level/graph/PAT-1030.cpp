#include<iostream>
#include<vector>

using namespace std;

const int INF = 999999999;
int N, M, S, D, costVal = INF, disVal = 0;
int dis[505][505], cost[505][505], d[505];
vector<int> pre[505], tempPath, path;
bool vis[505];

void dfs(int v){
    tempPath.push_back(v);
    if(v == S){
        int tempCost = 0;
        for(int i = tempPath.size()-1; i>0; i--){
            tempCost += cost[tempPath[i]][tempPath[i-1]];
        }
        if(tempCost < costVal){
            costVal = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i=0; i<pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){
    cin>>N>>M>>S>>D;
    fill(dis[0], dis[0]+505*505, INF);
    fill(cost[0], cost[0]+505*505, INF);
    fill(d, d+505, INF);
    fill(vis, vis+505, false);
    int c1, c2, disNum, costNum;
    for(int i=0; i<M; i++){
        cin>>c1>>c2>>disNum>>costNum;
        dis[c1][c2] = dis[c2][c1] = disNum;
        cost[c1][c2] = cost[c2][c1] = costNum;
    }
    //Dijkstra
    d[S] = 0;
    for(int i=0; i<N; i++){
        int u = -1, minDis = INF;
        for(int j=0; j<N; j++){
            if(!vis[j] && d[j] < minDis){
                u = j;
                minDis = d[j];
            }
        }
        if(u == -1)  break;
        vis[u] = true;
        for(int v=0; v<N; v++){
            if(!vis[v] && dis[v][u] != INF){
                if(dis[v][u] + d[u] < d[v]){
                    d[v] = dis[v][u] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v][u] + d[u] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    //dfs
    dfs(D);
    disVal = d[D];
    cout<<path[path.size()-1];
    for(int i=path.size()-2; i>=0; i--){
        cout<<" "<<path[i];
    }
    cout<<" "<<disVal<<" "<<costVal;
    //输出结果
    return 0;
}
