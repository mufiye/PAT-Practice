#include<iostream>

using namespace std;

int weight[10010];
int milk[10010];
int N,sum=0;

int main(){
    fill(milk, milk+10010, 200);
    cin>>N;
    for(int i=0; i<N; i++)  cin>>weight[i];
    for(int i=0; i<N-1; i++){
        while(milk[i] <= milk[i+1] && weight[i] > weight[i+1]){
            milk[i] += 100;
        }
        while(milk[i] >= milk[i+1] && weight[i] < weight[i+1]){
            milk[i+1] += 100;
        }
        while(milk[i] > milk[i+1] && weight[i] == weight[i+1]){
            milk[i+1] += 100;
        }
        while(milk[i+1] > milk[i] && weight[i] == weight[i+1]){
            milk[i] += 100;
        }
    }
    for(int i=N-1; i>=0; i--){
        while(milk[i] <= milk[i+1] && weight[i] > weight[i+1]){
            milk[i] += 100;
        }
        while(milk[i] >= milk[i+1] && weight[i] < weight[i+1]){
            milk[i+1] += 100;
        }
        while(milk[i] > milk[i+1] && weight[i] == weight[i+1]){
            milk[i+1] += 100;
        }
        while(milk[i+1] > milk[i] && weight[i] == weight[i+1]){
            milk[i] += 100;
        }
    }
    for(int i=0;i<N;i++)  sum += milk[i];
    cout<<sum<<endl;
    return 0;
}
