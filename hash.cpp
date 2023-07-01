#include <iostream>
using namespace std;

const int TABLE_SIZE = 100;

// HashNode represents a key-value pair in the hash table
struct HashNode {
    int key;
    int value;
    HashNode* next;
};

// HashTable represents the hash table data structure
class HashTable {
private:
    HashNode** table;

public:
    HashTable() {
        table = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    // Hash function that calculates the index value as the key modulo 100
    int HashFunc(int key) {
        return key % TABLE_SIZE;
    }

    // Insert a key-value pair into the hash table
    void Insert(int key, int value) {
        int index = HashFunc(key);

        HashNode* newNode = new HashNode;
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            HashNode* current = table[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for a key in the hash table and return its value if found
    int Search(int key) {
        int index = HashFunc(key);

        HashNode* current = table[index];
        while (current != NULL) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        return -1; // Key not found
    }
};

int main() {
    HashTable hashTable;

    // Insert key-value pairs into the hash table
    hashTable.Insert(123, 10);
    hashTable.Insert(456, 20);
    hashTable.Insert(789, 30);

    // Search for keys and retrieve their values
    int value1 = hashTable.Search(123);
    if (value1 != -1) {
        cout << "Value for key 123: " << value1 << endl;
    } else {
        cout << "Key 123 not found" << endl;
    }

    int value2 = hashTable.Search(456);
    if (value2 != -1) {
        cout << "Value for key 456: " << value2 << endl;
    } else {
        cout << "Key 456 not found" << endl;
    }

    int value3 = hashTable.Search(789);
    if (value3 != -1) {
        cout << "Value for key 789: " << value3 << endl;
    } else {
        cout << "Key 789 not found" << endl;
    }

    return 0;
}
