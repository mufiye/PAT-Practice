//输入的是栈的push和pop信息,push对应树的先序遍历,pop对应树的中序遍历
//要求的输出是栈的后序遍历
//如何根据先序遍历和中序遍历得到后序遍历是本题的关键
//参考柳神

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;
vector<int> pre,in,post;
stack<int> stk;

void postOrder(int root, int begin, int end){
    if(begin>end)  return;
    int i = begin;
    while(i<end && in[i]!=pre[root])  i++;
    postOrder(root+1, begin, i-1);//根的左子节点的后序遍历
    postOrder(root+1+i-begin, i+1, end);//根的右子节点的后序遍历
    post.push_back(pre[root]);
}

int main(){
    int N,times,number;
    cin>>N;
    times = 2 * N;
    string str;
    for(int i=0;i<times;i++){
        cin>>str;
        if(str == "Push"){
            cin>>number;
            pre.push_back(number);
            stk.push(number);
        }
        else if(str == "Pop"){
            number = stk.top();
            stk.pop();
            in.push_back(number);
        }
    }
    postOrder(0,0,N-1);
    for(int i=0;i<post.size();i++){
        if(i!=0)  cout<<" "<<post[i];
        else cout<<post[i];
    }
    cout<<endl;
    return 0;
}
