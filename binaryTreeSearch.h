//
// Created by Caaaarl on 2022-08-20.
//

#ifndef DOA_LABB3_V1_BINARYTREESEARCH_H
#define DOA_LABB3_V1_BINARYTREESEARCH_H
/*
class binarySearchTree {
    struct Node {
        size_t data{};
        std::unique_ptr<Node> left{}; // nullptr leaf
        std::unique_ptr<Node> right{}; // nullptr leaf
    };
    std::unique_ptr<Node> root = nullptr;

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

class binarySearchTree {
    struct Node {
        size_t data{};
        Node* left{};
        Node* right{};
    } *root{};

    Node* newNode(size_t data) {
        Node* tmp = new Node;
        tmp->data = data;
        tmp->left = nullptr;
        tmp->right = nullptr;

        return tmp;
    }

    void insert_at(Node* &node, size_t data) {
        Node* new_node = newNode(data);
        Node* x = root;
        Node* y = nullptr;

        while(x != nullptr) {
            y = x;
            if(data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        if(y==nullptr)
            y = new_node;
        else if(data < y->data)
            y->left = new_node;
        else
            y->right = new_node;
    }

    bool contains_at(const Node* node, size_t value) const {

        while (node != nullptr) {
            // pass right subtree as new tree
            if (value > node->data)
                node = node->right;

                // pass left subtree as new tree
            else if (value < node->data)
                node = node->left;
            else
                return true; // if the key is found return 1
        }
        return false;
    }

public:
    binarySearchTree() = default;
    explicit binarySearchTree(std::vector<int> init) {
        auto midPos = init.begin() + (init.size() / 2);
        insert(*midPos);
        init.erase(midPos);
        for(auto e : init) {
            insert(e);
        }
    }

    void insert(size_t value) {
        insert_at(root, value);
    }

    bool contains(size_t value) const{
        return contains_at(root, value);
    }
};





#endif //DOA_LABB3_V1_BINARYTREESEARCH_H
