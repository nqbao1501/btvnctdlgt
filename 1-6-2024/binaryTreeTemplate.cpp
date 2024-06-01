#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    int data;
    Node<T>* left, *right;
};
template <typename T>
class BinaryTree
{
    Node<T>* root;
public:
    void InitBTree()
    {
        root = nullptr;
    }
    Node<T>* getRoot()
    {
        return root;
    }
    void setRootValue(T x)
    {
        if (root ==  nullptr) {
            root = new Node<T>;
            root->data = x;
            root->left = nullptr;
            root->right = nullptr;
        } else {
            root->data = x;
    }
    }
    Node<T>* FindParent(Node<T>* startNode, Node<T>* targetNode)
    {
        if (!startNode || !targetNode) {
            return nullptr;
        }
        if (startNode->left == targetNode || startNode->right == targetNode)
        {
            return startNode;
        }
        Node<T>* leftParent = FindParent(startNode->left, targetNode);
        if (leftParent) {
            return leftParent;
        }
        return FindParent(startNode->right, targetNode);
    }
    Node<T>* FindNode(int data,Node<T>* startNode)
    {
        if (!startNode) {
            return nullptr;
        }
        if (startNode->data == data) {
            return startNode;
        }
        Node<T>* leftResult = FindNode(data, startNode->left);
        if (leftResult) {
            return leftResult;
        }
        return FindNode(data, startNode->right);
    }
    void InsertParent(T data, Node<T>* p)
    {
        if (p == nullptr)
        {
            root = new Node<T>;
            root->data = data;
            root->left = root->right = nullptr;           
        }
        else
        {
            Node<T>* oldParent = FindParent(root,p);
            Node<T>* newParent = new Node<T>;
            newParent->data = data;
            newParent->left = nullptr;
            newParent->right = p;
            if (oldParent->left == p) oldParent->left = newParent;
            else oldParent->right = newParent;
        }
    }
    void InsertLeftChild(T data, Node<T>* p)
    {
        if (p->left == nullptr)
        {
            p->left = new Node<T>;
            p->left->data = data;
            p->left->left = p->left->right = nullptr;
        }
        else{
            p->left->data = data;
        }
    }
    void InsertRightChild(int data, Node<T>* p)
    {
        Node<T>* temp = new Node<T>;
        p->right = temp;
        temp->data = data;
        temp->left = temp->right = nullptr;
    }
    void DeleteCurrentNode(Node<T>* node)
    {
        Node<T>* parent = FindParent(root,node);
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
    void DeleteLeftChild(Node<T>* *parent)
    {
        Node<T>* node = new Node<T>;
        node = parent->left;
        if (node->left == nullptr && node->right == nullptr)
        {
            parent->left = nullptr;
            delete node;
        }
        if (node->left == nullptr && node->right != nullptr)
        {
            parent->left = node->right;
            delete node;
        }
        else if (node->right == nullptr && node->left  != nullptr)
        {
            parent->left = node->left;
            delete node;
        }
    }
    void DeleteRightChild(Node<T>* parent)
    {
        Node<T> node = new Node<T>;
        node = parent->left;
        if (node->left == nullptr && node->right == nullptr)
        {
            parent->right = nullptr;
            delete node;
        }
        if (node->left == nullptr && node->right != nullptr)
        {
            parent->right= node->right;
            delete node;
        }
        else if (node->right == nullptr && node->left  != nullptr)
        {
            parent->right = node->left;
            delete node;
        }
    }
    void PreOrder(Node<T>* node)
    {
        if (node == nullptr) return;
        cout << node->data << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
    int GetSize(Node<T>* node) {
    if (node == nullptr) {
        return 0; // Empty tree has size 0
    }
    return 1 + GetSize(node->left) + GetSize(node->right);
}
};


int main() {
  BinaryTree<int> Tree; // Specify data type as int for this example
  Tree.InitBTree();

  Tree.setRootValue(1);
  Node<int>* root = Tree.getRoot();
  Tree.InsertLeftChild(2, root);
  Tree.InsertRightChild(3, root);
  Node<int>* temp = Tree.FindNode(3, root);
  Tree.InsertLeftChild(4, temp);
  Tree.InsertRightChild(5, temp);
  Node<int>* temp2 = Tree.FindNode(4, root);
  Tree.DeleteCurrentNode(temp2); // Modify for template usage (see below)
  Tree.PreOrder(root);
  cout << "\n" << Tree.GetSize(root);

  return 0;
}

