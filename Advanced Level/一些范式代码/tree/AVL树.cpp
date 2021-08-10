struct node{
    int v, height; //v为结点权值, height为当前子树高度
    node* lchild, *rchild; //左右孩子结点地址
};

//生成一个新结点, v为结点权值
node* newNode(int V){
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node; //返回新建结点的地址
}

//获取以root为根结点的子树的当前height
int getHeight(node* root){
    if(root == NULL)  return 0;
    return root->height;
}

//计算结点root的平衡因子
int getBalanceFactor(node* root){
    //左子树高度减右子树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}

//更新结点root的height
void updateHeight(node* root){
    root->height = max(getHeight(root->lchild), getHeight(root->rchild))+1;
}

//search函数查找AVL树中数据域为x的结点
void search(nnode* root, int x){
    if(root == NULL){
        printf("search failed\n");
        return;
    }
    
    if(x == root->data)  printf("%d\n", root->data);
    else if(x < root->data)  search(root->lchild, x);
    else  search(root->rchild, x);
}

//左旋
void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//右旋
void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//插入操作
void insert(node* &root, int v){
    if(root == NULL){
        root = newNode(v);
        return;
    }
    if(v < root->v){  //v比根结点的权值小
        insert(root->lchild, v); //往左子树插入
        updataHeight(root); //更新树高
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){  //LL型
                R(root);
            }  
            else if(getBalanceFactor(root->lchild) == -1){  //LR型
                L(root->lchild);
                R(root);
            }
        }
    }
    else{  //v比根节点的权值大
        insert(root->rchild, v); //往右子树插入
        updateHeight(root); //更新树高
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){  //RR型
                L(root);
            }  
            else if(getBalanceFactor(root->rchild) == 1){  //RL型
                R(root->rchild);
                L(root);
            }
        }
    }
}

//创建AVL树
node* Create(int data[], int n){
    node* root = NULL;
    for(int i=0; i<n; i++)  insert(root, data[i]);
    return root;
}
