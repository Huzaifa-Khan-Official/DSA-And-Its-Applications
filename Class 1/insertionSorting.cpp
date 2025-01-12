#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 6, 2, 8, 9, 4, 7};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Size of arr[0]: " << sizeof(arr[0]) << endl;
    cout << "Size of arr: " << sizeof(arr) << endl;
    cout << "Size of n: " << n << endl;
    
    for (int i = 0; i <= n-1; i++) {
        int j = i;
        
        while(j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            
            j--;
            cout << "runs \n";
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}