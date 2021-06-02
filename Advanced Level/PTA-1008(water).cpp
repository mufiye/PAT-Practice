#include<iostream>

using namespace std;

//水题
int main(){
    int N;
    int past = 0, now = 0, ans = 0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>now;
        if(now>past)  ans = ans + (now - past)*6 + 5;
        else  ans = ans + (past - now)*4 +5;
        past = now;
    }
    cout<<ans<<endl;
    return 0;
}
