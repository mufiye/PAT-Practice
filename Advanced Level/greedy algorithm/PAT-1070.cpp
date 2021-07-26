#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Cake{
    int number;
    double price;
};

bool cmp(Cake c1, Cake c2){
    return c1.price/c1.number > c2.price/c2.number;
}

int main(){
    int N,M;
    int curNum = 0;
    double totalPrice=0.0;
    vector<Cake> vec;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        Cake cake;
        cin>>cake.number;
        vec.push_back(cake);
    }
    for(int i=0;i<N;i++){
        cin>>vec[i].price;
    }
    sort(vec.begin(), vec.end(), cmp);
    int i=0;
    while(curNum<M && i<vec.size()){
        if(vec[i].number + curNum < M){
            curNum += vec[i].number;
            totalPrice += vec[i].price;
        }
        else{
            int num = M - curNum;
            totalPrice = totalPrice + vec[i].price*num/vec[i].number;
            break;
        }
        i++;
    }
    printf("%0.2f\n",totalPrice);
    return 0;
}
