#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
    int N,M;
    int minDis = 100000000, minIndex = -1;
    cin>>N>>M;
    int graph[N+1][N+1] = {0};
    for(int i=0;i<M;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b] = graph[b][a] = w;
    }
    int K;
    cin>>K;
    for(int i=1;i<=K;i++){
        int num, dis = 0;
        bool isPath = true;
        cin>>num;
        int arr[num];
        for(int j=0;j<num;j++){
            cin>>arr[j];
        }
        //先要是cycle,然后才能是simple cycle,两者皆不是则为not cycle
        for(int j=0;j<num-1;j++){
            if(graph[arr[j]][arr[j+1]] != 0){
                dis += graph[arr[j]][arr[j+1]];
            }
            else{
                isPath = false;
                break;
            }
        }
        if(!isPath){
            cout<<"Path "<<i<<": NA (Not a TS cycle)"<<endl;
        }
        else{
            //判断是否为ts cycle
            unordered_set<int> st;
            for(int j=0;j<num;j++){
                st.insert(arr[j]);
            }
            if(st.size() == N && arr[0] == arr[num-1]){
                //此时为cycle,判断是否为simple cycle
                if(dis<minDis){
                    minDis = dis;
                    minIndex = i;
                }
                if(num == N+1){
                    cout<<"Path "<<i<<": "<<dis<<" (TS simple cycle)"<<endl;
                }
                else{
                    cout<<"Path "<<i<<": "<<dis<<" (TS cycle)"<<endl;
                }
            }
            else{
                cout<<"Path "<<i<<": "<<dis<<" (Not a TS cycle)"<<endl;
            }
        }
    }
    cout<<"Shortest Dist("<<minIndex<<") = "<<minDis<<endl;
    return 0;
}
