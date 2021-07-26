#include<iostream>
#include<set>
#include<vector>

using namespace std;

int getFriendNum(int num){
    int res = 0;
    while(num != 0){
        res = res + num%10;
        num = num/10;
    }
    return res;
}

int main(){
    int N,number;
    vector<int> vec;
    set<int> res;//元素不重复且自动有序的,底层是红黑树
    cin>>N;
    //读取
    for(size_t  i=0;i<N;i++){
        cin>>number;
        vec.push_back(number);
    }
    
    //获取friend number
    for(size_t i=0;i<vec.size();i++){
        int number = getFriendNum(vec[i]);
//         cout<<vec[i]<<": "<<number<<endl;
        res.insert(number);
    }
    
    //输出
    cout<<res.size()<<endl;
    for(auto it = res.begin(); it!=res.end(); it++){
        if(it != res.begin())  cout<<" "<<*it;
        else  cout<<*it;
    }
    cout<<endl;
}
