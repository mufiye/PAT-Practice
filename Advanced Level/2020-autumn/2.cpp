#include<iostream>

using namespace std;

int arr[10010];

int main(){
    int N, M, cnt = 0;
    cin>>N>>M;
    for(int i=0; i<N; i++)  cin>>arr[i];
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=i; j<N; j++){
            sum += arr[j];
            if(sum > M){
                break;
            }
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
