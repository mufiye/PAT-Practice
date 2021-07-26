#include<iostream>
#include<vector>
#include<set>
#include<string>
#include <cstring>

using namespace std;

int main(){
    //用char vector记录第一个字符串, 用set记录第二个字符串
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    set<char> st;
    vector<char> vec;
    int l1 = s1.length(), l2 = s2.length();
    char p1[l1];
    char p2[l2];
    strcpy(p1,s1.c_str());
    strcpy(p2,s2.c_str());
    
    for(int i=0;i<l1;i++){
        vec.push_back(p1[i]);
    }
    for(int i=0;i<l2;i++){
        st.insert(p2[i]);
    }
    for(size_t i=0;i<l1;i++){
        if(st.find(vec[i]) == st.end())  cout<<vec[i];
    }
    cout<<endl;
    return 0;
}
