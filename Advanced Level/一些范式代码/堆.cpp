const int maxn = 100;
int heap[maxn], n = 10; //heap为堆, n为元素个数

//对heap数组在[low, high]范围进行向下取整
//其中low为欲调整结点的数组下标, high一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high){
    int i = low, j = i*2;
    while(j <= high){
        //如果右孩子存在, 且右孩子的值大于左孩子
        if(j+1 <= high && heap[j+1]>heap[j]){
            j = j+1;
        }
        
         //如果孩子中最大的权值比欲调整结点i大
         if(heap[j] > heap[i]){
             swap(heap[j], heap[i]);
             i = j;
             j = i*2;
         } else{
             break;
         }
    }
}

//建堆
void createHeap(){
    for(int i = n/2; i>=1; i--)  downAdjust(i, n);
}

//删除堆顶元素
void deleteTop(){
    heap[1] = heap[n--]; //用最后一个元素覆盖堆顶元素, 并让元素个数减1
    downAdjust(1,n);
}

//向堆中添加一个元素, 对heap数组在 [low, high]范围进行向上调整
//其中low一般设置为1, high表示欲调整结点的数组下标
void upAdjust(int low, int high){
    int i = high, j=i/2;
    while(j >= low){ //父亲在[low, high]范围内
        if(heap[j] < heap[i]){
            swap(heap[j], heap[i]);
            i = j;
            j = i/2;
        } else{
           break;
        }
    }
}

//添加元素x
void insert(int x){
    heap[++n] = x;
    upAdjust(1,n);
}
