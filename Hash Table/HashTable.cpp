#include <iostream>
#include <vector>

class HashTable
{
private:
    static const int TABLE_SIZE = 10; // Size of the hash table
    std::vector<int> table;           // Vector to represent the hash table

public:
    HashTable() : table(TABLE_SIZE, -1) {}

    // Function to perform a basic hash function (modulo operation)
    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

    // Function to insert a key into the hash table
    void insert(int key)
    {
        int index = hashFunction(key);

        // Linear probing to handle collisions
        while (table[index] != -1)
        {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key;
        std::cout << "Inserted key " << key << " at index " << index << std::endl;
    }

    // Function to search for a key in the hash table
    bool search(int key)
    {
        int index = hashFunction(key);

        // Linear probing to find the key
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                std::cout << "Key " << key << " found at index " << index << std::endl;
                return true;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        std::cout << "Key " << key << " not found in the hash table" << std::endl;
        return false;
    }

    // Function to delete a key from the hash table
    void remove(int key)
    {
        int index = hashFunction(key);

        // Linear probing to find the key
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                table[index] = -1;
                std::cout << "Deleted key " << key << " from index " << index << std::endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }

        std::cout << "Key " << key << " not found in the hash table" << std::endl;
    }

    // Function to display the contents of the hash table
    void display()
    {
        std::cout << "Hash Table Contents:\n";
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            std::cout << "Index " << i << ": ";
            if (table[i] != -1)
            {
                std::cout << table[i];
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    HashTable myHashTable;

    // Insert some keys into the hash table
    myHashTable.insert(5);
    myHashTable.insert(15);
    myHashTable.insert(25);

    // Display the contents of the hash table
    myHashTable.display();

    // Search for a key in the hash table
    myHashTable.search(15);

    // Remove a key from the hash table
    myHashTable.remove(15);

    // Display the updated contents of the hash table
    myHashTable.display();

    return 0;
}
