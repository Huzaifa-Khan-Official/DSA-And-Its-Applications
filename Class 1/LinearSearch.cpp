#include <iostream>
using namespace std;
#include <vector>

int main() {
    int arr[] = {3, 5, 6, 2, 4, 1, 1, 4, 6, 6, 2, 1, 2};
    cout << "Enter a number to find in array: ";
    int toSearch;
    cin >> toSearch;
    
    bool isFound = false;
    vector<int> searchIndexes;
    int arrSize = sizeof(arr) / sizeof(arr[0]); 
    for(int i = 0; i < arrSize; i++) {
        if  (toSearch == arr[i]) {
            searchIndexes.push_back(i);
            isFound = true;
        }
    }
    
    if (isFound) {
        cout << "The given number: " << toSearch << " is in the following indexes of an array: \n";
        for (int  i : searchIndexes) {
        cout << i << ' ';
        }
    } else {
        cout << "The given number: " << toSearch << " is not in the array.";
    }
}