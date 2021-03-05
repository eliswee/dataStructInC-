//
//  MergeSort.h
//  dataStructInC++
//
//  Created by May on 2021/2/23.
//

#ifndef MergeSort_h
#define MergeSort_h


/*
 归并的两种方式：
    自顶向下：递归
    自底向上：迭代。没有使用随机访问特性，可以对链表进行nlogn排序
 为什么第一种比第二种快？
 */

// 将arr[l...mid] 和 arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l , int mid, int r) {
    
    T aux[r-l+1]; // create new array
    
    for (int i = l ; i <= r; i++) {
        aux[i - l] = arr[i]; // copy arr
    }
    
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {
        if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (aux[i - l] > aux[j - l]) {
            arr[k] = aux[j - l];
            j++;
        } else {
            arr[k] = aux[i - l];
            i++;
        }
    }
}

// 递归排序，对arr[r...l]进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r ) {
    if (l >= r) {
        return;
    }
    
    int mid = (l + (r - l)/2);
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid ,r );
}

// 优化：
// 1.当mid之前和之后无交叉元素代表已经有序，不进行merge.
// 2.当区间范围小到一定程度时，区间内元素大概率有序，可以使用插入排序
// 3.数据规模比较小的时候算法复杂度的常数系数作用比较大
template<typename T>
void __mergeSort_1(T arr[], int l, int r ) {
    
    // 对于小规模数组,使用插入排序
    if (r - l >= 15) {
        insertionSort(arr, l, r);
        return;
    }
    int mid = (l + (r-l)/2);
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    
    // 对于arr[mid] <= arr[mid+1]的情况,不进行merge
    // 对于近乎有序的数组非常有效,但是对于一般情况,由于多了一次if，有一定的性能损失
    if (arr[mid] > arr[mid + 1]) {
        __merge(arr, l, mid, r);
    }
}

template<typename  T>
void mergeSortBU(T arr[], int n) {
    for ( int sz = 1; sz < n; sz += sz ) {
        for (int i = 0; <#condition#>; <#increment#>) {
            <#statements#>
        }
    }
}

template<typename T>
void mergeSort(T arr[], int n) {
//    __mergeSort(arr, 0, n - 1);
    __mergeSort_1(arr, 0, n);
}

#endif /* MergeSort_h */
