#include <iostream>
using namespace std;

class HashTable {
    private:
        int *table;
        int size;
        
    public:
        HashTable(int size) {
            this->size = size;
            table = new int[size];
            for (int i = 0; i < size; i++) {
                table[i] = -1;
            }
        }
    
        ~HashTable() {
            delete[] table;
        }
    
        int hashFunction(int key) {
            return key % size; // 52 % 7 = 3
        }
    
        void insert(int key) {
            int index = hashFunction(key); // 3
            int startIndex = index; // 3
            while (table[index] != -1) { // table[3] != -1 (true)
                // if (table[index] == key) {
                //     cout << "Key " << key << " already exists at index " << index << endl;
                //     return;
                // }
                index = (index + 1) ^ 2 % size;
                if (index == key % size) {
                    cout << "Hash table is full!" << endl;
                    return;
                }
            }
            table[index] = key;
            cout << "Inserted " << key << " at index " << index << endl;
        }
    
        int search(int key) {
            int index = hashFunction(key);
            int startIndex = index;
            while (table[index] != -1) {
                if (table[index] == key) {
                    return index;
                }
                index = (index + 1) % size;
                if (index == startIndex) {
                    break;
                }
            }
            return -1;
        }
    
        void display() {
            cout << "Hash Table:" << endl;
            for (int i = 0; i < size; i++) {
                if (table[i] != -1) {
                    cout << "Index " << i << ": " << table[i] << endl;
                } else {
                    cout << "Index " << i << ": None" << endl;
                }
            }
        }
};

int main() {
    HashTable ht(7);
    ht.insert(52);
    ht.insert(64);
    ht.insert(73);
    ht.insert(73);
    ht.insert(85);
    ht.insert(85);
    ht.insert(51);
    // ht.insert(50);
    ht.display();

    // int keyToSearch = 20;
    // int result = ht.search(keyToSearch);
    // if (result != -1) {
    //     cout << "Found " << keyToSearch << " at index " << result << endl;
    // } else {
    //     cout << keyToSearch << " not found in the table" << endl;
    // }

    // keyToSearch = 50;
    // result = ht.search(keyToSearch);
    // if (result != -1) {
    //     cout << "Found " << keyToSearch << " at index " << result << endl;
    // } else {
    //     cout << keyToSearch << " not found in the table" << endl;
    // }

    return 0;
}
