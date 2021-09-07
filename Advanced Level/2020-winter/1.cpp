#include<iostream>

using namespace std;

int main(){
    int N, pre = 0, now = 1;
    cin>>N;
    while(now < N){
        int temp = now;
        now = pre + now;
        pre = temp;
    }
    if(now - N < N - pre)  cout<<now;
    else  cout<<pre;
    return 0;
}
