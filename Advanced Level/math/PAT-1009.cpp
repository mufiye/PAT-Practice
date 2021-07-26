#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

/*
求两个多项式的乘积，
读取的时候最前面的数字是项数
之后每一项第一个数字为指数，第二个数字为系数
*/
//精确到小数点后一位
int main(){
    int N,M;
    vector<pair<float,int>> vec1;
    vector<pair<float,int>> vec2;
    float arr[2001] = {0.0};
    //memset(res, -1, sizeof(res));
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        float a;
        cin>>n>>a;
        vec1.emplace_back(make_pair(a,n));
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int n;
        float a;
        cin>>n>>a;
        vec2.emplace_back(make_pair(a,n));
    }
    //auto it1 = vec1.begin(), it2 = vec2.begin();
    int size1 = vec1.size(), size2 = vec2.size();
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            arr[vec1[i].second+vec2[j].second] += (vec1[i].first * vec2[j].first);
        }
    }
    int num = 0;
    for(int i = 0;i<2001;i++){
        if(arr[i] != 0) num++;
    }
    cout<<num;
    for(int i = 2000;i>=0;i--){
        if(arr[i] != 0) cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<arr[i];
    }
    cout<<endl;
    return 0;
}
