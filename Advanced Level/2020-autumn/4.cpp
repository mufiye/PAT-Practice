#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 999999999;
int N, M, v1, v2, s, d, queryNum, sval = INF, dval = -1;
int inDegree[1010], tempDegree[1010], graphS[1010][1010], graphD[1010][1010];
vector<int> query, graph[1010], reveGra[1010], tempPath, path;
bool isTopological = true;

void dfs(int v){
    tempPath.push_back(v);
    if(inDegree[v] == 0){
        int tempS = 0, tempD = 0;
        for(int i=tempPath.size()-1; i>=1; i--){
            tempS += graphS[tempPath[i]][tempPath[i-1]];
            tempD += graphD[tempPath[i]][tempPath[i-1]];
        }
        if(tempS < sval){
            sval = tempS;
            dval = tempD;
            path = tempPath;
        }
        else if(tempS == sval && tempD > dval){
            sval = tempS;
            dval = tempD;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i=0; i<reveGra[v].size(); i++){
        dfs(reveGra[v][i]);
    }
    tempPath.pop_back();
}

bool DAG(){
    int cnt=0;
    queue<int> q;
    for(int i=0; i<N; i++){
        if(tempDegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int index = q.front();
        q.pop();
        for(int i=0; i<graph[index].size(); i++){
            tempDegree[graph[index][i]]--;
            if(tempDegree[graph[index][i]] == 0){
                q.push(graph[index][i]);
            }
        }
        cnt++;
    }
    if(cnt == N)  return true;
    else  return false;
}

int main(){
    fill(inDegree, inDegree+1010, 0);
    fill(graphS[0], graphS[0]+1010*1010, INF);
    fill(graphD[0], graphD[0]+1010*1010, INF);
    cin>>N>>M;
    for(int i=0; i<M; i++){
        cin>>v1>>v2>>s>>d;
        graphS[v1][v2] = s;
        graphD[v1][v2] = d;
        graph[v1].push_back(v2);
        reveGra[v2].push_back(v1);//反着记录
        inDegree[v2] += 1;
    }
    cin>>queryNum;
    for(int i=0; i<queryNum; i++){
        int temp;
        cin>>temp;
        query.push_back(temp);
    }
    for(int i=0; i<N; i++)  tempDegree[i] = inDegree[i];
    if(DAG()){//想办法求路径
        cout<<"Okay."<<endl;
        for(int i=0; i<queryNum; i++){
            if(inDegree[query[i]] == 0)  cout<<"You may take test "<<query[i]<<" directly."<<endl;
            else{
                tempPath.clear();
                path.clear();
                sval = INF, dval = -1;
                dfs(query[i]);
                //cout<<"path的size: "<<path.size()<<"  ";
                for(int i=path.size()-1; i>=0; i--){
                    if(i != 0)  cout<<path[i]<<"->";
                    else  cout<<path[i];
                }
                cout<<endl;
            }
        }
    }
    else{
        cout<<"Impossible."<<endl;
        for(int i=0; i<queryNum; i++){
            if(inDegree[query[i]] == 0)  cout<<"You may take test "<<query[i]<<" directly."<<endl;
            else  cout<<"Error."<<endl;
        }
    }
    return 0;
}
