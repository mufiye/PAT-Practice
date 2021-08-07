//kruskal算法
struct edge{
    int u,v; //边的两个端点编号
    int cost;//边权
}E[MAXE];//最多有MAXE条边

bool cmp(edge a, edge b){
    return  a.cost < b.cost;
}

//使用并查集
int father[N];
int findFather(int x){
   ...
}

int kruskal(int n, int m){
    //ans为所求边权之和, Num_Edge为当前生成树的边数
    int ans = 0, Num_Edge = 0;
    for(int i=0; i<=n; i++)  father[i] = i;//并查集初始化
    sort(E, E+m, cmp); //所有边按边权从小到大排序
    for(int i=0; i<m; i++){
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if(faU != faV){ //如果不在一个集合中
            father[faU] = faV;
            ans += E[i].cost;
            Num_Edge++;
            if(Num_Edge == n-1)  break;
        }
        if(Num_Edge != n-1)  return -1;//无连通时返回-1
        else  return ans; //返回最小生成树的边权之和
    }
}
