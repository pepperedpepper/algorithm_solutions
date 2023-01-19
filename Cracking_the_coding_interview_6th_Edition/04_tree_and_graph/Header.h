#include <vector>


struct Node
{
    int data;
    Node * left;
    Node * right;
    Node * parent;
};

class Tree
{
public:
    Node * root;
    
    Tree();
    void makeSampleBST(int num);
    Node * makeBST(std::vector<int>& arr, int start, int end, Node * parent = nullptr);
    void printTree(Node * root, std::string indent = "", bool last = true);
};
