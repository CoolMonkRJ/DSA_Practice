class MyHashMap {
private:

    // Total number of buckets.
    // Using a prime number gives a better distribution.
    static const int SIZE = 1009;

    // Every bucket is a linked list of (key, value) pairs.
    vector<list<pair<int,int>>> buckets;

    // Hash Function
    // Converts any key into a bucket index.
    int hash(int key)
    {
        return key % SIZE;
    }

public:

    // Constructor
    MyHashMap()
    {
        // Create SIZE empty buckets.
        buckets.resize(SIZE);
    }

    // Insert or Update
    void put(int key, int value)
    {
        // Find which bucket this key belongs to.
        int index = hash(key);

        // Search inside that bucket.
        for(auto &node : buckets[index])
        {
            // If key already exists
            if(node.first == key)
            {
                // Update its value.
                node.second = value;
                return;
            }
        }

        // Key not found.
        // Add new (key,value) pair.
        buckets[index].push_back({key,value});
    }

    // Search
    int get(int key)
    {
        int index = hash(key);

        // Search only inside one bucket.
        for(auto &node : buckets[index])
        {
            if(node.first == key)
            {
                return node.second;
            }
        }

        // Key doesn't exist.
        return -1;
    }

    // Delete
    void remove(int key)
    {
        int index = hash(key);

        // Traverse linked list.
        for(auto it = buckets[index].begin();
            it != buckets[index].end();
            it++)
        {
            if(it->first == key)
            {
                buckets[index].erase(it);
                return;
            }
        }
    }
};