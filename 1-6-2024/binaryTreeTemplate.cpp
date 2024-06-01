#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, *right;
};
class BinaryTree
{
    Node* root;
public:
    void InitBTree()
    {
        root = nullptr;
    }
    Node* getRoot()
    {
        return root;
    }
    void setRootValue(int x)
    {
        if (root ==  nullptr) {
            root = new Node;
            root->data = x;
            root->left = nullptr;
            root->right = nullptr;
        } else {
            root->data = x;
    }
    }
    Node* FindParent(Node* startNode, Node* targetNode)
    {
        if (!startNode || !targetNode) {
            return nullptr;
        }
        if (startNode->left == targetNode || startNode->right == targetNode)
        {
            return startNode;
        }
        Node* leftParent = FindParent(startNode->left, targetNode);
        if (leftParent) {
            return leftParent;
        }
        return FindParent(startNode->right, targetNode);
    }
    Node* FindNode(int data, Node* startNode)
    {
        if (!startNode) {
            return nullptr;
        }
        if (startNode->data == data) {
            return startNode;
        }
        Node* leftResult = FindNode(data, startNode->left);
        if (leftResult) {
            return leftResult;
        }
        return FindNode(data, startNode->right);
    }
    void InsertParent(int data, Node* p)
    {
        if (p == nullptr)
        {
            root = new Node;
            root->data = data;
            root->left = root->right = nullptr;           
        }
        else
        {
            Node* oldParent = FindParent(root,p);
            Node* newParent = new Node;
            newParent->data = data;
            newParent->left = nullptr;
            newParent->right = p;
            if (oldParent->left == p) oldParent->left = newParent;
            else oldParent->right = newParent;
        }
    }
    void InsertLeftChild(int data, Node* p)
    {
        if (p->left == nullptr)
        {
            p->left = new Node;
            p->left->data = data;
            p->left->left = p->left->right = nullptr;
        }
        else{
            p->left->data = data;
        }
    }
    void InsertRightChild(int data, Node* p)
    {
        Node* temp = new Node;
        p->right = temp;
        temp->data = data;
        temp->left = temp->right = nullptr;
    }
    void DeleteCurrentNode(Node* node)
    {
        Node* parent = FindParent(root,node);
        if (node->left == nullptr && node->right == nullptr)
        {
            if (parent->left == node) parent->left = nullptr;
            else parent->right = nullptr;
            delete node;
        }
        if (node->left == nullptr && node->right != nullptr)
        {
            if (parent->left == node) parent->left = node->right;
            else parent->right = node->right;
            delete node;
        }
        else if (node->right == nullptr && node->left  != nullptr)
        {
            if (parent->left == node) parent->left = node->left;
            else parent->right = node->left;
            delete node;
        }
    }
    void DeleteLeftChild(Node *parent)
    {
        Node* node = new Node;
        node = parent->left;
        if (node->left == nullptr && node->right == nullptr)
        {
            parent->left = nullptr;
            delete node;
        }
        if (node->left == nullptr && node->right != nullptr)
        {
            if (parent->left == node) parent->left = node->right;
            else parent->right = node->right;
            delete node;
        }
        else if (node->right == nullptr && node->left  != nullptr)
        {
            if (parent->left == node) parent->left = node->left;
            else parent->right = node->left;
            delete node;

    }
    }
    void PreOrder(Node* node)
    {
        if (node == nullptr) return;
        cout << node->data << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
};

int main()
{
    BinaryTree Tree;
    Tree.InitBTree();

    Tree.setRootValue(1);
    Node* root = Tree.getRoot();
    Tree.InsertLeftChild(2, root);
    Tree.InsertRightChild(3,root);
    Node* temp = Tree.FindNode(3,root);
    Tree.InsertLeftChild(4,temp);
    Tree.InsertRightChild(5,temp);
    Node* temp2 = Tree.FindNode(4,root);
    Tree.DeleteCurrentNode(temp2);
    Tree.PreOrder(root);



}

