#include<iostream>
#include<vector>

using namespace std;

const int INF = 999999999;
int N, M, v1, v2, s, d, queryNum;
int inDegree[1010], graphS[1010][1010], graphD[1010][1010];
vector<int> query, graph[1010];
bool isTopological = true;

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
        inDegree[v2] += 1;
    }
    cin>>queryNum;
    for(int i=0; i<queryNum; i++){
        int temp;
        cin>>temp;
        query.push_back(temp);
    }
    for(int i=0; i<queryNum; i++){
        if(inDegree[query[i]] != 0){
            isTopological = false;
            break;
        }
        for(int j=0; j<graph[query[i]].size(); j++){
            inDegree[graph[query[i]][j]]--;
        }
    }
    if(isTopological)  cout<<"Okay."<<endl;
    else  cout<<"Impossible."<<endl;
    return 0;
}
