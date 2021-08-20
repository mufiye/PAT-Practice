#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string s){
    string t = s;
    reverse(t.begin(),t.end());
    int carry = 0, len = s.length();
    for(int i=0;i<len;i++){
        t[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(t[i] > '9'){
            t[i] -= 10;
            carry = 1;
        }
    }
    if(carry) t += '1';
    reverse(t.begin(), t.end());
    return t;
}

bool isHuiwen(string s){
    string t = s;
    reverse(t.begin(),t.end());
    return  t == s;
}

int main(){
    string s;
    int k;
    cin>>s>>k;
    for(int i=0;i<=k;i++){
        //判断是否为回文数
        if(isHuiwen(s)){
            cout<<s<<endl;
            cout<<i<<endl;
            return 0;
        }
        //operation
        if(i != k)  s = add(s);
        //cout<<s<<endl;
    }
    cout<<s<<endl;
    cout<<k<<endl;
    return 0;
}
