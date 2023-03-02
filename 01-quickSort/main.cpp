//
//  main.cpp
//  01-quickSort
//
//  Created by dry on 2023/2/28.
//

#include <iostream>
#include <vector>

using namespace std;

// 分治函数
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];  // 选取第一个元素作为基准值
    int i = left, j = right;
    while (i < j) {
        // 从右侧开始查找小于等于基准值的元素
        while (i < j && arr[j] > pivot) {
            j--;
        }
        // 从左侧开始查找大于等于基准值的元素
        while (i < j && arr[i] <= pivot) {
            i++;
        }
        // 如果左右指针未相遇，则交换两个指针所指向的元素
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // 最后将基准值与指针相遇的元素交换
    swap(arr[left], arr[i]);
    return i;
}

// 快速排序递归函数
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotPos = partition(arr, left, right);
    quickSort(arr, left, pivotPos - 1);
    quickSort(arr, pivotPos + 1, right);
}

// 对外接口
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// 测试代码
int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    quickSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
