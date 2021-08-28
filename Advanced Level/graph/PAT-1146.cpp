#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N,M,K;
    vector<int> res;
    cin>>N>>M;
    vector<int> graph[N+1]; //下标从1开始
    int inDegree[N+1] = {0};//存储入度
    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        inDegree[b] += 1;
    }
    cin>>K;
    for(int i=0; i<K; i++){
        bool isOrder = true;
        int order[N];
        int temp[N+1];//复制一个indegree数组
        for(int j=1; j<=N; j++){
            temp[j] = inDegree[j];
            //cout<<temp[j]<<endl;//入度数组没问题
        }
        for(int j=0;j<N;j++)  cin>>order[j];
        //如何判断是否为拓扑排序
        for(int j=0;j<N;j++){
            int vertex = order[j];
            //cout<<vertex<<" : "<<temp[vertex]<<endl;
            if(temp[vertex] != 0){
                //cout<<"in and the vertex is "<<vertex<<" and inDegree is: "<<temp[vertex]<<endl;
                isOrder = false;
                break;
            }
            else{
                for(int k=0;k<graph[vertex].size();k++){
                    temp[graph[vertex][k]] -= 1;
                }
            }
        }
        if(!isOrder)  res.push_back(i);
    }
    
    //输出结果
    for(int i=0; i<res.size(); i++){
        if(i != 0)  cout<<" "<<res[i];
        else  cout<<res[i];
    }
    return 0;
}
