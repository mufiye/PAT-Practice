//if there are two solutions, output the starting postion with the smallest index
//using the dfs
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//const int INF = 999999999;
int N,M;
int maxStart = -1, maxSite = -1, currentStart, tempCnt = 0;
vector<int> graph[110]; //1~N
bool vis[110];

void dfs(int v){
    vis[v] = true;
    tempCnt++;
    bool isDfs = false;
    for(int i=0; i<graph[v].size(); i++){
        if(!vis[graph[v][i]]){
            dfs(graph[v][i]);
            isDfs = true;
            break;
        }
    }
    if(!isDfs){
        if(tempCnt > maxSite){
            maxSite = tempCnt;
            maxStart = currentStart;
        }
        else if(tempCnt == maxSite && currentStart < maxStart){
            maxStart = currentStart;
        }
    }
    return;
}

int main(){
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=1; i<N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    for(int i=1; i<=N; i++){
        currentStart = i, tempCnt = 0;
        fill(vis, vis+110, false);
        dfs(currentStart);
    }
    cout<<maxStart<<" "<<maxSite<<endl;
    return 0;
}
