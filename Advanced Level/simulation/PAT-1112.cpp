#include<iostream>
#include<set>
#include<string>

using namespace std;
int main(){
    int k, cnt=1;
    string str;
    set<char> st, res;
    cin>>k>>str;
    char ch = str[0];
    for(int i=1; i<str.length(); i++){
        if(ch == str[i])  cnt++;
        else{
            if(cnt < k){
                st.insert(ch);
            }
            cnt = 1;
            ch = str[i];
        }
    }
    if(cnt < k)  st.insert(ch);
    ch = str[0];
    cnt = 1;
    for(int i=1; i<str.length(); i++){
        if(ch == str[i])  cnt++;
        else{
            if(cnt >= k){
                if(st.find(ch) == st.end() && res.find(ch) == res.end()){
                    res.insert(ch);
                    cout<<ch;
                }
            }
            cnt = 1;
            ch = str[i];
        }
    }
    cout<<endl;
    //消除字符串中的重复元素
    ch = str[0];
    cnt = 1;
    for(int i=1; i<str.length(); i++){
        if(ch == str[i]){
            cnt++;
//             if(cnt == k && res.find(ch) != res.end()){
//                 str.replace(i-cnt+1, cnt-1, "");
//                 i = i-cnt+1;
//             }
//             ch = str[i];
//             cnt = 0;
        }
        else{
            if(res.find(ch) != res.end()){
                str.replace(i-cnt, cnt-1, "");
                i = i-cnt+1;
            }
            ch = str[i];
            cnt = 1;
        }
    }
    //if(cnt == k)  str.replace(str.length()-cnt, cnt-1, "");
    cout<<str<<endl;
    return 0;
}
