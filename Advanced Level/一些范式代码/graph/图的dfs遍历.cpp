const int MAXV = 1000;
const int INF = 1000000000;

//邻接矩阵版
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void dfs(int u, int depth){//u为当前访问的顶点标号, depth为深度
    vis[u] = true;
    for(int v=0; v<n; v++){
        if(vis[n] == false && G[u][v] != INF){
            dfs(v, depth+1);
        }
    }
}

void dfsTrave(){//遍历图G
    for(int u=0; u<n; u++){//对每个顶点u
        if(vis[u] == false){
            dfs(u, 1);
        }
    }
}

//邻接表版
vector<int> Adj[MAXV];
int n;
bool vis[MAXV] = {false};

void dfs(int u, int depth){
    vis[u] = true;
    for(int i=0; i<Adj[u].size(); i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            dfs(v, depth+1);
        }
    }
}

void dfsTrave(){//遍历图G
    for(int u=0; u<n; u++){
        if(vis[u] == false){
            dfs(u ,1);
        }
    }
}
