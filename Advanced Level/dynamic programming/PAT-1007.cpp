#include<iostream>

using namespace std;

int main(){
    int K;
    cin>>K;
    int arr[K];
    int temp = 0, sum = -1, tempIndex = 0, leftIndex = 0, rightIndex = K-1;
    for(int i=0; i<K; i++){
        cin>>arr[i];
        temp = temp + arr[i];
        if(temp < 0){
            temp = 0;
            tempIndex = i + 1;
        }
        else if(temp > sum){
                sum = temp;
                leftIndex = tempIndex;
                rightIndex = i;
        }
    }
    if(sum<0)  sum = 0;
    cout<<sum<<" "<<arr[leftIndex]<<" "<<arr[rightIndex];
    return 0;
}
