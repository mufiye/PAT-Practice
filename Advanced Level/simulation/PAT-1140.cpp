// 理解错了题意。。
// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     int d,n;
//     cin>>d>>n;
//     string s;
//     s = to_string(d);
//     for(int i=0;i<n;i++){
//         map<char,int> mp;
//         for(int j=0;j<s.length();j++){
//             if(!mp.count(s[j]))  mp[s[j]] = 1;
//             else  mp[s[j]]++;
//         }
//         map<char,int>::iterator it;
//         s = "";
//         for(it = mp.begin(); it!=mp.end(); it++){
//             s += it->first;
//             s += to_string(it->second);
//         }
//         cout<<s<<endl;
//     }
//     cout<<s<<endl;
// }

#include<iostream>
#include<string>
using namespace std;
int main(){
    int d,n;
    cin>>d>>n;
    string s = to_string(d);
    for(int i=0; i<n-1; i++){
        string t = "";
        char ch = s[0];
        int cnt = 1;
        for(int j=1; j<s.length(); j++){
            if(s[j] == ch){
                cnt++;
            }
            else{
                t += ch;
                t += to_string(cnt);
                ch = s[j];
                cnt = 1;
            }
        }
        t += ch;
        t += to_string(cnt);
        s = t;
        //cout<<s<<endl;
    }
    cout<<s<<endl;
    return 0;
}
