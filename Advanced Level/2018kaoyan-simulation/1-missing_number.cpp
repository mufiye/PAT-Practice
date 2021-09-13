#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    int N, number;
    unordered_set<int> st;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>number;
        st.insert(number);
    }
    int num = 1;
    while(true){
        if(st.find(num) == st.end()){
            cout<<num;
            return 0;
        }
        num++;
    }
}
