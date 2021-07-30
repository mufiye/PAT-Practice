//连续子序列的和
#include<iostream>

using namespace std;

int main(){
    int N;
    double sum = 0.0;
    cin>>N;
    for(int i=0;i<N;i++){
        double number;
        cin>>number;
        sum += number*(i+1)*(N-i);
    }
    printf("%.2lf",sum);
    return 0;
}
