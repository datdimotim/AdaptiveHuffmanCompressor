#ifndef CODETREE
#define CODETREE
namespace code_tree {

    struct Node{
        char symbol;
        long weight;
        Node* parent;
        Node* left;
        Node* right;
        Node(char symbol, long weight, Node* parent, Node* left, Node* right){
            this->symbol=symbol;
            this->weight=weight;
            this->parent=parent;
            this->left=left;
            this->right=right;
        }
    };

    bool isLeft(Node* node);
    Node* iterate(Node* current);
    void incrementWeight(Node* n); // call on leaf only!
    void destroy(Node* node);

    char* encode(char* in);
    char* decode(char* in);
}

#endif // CODETREE

