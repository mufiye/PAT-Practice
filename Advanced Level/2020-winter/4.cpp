#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int N, M, K;
string str;
unordered_set<int> st;
vector<vector<int>> equations[55];
vector<int> query;
vector<int> ans;//存放结果

void dfs(int product_index){
    
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        st.insert(num);
        vector<int> temp(1, num);
        equations[num].push_back(temp);
    }
    cin>>M;
    for(int i=0; i<M; i++){
        int num;
        cin>>num;
        query.push_back(num);
    }
    cin>>K;
    getchar();
    for(int i=0; i<K; i++){
        //如何读取输入?
        int num;
        string t;
        vector<int> temp;
        while(1){
            cin>>num>>t;
            temp.push_back(num);
            if(t != "+")  break;
        }
        cin>>num;
        sort(temp.begin(), temp.end());
        equations[num].push_back(temp);
    }
    for(auto item : query){
        sort(equations[item].begin(), equations[item].end());
    }
    //从第一个要求产物开始dfs
    dfs(0);
    return 0;
}
