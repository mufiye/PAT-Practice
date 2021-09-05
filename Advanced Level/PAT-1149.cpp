#include<iostream>
#include<vector>

using namespace std;

struct pairThing{
    int id1, id2;
} arr[10010];

bool vecFind(vector<int> &vec, int num){
    int i;
    for(i=0; i<vec.size(); i++){
        if(vec[i] == num)  break;
    }
    return  i < vec.size();
}

int main(){
    int N,M,num,id;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>arr[i].id1>>arr[i].id2;
    }
    for(int i=0;i<M;i++){
        bool isDanger = false;
        vector<int> vec;
        cin>>num;
        for(int j=0; j<num; j++){
            cin>>id;
            vec.push_back(id);
        }
        for(int j=0;!isDanger && j<N;j++){
            if(vecFind(vec,arr[j].id1) && vecFind(vec,arr[j].id2)){
                isDanger = true;
                break;
            }
        }
        if(isDanger)  cout<<"No"<<endl;
        else  cout<<"Yes"<<endl;
    }
    return 0;
}
