#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct Node{
    int startAddress;
    int startIndex;
    int length;
};

int main(){
    int N, K, pre = 0, len=0, address, maxIndex;
    vector<Node> vec;
    unordered_set<int> st;
    cin>>N>>K;
    for(int i=0; i<N; i++){
        pre += len;
        cin>>address>>len;
        Node node;
        node.startAddress = address;
        node.length = len;
        node.startIndex = pre;
        vec.push_back(node);
    }
    maxIndex = pre+len;
    for(int i=0; i<K; i++){
        int indexNum;
        cin>>indexNum;
        //handle 
        if(indexNum >= 0 && indexNum < maxIndex){
            int j;
            for(j=0; j<N; j++){
                st.insert(j);
                if(vec[j].startIndex + vec[j].length > indexNum && indexNum >= vec[j].startIndex){
                   break;
                }
            }
            cout<<vec[j].startAddress + (indexNum-vec[j].startIndex)*4<<endl;
        }
        else{
            cout<<"Illegal Access"<<endl;
        }
    }
    cout<<st.size()<<endl;
    return 0;
}
