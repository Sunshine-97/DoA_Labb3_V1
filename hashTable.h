//
// Created by Caaaarl on 2022-08-20.
//

#ifndef DOA_LABB3_V1_HASHTABLE_H
#define DOA_LABB3_V1_HASHTABLE_H

class hashTable {
    struct Node {
        size_t data;
        std::unique_ptr<Node> next;
    };
    std::vector<std::unique_ptr<Node>> hashtable;

    size_t hashFunc(size_t data, size_t size) const{
        return (data % size);
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

    bool contains_at(const std::vector<std::unique_ptr<Node>>& table, size_t data) const {
        auto hash = hashFunc(data, table.size());
        auto Itr = std::make_unique<Node>(Node{table[hash]->data, std::move(table[hash]->next)});

        while(!Itr) {
            auto& tmp = Itr;
            if(Itr->data == data) {
                return true;
            }
            Itr = std::move(tmp->next);
        }
        return false;
    }

public:
    hashTable() = default;
    explicit hashTable(const std::vector<int>& init) {
        hashtable.resize(init.size()*2.6);
        for(auto e : init) {
            insert(e);
        }
    }

    ~hashTable() = default;

    void insert(size_t data) {
        insert_at(hashtable, data);
    }

    bool contains(size_t value) const{
        return contains_at(hashtable, value);
    }

};
#endif //DOA_LABB3_V1_HASHTABLE_H
