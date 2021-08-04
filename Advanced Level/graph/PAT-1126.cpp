//判断欧拉图，注意要判断连通性
//Q: 度为0和连通性的关系是什么？
#include<iostream>
#include<vector>
#define max_size 501

using namespace std;

vector<int> graph[max_size];//下标为0的位置空着
int degree[max_size];
int N,M;
vector<bool> visit;
int cnt = 0;
void dfs(int index) {
    visit[index] = true;
    cnt++;
    for (int i = 0; i < graph[index].size(); i++)
        if (visit[graph[index][i]] == false)
            dfs(graph[index][i]);
}

int main(){
    cin>>N>>M;
    visit.resize(N + 1);
    for(int i=0;i<M;i++){
        int V1,V2;
        cin>>V1>>V2;
        graph[V1].push_back(V2);
        graph[V2].push_back(V1);
    }
    for(int i=1;i<=N;i++){
        degree[i] = graph[i].size();
        if(i!=1)  cout<<" "<<degree[i];
        else  cout<<degree[i];
    }
    cout<<endl;
    int oddNum = 0;
    for(int i=1;i<=N;i++){
        if(degree[i]%2 != 0)  oddNum++;
    }
    dfs(1);
    if(cnt!=N)  cout<<"Non-Eulerian";
    else if(oddNum == 0)  cout<<"Eulerian";
    else if(oddNum == 2)  cout<<"Semi-Eulerian";
    else  cout<<"Non-Eulerian";
    return 0;
}
