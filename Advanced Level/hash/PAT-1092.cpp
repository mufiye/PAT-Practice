/*
  买珠子,所有的字符都要有(考虑同类珠子的数量)
  如果都有则输出Yes以及多余的珠子的数量
  如果有没有的则输出No以及少的珠子的数量
*/
#include<iostream>

using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;//没有空格
    int FindIndex;
    for(int i=0;i<s2.length();i++){
        if((FindIndex=s1.find(s2[i])) != string::npos){
            s1.erase(FindIndex,1);
            s2.erase(i,1);
            i--;
        }
    }
    if(s2.length() == 0){
        cout<<"Yes "<<s1.length()<<endl;
    }
    else if(s2.length()>0){
        cout<<"No "<<s2.length()<<endl;
    }
    return 0;
}
