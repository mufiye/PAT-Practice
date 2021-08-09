//prim算法
//邻接矩阵版
int n, G[MAXV][MAXV];
int d[MAXV]; //顶点和集合S的最短距离
bool vis[MAXV] = {false};

int prim(){//默认零号为初始点，函数返回最小生成树的边权之和
    fill(d, d+MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j<n; j++){
            if(vis[j] == false && d[j]<MIN){
                u = j;
                MIN = d[j];
            }
        }
    
        //找不到小于INF的d[u], 则剩下的顶点和集合S不连通
        if(u == -1)  return -1;
        vis[u] = true;//标记u为已访问
        ans += d[u];//将与集合S距离最小的边加入最小生成树
        for(int v=0; v<n; v++){
            //v未访问 && u能到达v && 以u为中介点可以使v离集合S更近
            if(vis[v] == false && G[u][v] != INF && G[u][v] < d[v]){
                d[v] = G[u][v]; //将G[u][v]赋值给d[v]
            }
         }
     }
     return ans; //返回最小生成树边权之和
}

//邻接表版
struct Node{
    int v, dis; 
};
vector<Node> G[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};
int prim(){
    fill(d, d+MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for(int i = 0; i<n; i++){
        int u=-1, MIN = INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false  &&  d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1)  return -1;
        vis[u] = true;
        ans += d[u];
        for(int j=0; j<G[u].size(); v++){
            int v = G[u][j].v;
            if(vis[v] == false && G[u][j].dis < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}
