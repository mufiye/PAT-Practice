//二分区间为左闭右闭[left, right]
int binarySearch(int A[], int left, int right, int x){
    int mid;
    while(left <= right){
        mid = (left + mid) / 2;
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
