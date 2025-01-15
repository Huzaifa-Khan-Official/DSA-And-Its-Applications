// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void divide_merge(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    
    int mid = (low + high) / 2;
    divide_merge(arr, low, mid);
    divide_merge(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSorting(vector<int> &arr, int n) {
    divide_merge(arr, 0, n-1);
}

int main() {
    vector<int> arr= {1, 4, 3, 2, 6, 9, 5};
    int n = arr.size();
    
    cout << "Befor Sorting: " << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    
    mergeSorting(arr, n);
    
    cout << "\nAfter Sorting: " << endl;
    for (int num : arr) {
        cout << num << " ";
    }
}