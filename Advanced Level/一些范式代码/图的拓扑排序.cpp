vector<int> G[MAXV]; 
int n, m, inDegree[MAXV];

//拓扑排序
bool topologicalSort(){
    int num = 0; // 记录加入拓扑序列的顶点数
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0){
            q.push(i); //将所有入度为0的顶点入队
        }
    }
    while(!q.empty()){
        int u = q.front(); //取队首顶点u
        q.pop();
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0)  q.push(v);
        }
        G[u].clear();
        num++;
    }
  
    if(num == n)  return true; //加入拓扑排序的顶点数为n，说明拓扑排序成功
    else  return false;
}

//如果要求有多个入度为0的顶点，选择编号最小的顶点，那么把queue改成priority_queue,并保持队首元素是优先队列中最小的元素即可，C++的STL库中的set的实现就是堆）
