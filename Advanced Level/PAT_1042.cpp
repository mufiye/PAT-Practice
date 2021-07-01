#include<iostream>

using namespace std;

string cardName[5] = {"S","H","C","D","J"};

void shuffle(int original[], int shuffleWay[], int times){
    int temp[55];
    for(int i=0;i<times;i++){
        for(int i=1;i<55;i++)  temp[i] = original[i];
        for(int i=1;i<55;i++){
            original[shuffleWay[i]] = temp[i];
        }
    }
}

//打印结果
void showRes(int arr[]){
    for(int i=1;i<55;i++){
        int charVal = arr[i]/13;
        int numVal = arr[i]%13;
        if(numVal == 0){
            numVal = 13;
            charVal--;
        }
        if(i==1)  cout<<cardName[charVal]<<numVal;
        else  cout<<" "<<cardName[charVal]<<numVal;
    }
    cout<<endl;
}

int main(){
    //card number is 54
    int times;
    int shuffleWay[55];
    int original[55];
    cin>>times;
    for(int i=1;i<55;i++)  cin>>shuffleWay[i];
    for(int i=1;i<55;i++)  original[i] = i;
    shuffle(original,shuffleWay,times);
    showRes(original);
    return 0;
}
