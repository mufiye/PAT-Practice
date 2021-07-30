#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool isPrime(int number){
    if(number <= 1) return false;
    for(int i=2;i*i<=number;i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int N,L,number;
    string str;
    //bool isFind = false;
    cin>>N>>L>>str;
    for(int i=0;i<=N-L;i++){
        string sstr = str.substr(i,L);
        number = stoi(sstr);
        if(isPrime(number)){
            cout<<sstr;
            return 0;
        }
    }
    cout<<"404"<<endl;
    return 0;
}
