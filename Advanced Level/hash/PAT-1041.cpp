//由于STL库中的map结构和unordered_map结构的遍历顺序都无法做到如队列一般先进先出,我使用vector记录了顺序

#include<iostream>
#include<unordered_map>
#include<vector>
//#define debug

using namespace std;

int main(){
    int N;
    cin>>N;
    unordered_map<int,int> mp;
    vector<int> vec;
    //读取
    for(int i=0;i<N;i++){
        int number;
        cin>>number;
        vec.push_back(number);
        if(mp.find(number) == mp.end())  mp.insert(pair<int,int>(number,1));
        else  mp[number]++;
    }
    
    //输出
#ifdef debug
    for(auto it=mp.begin(); it!=mp.end(); it++){
        cout<<"number: "<<it->first<<"  times: "<<it->second<<endl;
    }
#endif
    bool isFind = false;
    for(size_t i=0; i<vec.size(); i++){
        auto it = mp.find(vec[i]);
        if(it->second == 1){
            cout<<it->first<<endl;
            isFind = true;
            break;
        }
    }
    if(!isFind)  cout<<"None"<<endl;
    return 0;
}
