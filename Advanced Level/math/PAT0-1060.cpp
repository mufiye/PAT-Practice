//科学计数法

#include<iostream>
#include<string>
using namespace std;

int main(){
    int N, dotIndex1, dotIndex2;
    string a,b;
    bool isSame = true;
    cin>>N>>a>>b;
    //dotIndex决定了k的值
    dotIndex1 = a.length();
    dotIndex2 = b.length();
    for(int i=0;i<a.length();i++){
        if(a[i] == '.'){
            a.erase(a.begin()+i);
            dotIndex1 = i;
            break;
        }
    }
    for(int i=0;i<b.length();i++){
        if(b[i] == '.'){
            b.erase(b.begin()+i);
            dotIndex2 = i;
            break;
        }
    }
    for(int i=0;i<N;i++){
        if(a[i] != b[i]){
            isSame = false;
            break;
        }
    }
    if(dotIndex1 != dotIndex2)  isSame = false;
    if(isSame){
        cout<<"YES ";
        cout<<"0.";
        for(int i=0;i<N && i<a.length();i++){
            cout<<a[i];
        }
        cout<<"*10^"<<dotIndex1<<endl;
    }
    else{
        cout<<"NO ";
        cout<<"0.";
        for(int i=0;i<N && i<a.length();i++){
            cout<<a[i];
        }
        cout<<"*10^"<<dotIndex1;
        
        cout<<" 0.";
        for(int i=0;i<N && i<b.length();i++){
            cout<<b[i];
        }
        cout<<"*10^"<<dotIndex2<<endl;
    }
    return 0;
}
