#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct customer{
    int id; //1~N
    int order; //cmp
    int weight;
};

struct hat{
    int id; //1~N
    int order; //cmp
    int num;
};

bool cmph1(hat h1, hat h2){
    return h1.num > h2.num;
}

bool cmpc1(customer c1, customer c2){
    return c1.weight > c2.weight;
}

bool cmph2(hat h1, hat h2){
    return h1.id < h2.id;
}

int main(){
    int N;
    vector<hat> vec1;
    vector<customer> vec2;
    unordered_map<int,int> mp;
    cin>>N;
    for(int i=N; i>=1; i--){
        hat h;
        cin>>h.num;
        h.id = i;
        vec1.push_back(h);
    }
    for(int i=1; i<=N; i++){
        customer c;
        cin>>c.weight;
        c.id = i;
        vec2.push_back(c);
    }
    sort(vec1.begin(), vec1.end(), cmph1);
    sort(vec2.begin(), vec2.end(), cmpc1);
    for(int i=0; i<vec1.size(); i++)  vec1[i].order = i;
    for(int i=0; i<vec2.size(); i++){
        mp[i] = vec2[i].id;
    }
    sort(vec1.begin(), vec1.end(), cmph2);
    for(int i=0; i<vec1.size(); i++){
        if(i != 0)  cout<<" "<<mp[vec1[i].order];
        else  cout<<mp[vec1[i].order];
    }
    return 0;
}
