//找出单身狗
//输出的序列是从小到大有序的
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iomanip>
#define max_size 100000
using namespace std;

int couples1[max_size]={-1};
int couples2[max_size]={-1};
int main(){
    vector<int> res;
    unordered_set<int> st;
    int N,M,num1,num2;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num1>>num2;
        couples1[num1] = num2;
        couples2[num2] = num1;
    }
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>num1;
        st.insert(num1);
    }
    for(auto it=st.begin();it!=st.end();it++){
        if(st.find(couples1[*it])==st.end() && st.find(couples2[*it])==st.end())  res.push_back(*it);
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(size_t i=0;i<res.size();i++){
        if(i!=0)  printf(" %05d", res[i]);
        else  printf("%05d", res[i]);
    }
    cout<<endl;
    return 0;
}
