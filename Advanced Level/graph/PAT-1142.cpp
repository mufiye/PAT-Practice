#include<iostream>
#include<vector>
using namespace std;

int vecFind(vector<int> vec, int num){
    int index = 0;
    for(;index<vec.size();index++){
        if(vec[index] == num){
            return index;
        }
    }
    return index;
}

int main(){
    int Nv, Ne;
    cin>>Nv>>Ne;
    int graph[Nv+1][Nv+1] = {0};
    for(int i=0;i<Ne;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    int M;
    cin>>M;
    for(int i=0;i<M;i++){
        vector<int> vec;
        int N;
        cin>>N;
        for(int i=0;i<N;i++){
            int number;
            cin>>number;
            vec.push_back(number);
        }
        //开始判断
        //先判断是否是clique,是clique的话再判断是否是maximal clique
        bool isClique = true;
        if(vec.size() == 1){
            //size为1一定是clique,判断是否是maximal clique
            bool isMaximal = true;
            for(int i=1; i<=Nv; i++){
                bool allLink = true;
                if(vecFind(vec,i) >= vec.size()){//不在vec中
                    for(int j=0;j<vec.size();j++){
                        if(graph[i][vec[j]] != 1){
                            allLink = false;
                            break;
                        }
                    }
                }
                else  continue;
                if(allLink){
                    isMaximal = false;
                    break;
                }
            }
            if(isMaximal)  cout<<"Yes"<<endl;
            else  cout<<"Not Maximal"<<endl;
        }
        else{
            for(int i=0;isClique && i<vec.size();i++){
                for(int j=i+1;j<vec.size();j++){
                    if(graph[vec[i]][vec[j]] != 1){
                        isClique = false;
                        break;
                    }
                }
            }
            if(!isClique)  cout<<"Not a Clique"<<endl;
            else{//在判断是否为maximal Clique
                bool isMaximal = true;
                for(int i=1; i<=Nv; i++){
                    bool allLink = true;
                    if(vecFind(vec,i) >= vec.size()){//不在vec中
                        //cout<<"in"<<endl;
                        for(int j=0;j<vec.size();j++){
                            if(graph[i][vec[j]] != 1){
                                allLink = false;
                                break;
                            }
                        }
                    }
                    else  continue;
                    if(allLink){
                        isMaximal = false;
                        break;
                    }
                }
                if(isMaximal)  cout<<"Yes"<<endl;
                else  cout<<"Not Maximal"<<endl;
           }
        }
    }
    return 0;
}
