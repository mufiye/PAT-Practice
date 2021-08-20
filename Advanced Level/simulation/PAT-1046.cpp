// 会超时
// #include<iostream>
// #include<numeric>

// using namespace std;

// int main(){
//     int n, m, distance, totalDis = 0;
//     cin>>n;
//     int arr[n+1];
//     for(int i=1; i<=n; i++){
//         cin>>distance;
//         arr[i] = distance;
//     }
//     totalDis = 0;
//     for(int i=1;i<=n;i++) totalDis += arr[i];
//     cin>>m;
//     for(int i=0; i<m; i++){
//         int a,b;
//         cin>>a>>b;
//         if(a>b){
//             int temp = a;
//             a = b;
//             b = temp;
//         }
//         int tempDis = 0;
//         if(b-a < n/2){
//             for(int j=a; j<b; j++)  tempDis += arr[j];
//         }
//         else{
//             for(int j=1; j<a; j++)  tempDis += arr[j];
//             for(int j=b;j<=n;j++)  tempDis += arr[j];
//         }
//         if(tempDis > totalDis - tempDis)  tempDis = totalDis - tempDis;
//         cout<<tempDis<<endl;
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,sum = 0,dis;
    cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        cin>>dis;
        sum += dis;
        vec[i] = sum;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b)  swap(a,b);
        int temp = vec[b-1] - vec[a-1];
        cout<<min(temp, sum - temp)<<endl;
    }
}
