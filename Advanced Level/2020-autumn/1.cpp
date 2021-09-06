#include<iostream>

using namespace std;

int weight[10010], milkA[10010], milkB[10010];
int N, sum = 0;

int main(){
    cin>>N;
    for(int i=0; i<N; i++)  cin>>weight[i];
    milkA[0] = 200;
    for(int i=1; i<N; i++){
        if(weight[i] > weight[i-1])  milkA[i] = milkA[i-1] + 100;
        else if(weight[i] == weight[i-1])  milkA[i] = milkA[i-1];
        else  milkA[i] = 200;
    }
    milkB[N-1] = 200;
    for(int i=N-2; i>=0; i--){
        if(weight[i] > weight[i+1])  milkB[i] = milkB[i+1] + 100;
        else if(weight[i] == weight[i+1])  milkB[i] = milkB[i+1];
        else  milkB[i] = 200;
    }
    for(int i=0; i<N; i++)  sum += max(milkA[i], milkB[i]);
    cout<<sum<<endl;
    return 0;
}
