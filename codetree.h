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

    void updateWeights(Node* node);
    void resolve(Node* problem);
    bool isLeft(Node* node);
    Node* iterateNextOnThisLevel(Node* node);
    Node* iterateNext(Node* node);
    void destroy(Node* node);

    void updateWeights(Node* node){
        if(node->parent==nullptr)return;
        node->parent->weight=node->parent->left->weight+node->parent->right->weight;
        updateWeights(node->parent);
    }

    void resolve(Node* problem){
        Node* next=iterateNext(problem);
        while((next=iterateNext(next))->weight<problem->weight);

        Node* parentNext=next->parent;
        Node* parentProblem=problem->parent;
        if(isLeft(next)) parentNext->left=problem;
            else parentNext->right=problem;
        if(isLeft(problem))parentProblem->left=next;
            else parentProblem->right=next;
        problem->parent=parentNext;
        next->parent=parentProblem;
        updateWeights(problem);
        updateWeights(next);
    }

    bool isLeft(Node* node){
        return node==node->parent->left;
    }

    Node* iterateNextOnThisLevel(Node* node){
        if(node->parent==nullptr)return nullptr;
        if(isLeft(node))return node->parent->right; // правый сосед - следующий для левого узла
        node=iterateNext(node->parent);             // узел того же уровня, но доступный через предков
        if(node==nullptr)return nullptr;            // уровень закончен, дошли до корня
        return node->left;
    }

    Node* iterateNext(Node* node){
        Node* nextOnLevel=iterateNextOnThisLevel(node);
        if(nextOnLevel!=nullptr)return nextOnLevel;
        // переход на уровень выше
        int i=0;
        while(node->parent!=nullptr){
            node=node->parent;
            i++;
        }
        if(i==0)return nullptr;    // корень - самый последний элемент
        for(;i>1;i--)node=node->left;
        return node;
    }

    // сверху - влево
    // слева - вправо
    // справа- вверх
    Node* iterateNextOnThisLevelNew(Node* current){
        if(current==nullptr)return nullptr;
        int level=0;
        Node* prev=current;

        current=current->parent;
        if(current==nullptr)return nullptr;
        level--;

        while(level!=0){
            if(prev==current->parent){ // сверху
                if(current->left!=nullptr){
                    prev=current;
                    current=current->left;
                    level++;
                }
                else{
                    if(current->parent==nullptr)return nullptr;
                    prev=current;
                    current=current->parent;
                    level--;
                }
                continue;
            }

            if(current->left==prev){ // слева
                level++;
                prev=current;
                current=current->right;
                continue;
            }

            if(current->right==prev){ // справа
                if(current->parent==nullptr)return nullptr;
                level--;
                prev=current;
                current=current->parent;
                continue;
            }
        }
        return current;
    }

    void destroy(Node* node){
        if(node==nullptr)return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

#endif // CODETREE

