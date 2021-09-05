#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct node{
    string str;
    int score;
} arr[10010];

bool cmp(const node &a, const node &b) {
    return a.score != b.score ? a.score > b.score : a.str < b.str;
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i].str>>arr[i].score;
    }
    for(int i=1;i<=M;i++){
        string type, term;
        cin>>type>>term;
        cout<<"Case "<<i<<": "<<type<<" "<<term<<endl;
        if(type == "1"){
            vector<node> vec;
            for(int j=0;j<N;j++){
                if(arr[j].str[0] == term[0])  vec.push_back(arr[j]);
            }
            sort(vec.begin(),vec.end(),cmp);
            for(int j=0;j<vec.size();j++){
                cout<<vec[j].str<<" "<<vec[j].score<<endl;
            }
            if(vec.size() <= 0)  cout<<"NA"<<endl;
        }
        else if(type == "2"){
            vector<int> vec;
            int totalVal = 0;
            for(int j=0;j<N;j++){
                if(arr[j].str.substr(1,3) == term)  vec.push_back(arr[j].score);
            }
            if(vec.size() <= 0)  cout<<"NA"<<endl;
            else{
                for(int j=0;j<vec.size();j++)  totalVal += vec[j];
                cout<<vec.size()<<" "<<totalVal<<endl;
            }
        }
        else if(type == "3"){
            unordered_map<string,int> mp;
            vector<node> ans;
            for(int j=0;j<N;j++){
                if(arr[j].str.substr(4,6) == term){
                    mp[arr[j].str.substr(1,3)] += 1;
                }
            }
            for (auto it : mp)  ans.push_back({it.first, it.second});
            sort(ans.begin(), ans.end(), cmp);
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].str<<" "<<ans[i].score<<endl;
            }
            if(ans.size() <= 0)  cout<<"NA"<<endl;
        }
        else{
            cout<<"NA"<<endl;
        }
    }
    return 0;
}
