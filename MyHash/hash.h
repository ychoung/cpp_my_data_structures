#ifndef HASH_H
#define HASH_H

#include <functional>

template<typename K, typename V>
class hash
{
private:
    struct Node
    {
        K key;
        V value;
        Node* next;

        Node(K k, V v, Node* n)
        {
            key = k;
            value = v;
            next = n;
        }
    };

    Node** hashmap;
    int size;
    int capacity;

    void init();
    size_t hashing(K);
    int indexMapping(size_t);
    Node* find(int, K);
    Node* findParent(int, K);
    void rehashing();

public:
    hash(int);
    ~hash();

    void insert(K, V);
    V& operator[](K);
    void clear();
    void erase(K);
};

#endif


template <typename K, typename V>
inline void hash<K, V>::init()
{
    for (int i = 0; i < capacity; i++)
        hashmap[i] = nullptr;
}


template <typename K, typename V>
inline size_t hash<K, V>::hashing(K key)
{
    return std::hash<K>{}(key);
}


template <typename K, typename V>
inline int hash<K, V>::indexMapping(size_t hash)
{
    return hash % capacity;
}


template <typename K, typename V>
inline typename hash<K,V>::Node* hash<K, V>::find(int idx, K key)
{
    Node* tmp = hashmap[idx];
    if(tmp ==  nullptr) return nullptr;

    while(tmp != nullptr)
    {
        if(tmp->key == key)
            return tmp;

        tmp = tmp->next;
    }

    return nullptr;
}

template <typename K, typename V>
inline typename hash<K,V>::Node* hash<K, V>::findParent(int idx, K key)
{
    Node* parent = hashmap[idx];

    if(parent == nullptr) return nullptr;

    while(parent->next->key != key)
    {
        parent = parent->next;
    }

    return parent;
}

template <typename K, typename V>
inline void hash<K, V>::rehashing()
{
    capacity *= 2;

    Node** newHashmap = new Node*[capacity]; // create 2 times larger array
    Node** oldHashmap = hashmap; // name current hashmap old
    hashmap = newHashmap; // hashmap points to larger hashmap

    init(); // initialize new hashmap

    Node* guest;
    int newIdx;

    for (int i = 0; i < (capacity >> 1); i++)
    {
        guest = oldHashmap[i];
        while(guest != nullptr)
        {
            oldHashmap[i] = guest->next;
            newIdx = indexMapping(hashing(guest->key)); // make a new Index

            guest->next = hashmap[newIdx]; // make node points to new room. 
            hashmap[newIdx] = guest;

            guest = oldHashmap[i];
        }
    }

    delete[] oldHashmap; oldHashmap = nullptr;
    
}


template <typename K, typename V>
inline hash<K, V>::hash(int capacity)
{
    hashmap = new Node*[capacity];
    
    this->capacity = capacity;
    this->size = 0;

    init();
}


template <typename K, typename V>
inline hash<K, V>::~hash()
{
    clear();
    
    delete[] hashmap; hashmap = nullptr;
}


template <typename K, typename V>
inline void hash<K, V>::insert(K key, V value)
{
    if (size >= capacity * 2)
        rehashing();
    
    int idx = indexMapping(hashing(key));
    Node* replaced = find(idx, key);

    if(replaced != nullptr)
    {
        replaced->value = value;
        return;
    }

    Node* newNode = new Node(key, value, hashmap[idx]); // new node points to previous hashmap[key]
    hashmap[idx] = newNode;
    size++;
}

template <typename K, typename V>
inline V &hash<K, V>::operator[](K key)
{
    int idx = indexMapping(hashing(key));
    Node* tmp = find(idx, key);

    if(tmp ==  nullptr)
    {
        tmp = new Node(key, V(), hashmap[idx]);
        hashmap[idx] = tmp;
        size++;
    }

    return tmp->value;
}

template <typename K, typename V>
inline void hash<K, V>::clear()
{
    if(hashmap ==  nullptr) return;

    Node* deleted;

    for(int i = 0; i < capacity; i++)
    {
        deleted = hashmap[i];

        while(deleted != nullptr)
        {
            hashmap[i] = deleted->next;
            delete deleted;
            deleted = hashmap[i];
        }
    }
    size = 0;
}

template <typename K, typename V>
inline void hash<K, V>::erase(K key)
{
    int idx = indexMapping(hashing(key));
    Node* erased = find(idx, key);

    if(erased == nullptr) return;

    if(hashmap[idx] == erased)
    {
        hashmap[idx] = erased->next;
        delete erased; erased = nullptr;
        size--;
        return;
    }

    Node* parent = findParent(idx, key);
    parent->next = erased->next;
    
    delete erased; erased = nullptr;
    size--;
}
