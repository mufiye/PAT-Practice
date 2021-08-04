/*
  展示的是带有压缩的版本
*/

//初始化
int father[size];
for(int i=0;i<size;i++){
    father[i] = i;
}

//find函数
int find(int x){
    int a = x;
    while(x != father[x])
      x = father[x];
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

//合并的函数
void union(int a, int b){
     a = find(a);
     b = find(b);
     if(a != b)  father[a] = b; //写成 father[b] = a 也一样
}
