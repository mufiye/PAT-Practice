//二分区间为左闭右闭[left, right]
int binarySearch(int A[], int left, int right, int x){
    int mid;
    while(left <= right){
        mid = left + (right - left)/2; //效果同mid=(left+right)/2,但是这样可以防止溢出
        if(A[mid] == x)  return mid;
        else if(A[mid] > x){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

//如何求序列中第一个大于等于x的元素的位置
int lower_bound(int A[], int left, int right){
    int mid;
    while(left < right){
        mid = (left + right)/2;
        if(A[mid] >= x)  right = mid;
        else  left = mid+1;
    }
    return left;
}

//如何求序列中第一个大于x的元素的位置
int upper_bound(int A[], int left, int right){
    int mid;
    while(left < right){
        mid = (left+right) / 2;
        if(A[mid] > x)  right = mid;
        else  left = mid+1
    }
    return left;
}
