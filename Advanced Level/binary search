#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vec;

int main(){
    int N,P,input,number=0,min,max;
    
    //读取
    cin>>N>>P;
    for(int i=0;i<N;i++){
        cin>>input;
        vec.push_back(input);
    }
    sort(vec.begin(),vec.end());
    
    //处理
    for(int i=0;i<vec.size()-number;i++){
        min = vec[i];
        max = min*P;
        //二分搜索
        int l=i, r=vec.size()-1, mid=(l+r)/2;
        bool isFind = false;
        while(l<=r){
            mid=(l+r)/2;
            if(vec[mid]==max){
                isFind = true;
                break;
            }
            else if(vec[mid]<max){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(isFind){
            if(mid - i > number){
                number = mid-i;
            }
        }
        else{
            if(vec[mid] > max){
                number = mid-1-i;
            }
            else{
                number = mid-i;
            }
        }
    }
    cout<<number<<endl;
    return 0;
}
