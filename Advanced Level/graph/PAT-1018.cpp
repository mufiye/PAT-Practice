//看来得dfs, 两个附加条件是如果路径相同则看PMBC需要送出的自行车数量最少,如果前者也相同则需最后需要送回的自行车最少
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

const int INF = 999999999;
int cMax, N, sp, M, halfMax;
int graph[505][505], arr1[505], d[505];
vector<int> pre[505], tempPath, path;
bool vis[505] = {false};
int minNeed = INF, minBack = INF;

void dfs(int v){
    tempPath.push_back(v);
    if(v == 0){
        int need = 0, back = 0;
        for(int i=tempPath.size()-1; i>=0; i--){
            if(arr1[tempPath[i]] > 0){
                back += arr1[tempPath[i]];
            }
            else{
                if(back > 0 - arr1[tempPath[i]]){
                    back += arr1[tempPath[i]];
                }
                else{
                    need = need + 0-arr1[tempPath[i]]-back;
                    back = 0;
                }
            }
        }
        if(minNeed > need){
            minNeed = need;
            minBack = back;
            path = tempPath;
        }
        else if(minNeed == need && minBack>back){
            minBack = back;
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
    fill(graph[0], graph[0]+505*505, INF);
    fill(d, d+505, INF);
    cin>>cMax>>N>>sp>>M;
    halfMax = cMax/2;
    for(int i=1; i<=N; i++){
        cin>>arr1[i];
        arr1[i] -= halfMax;
    }
    for(int i=0; i<M; i++){
        int a,b,t;
        cin>>a>>b>>t;
        graph[a][b] = graph[b][a] = t;
    }
    d[0] = 0;
    for(int i=0; i<=N; i++){
        int u = -1, minDis = INF;
        for(int j=0; j<=N; j++){
            if(!vis[j] && minDis>d[j]){
                u = j;
                minDis = d[j];
            }
        }
        if(u == -1)  break;
        vis[u] = true;
        for(int v=0; v<=N; v++){
            if(!vis[v] && graph[u][v] != INF){
                if(d[v] > d[u] + graph[u][v]){
                    d[v] = graph[u][v] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == d[u] + graph[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    cout<<minNeed<<" 0";
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    cout<<" "<<minBack;
    return 0;
}
