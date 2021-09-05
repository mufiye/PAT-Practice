#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct edge{
    int v1, v2;
} edgeArr[10010];

//const int INF = 999999999;
int N,M,K; //N为顶点数, M为边数,K为query
int colorArr[10010];

int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>edgeArr[i].v1>>edgeArr[i].v2;
    }
    cin>>K;
    for(int i=0;i<K;i++){
        unordered_set<int> st;//记录颜色数
        bool proper = true;
        for(int j=0; j<N; j++){
            cin>>colorArr[j];
        }
        for(int j=0; j<M; j++){
            if(colorArr[edgeArr[j].v1] == colorArr[edgeArr[j].v2]){
                proper = false;
                break;
            }
        }
        if(proper){
            for(int j=0;j<N;j++){
                st.insert(colorArr[j]);
            }
            cout<<st.size()<<"-coloring"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
