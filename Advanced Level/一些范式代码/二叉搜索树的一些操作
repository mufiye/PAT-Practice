//查找, search函数查找二叉搜索树中数据域为x的结点
void search(node* root, int x){
    if(root == NULL){
        printf("search failed\n");
        return;
    }

    if(x == root->data)  printf("%d\n", root->data);
    else if(x < root->data)  search(root->lchild, x);
    else  search(root->rchild, x);
}

//插入操作
void insert(node* &root, int x){ //注意要加&符号
    if(root == NULL){
        root = new Node(x);
        return;
    }
    
    if(x == root->data)  return;
    else if(x < root->data)  insert(root->lchild, x);
    else  insert(root->rchild, x);
}

//二叉查找树的建立
node* Create(int data[], int n){
    node* root = NULL;
    for(int i=0; i<n; i++)  insert(root, data[i]);
    return root;
}

//寻找以root为根节点的树中的最大权值结点
node* findMax(node* root){
    while(root->rchild != NULL)  root = root->rchild;
    return root;
}

//寻找以root为根节点的树中的最小权值结点
node* findMin(node* root){
    while(root->lchild != NULL)  root = root->lchild;
    return root;
}

//删除以root为根结点的树中权值为x的结点
void deleteNode(node* &root, int x){
    if(root == NULL)  return;
    if(root->data == x){//找到了欲删除的结点
        if(root->lchild == NULL && root->rchild == NULL){
            root = NULL;
        }
        else if(root->lchild != NULL){ //左子树不为空时
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data); //在左子树中删除结点pre
        }
        else{ //右子树不为空时
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data); //在右子树中删除结点next
        }
        else if(root->data > x){
            deleteNode(root->lchild, x); //在左子树中删除x
        }
        else{
            deleteNode(root->rchild, x); //在右子树中删除x
        }
    }
}

//一个性质，对二叉搜索树进行中序遍历，遍历的结果是有序的
