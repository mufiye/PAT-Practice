struct node{
    typename data;//数据域
    int lchild; //指向左子树的指针域
    int rchild; //指向右子树的指针域
}nodes[maxn]; //结点数组，maxn为节点上限

int index = 0;
int newNode(int v){ //分配一个Node数组中的节点给新的节点
    nodes[index].data = v;
    nodes[index].lchild = -1; //表示空
    nodes[index].rchild = -1; //表示空
    return index++;
}

//查找函数, root为根节点在数组中的下标
void search(int root, int x, int newdata){
    if(root == -1)  return;
    if(nodes[root].data == x)  nodes[root].data = newdata;
    search(nodes[root].lchild, x, newdata);
    search(nodes[root].rchild, x, newdata);
}

//插入, root为根节点在数组中的下标
void insert(int &root, int x){
    if(root == -1){
        root = newNode(x);
        return;
    }
    if(由二叉树的性质x应该插在左子树)  insert(nodes[root].lchild, x);
    else  insert(nodes[root].rchild, x);
}

//二叉树的建立, 函数返回根节点root的下标
int Create(int data[], int n){
    int root = -1;//新建根节点
    for(int i=0; i<n; i++)  insert(root, data[i]);
    return root;
}

//先序遍历
void preorder(int root){
    if(root == -1)  return;
    printf("%d\n", nodes[root].data);
    preorder(nodes[root].lchild);
    preorder(nodes[root].rchild);
}

//中序遍历
......
//先序遍历
......

//层序遍历
void LayerOrder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        printf("%d ", nodes[now].data);
        if(nodes[now].lchild != -1)  q.push(nodes[now].lchild);
        if(nodes[now].rchild != -1)  q.push(nodes[now].rchild);
    }
}

//PS: 如果是普通的二叉树的话，一般用不到插入这个函数
