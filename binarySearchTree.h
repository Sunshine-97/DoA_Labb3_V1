//
// Created by Caaaarl on 2022-08-20.
//

#ifndef DOA_LABB3_V1_BINARYSEARCHTREE_H
#define DOA_LABB3_V1_BINARYSEARCHTREE_H

/*
class binarySearchTree {
    struct Node {
        size_t data{};
        std::unique_ptr<Node> left{}; // nullptr leaf
        std::unique_ptr<Node> right{}; // nullptr leaf
    };
    std::unique_ptr<Node> root{};

    void insert_at(std::unique_ptr<Node>& node, size_t data)
    {
        if (!node) {
            node = std::make_unique<Node>(Node{data});
            //node.reset(new Node{data});
        } else if (data < node->data) {
            insert_at(node->left, data);
        } else {
            insert_at(node->right, data);
        }
    }

    bool contains_at(const std::unique_ptr<Node>& node, size_t data) const
    {
        if (!node) {
            return false;
        } else if (data < node->data) {
            return contains_at(node->left, data);
        } else if (node->data < data) {
            return contains_at(node->right, data);
        } else {
            return true;
        }
    }

public:
    binarySearchTree() = default;
    explicit binarySearchTree(std::vector<int>& init)
    {
        auto midPos = init.begin() + (init.size() / 2);
        insert(*midPos);
        init.erase(midPos);
        for(auto e : init) {
            insert(e);
        }
    }
    ~binarySearchTree() = default;

    void insert(size_t data)
    {
        insert_at(root, data);
    }

    bool contains(int value) const
    {
        return contains_at(root, value);
    }

};
*/

//Time Complexity: O(log n)
//Worst: O(n)
class binarySearchTree {
    struct Node {
        size_t data{};
        Node* left{};
        Node* right{};
    };
    Node* root{};

    Node* newNode(size_t data) {
        Node* tmp = new Node;
        tmp->data = data;
        tmp->left = nullptr;
        tmp->right = nullptr;

        return tmp;
    }

    void insert_at(Node* &node, size_t data) {
/*
        auto new_node = new Node{data};
        if(!node) {
            node = new_node;
            return;
        }

        Node* prev = nullptr;
        auto tmp = node;
        while(tmp) {
            if(data < tmp->data) {
                prev = tmp;
                tmp = tmp->left;
            } else if(data > tmp->data) {
                prev = tmp;
                tmp = tmp->right;
            }
        }
        if(data < prev->data)
            prev->left = new_node;
        else
            prev->right = new_node;
*/

        if(!node) {
            node = new Node{data};
            return;
        } else if(data < node->data) {
            insert_at(node->left, data);
        } else {
            insert_at(node->right, data);
        }

    }

    bool contains_at(const Node* node, size_t value) const {

        if (!node) {
            return false;
        } else if (value < node->data) {
            return contains_at(node->left, value);
        } else if (node->data < value) {
            return contains_at(node->right, value);
        } else {
            return true;
        }
        /*
        while(node != nullptr) {
            if(value < node->data) {
                node = node->left;
            } else if(value > node->data) {
                node = node->right;
            } else
                return true;
        }
        return false;
         */
    }

public:
    binarySearchTree() = default;
    explicit binarySearchTree(std::vector<int>& init) {
        buildTree(init.begin(), init.end());
    }


    template<typename It>
    void buildTree(It first, It last) {
        while(last >= first) {
            auto mid = first + (std::distance(first, last) / 2);
            insert(*mid);

            if(mid != first) {
                buildTree(first, std::prev(mid));
                first = mid;
            } else if(mid != last) {
                buildTree(std::next(mid), last);
                last = mid;
            } else return;
        }
    }

    void insert(size_t value) {
        insert_at(root, value);
    }

    bool contains(size_t value) const{
        return contains_at(root, value);
    }
};


#endif //DOA_LABB3_V1_BINARYSEARCHTREE_H
