//邻接矩阵版
int n, G[MAXV][MAXV];
int d[MAXV];
int pre[MAXV];//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
bool vis[MAXV] = {false};

void Dijkstra(int s){
    fill(d, d+MAXV, INF);
    for(int i=0;i<n;i++) pre[i] = i;
    d[s] = 0;
    for(int i=0; i<n; i++){ //循环n次
        int u = -1, MIN = INF; //u是d[u]最小, MIN存放最小的d[u]
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1)  return;
        vis[u] = true;
        for(int v=0; v<n; v++){
            //如果v未访问 && u能到达v && 以u为中介点可以是d[v]更优
            if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v]; //优化d[v]
                pre[v] = u;//记录v的前驱顶点
            }
        }
    }
}


//邻接表版
struct Node{
    int v, dis;
}
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
int pre[MAXV];//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
bool vis[MAXV] = {false};

void Dijkstra(int s){//s为起点
    fill(d, d+MAXV, INF);
    for(int i=0;i<n;i++) pre[i] = i;
    d[s] = 0;
    for(int i=0; i<n; i++){ //循环n次
        int u = -1, MIN = INF; //u是d[u]最小, MIN存放最小的d[u]
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1)  return;
        vis[u] = true;
        for(int j=0; j<Adj[u].size(); j++){
            int v = Adj[u][j].v;
            if(vis[v] == false && d[u] + Adj[u][j].dis<d[v]){
                d[v] = d[u] + Adj[u][j].dis;
                pre[v] = u;//记录v的前驱顶点
            }
        }
    }
}

//pre数组的遍历
void DFS(int s, int v){
    if(v == s){
        printf("%d\n",s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d\n",v);
}
