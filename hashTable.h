//
// Created by Caaaarl on 2022-08-20.
//

#ifndef DOA_LABB3_V1_HASHTABLE_H
#define DOA_LABB3_V1_HASHTABLE_H
//Time Complexity: O(1)
//Worst: O(n)
class hashTable {
    struct Node {
        size_t data;
        std::unique_ptr<Node> next;
    };
    std::vector<std::unique_ptr<Node>> hashtable;

    size_t hashFunc(size_t data, size_t size) const{
        return (data % size);
    }


    bool isPrime(int n)
    {
        // Corner cases
        if (n <= 1)  return false;
        if (n <= 3)  return true;

        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n%2 == 0 || n%3 == 0) return false;

        for (int i=5; i*i<=n; i=i+6)
            if (n%i == 0 || n%(i+2) == 0)
                return false;

        return true;
    }

    int findNextPrime(int N) {
        // Base case
        if (N <= 1)
            return 2;

        int prime = N;
        bool found = false;

        // Loop continuously until isPrime returns
        // true for a number greater than n
        while (!found) {
            prime++;

            if (isPrime(prime))
                found = true;
        }

        return prime;
    }

    void insert_at(std::vector<std::unique_ptr<Node>>& table, size_t data) {
        auto hash = hashFunc(data, table.size());

        if(!table[hash]) {
            table[hash] = std::make_unique<Node>(Node{data});
            //table[hash].reset(new Node{data});
            //std::cout<<table[hash]->data<< " <-item\n";
        } else {
            auto& item = table[hash];
            //auto new_node = std::make_unique<Node>(Node{data, std::move(item)});
            table[hash] = std::make_unique<Node>(Node{data, std::move(item)});
            //std::cout<<table[hash]->data << ", " << table[hash]->next->data << " <-Collisions/Chained\n";
        }
    }

    bool contains_at(const std::vector<std::unique_ptr<Node>>& table, const size_t& data) const {
        auto hash = hashFunc(data, table.size());

        if(table[hash]->data == data) {
            //std::cout<<table[hash]->data<<"!\n";
            return true;
        } else {
            for(auto&& i = table[hash]->next; i != nullptr; i = std::move(i->next)) {
                //std::cout<<i->data<<", ";
                if(i->data == data) return true;
            }
        }
        return false;
    }

public:
    hashTable() = default;
    explicit hashTable(const std::vector<int>& init) {
        int newSize = (init.size()*1.7);
        newSize = findNextPrime(newSize);
        hashtable.resize(newSize);

        for(auto& e : init) {
            insert(e);
        }
    }

    void insert(size_t data) {
        insert_at(hashtable, data);
    }

    bool contains(size_t value) const{
        return contains_at(hashtable, value);
    }

};
#endif //DOA_LABB3_V1_HASHTABLE_H
