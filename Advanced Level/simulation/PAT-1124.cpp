#include<unordered_set>
#include<iostream>

using namespace std;

int main(){
    int m,n,s;
    string str;
    unordered_set<string> st;
    cin>>m>>n>>s;
    int cnt = n;
    for(int i=1;i<=m;i++){ //i代表行数
        cin>>str;
        if(i>=s){ //到达了开始下标
            if(cnt == n){
                if(st.find(str) == st.end()){
                    cnt = 1;
                    cout<<str<<endl;
                    st.insert(str);
                }
            }
            else{
                cnt++;
            }
        }
    }
    if(st.size() <= 0)  cout<<"Keep going..."<<endl;
    return 0;
}
