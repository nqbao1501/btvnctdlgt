#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
		 left = NULL;
        right = NULL;
    }

};

struct BinaryTree
{
    Node* root ;
};
void duyetHauTo (Node* node)
{
    if (node != nullptr)
    {
        duyetHauTo(node->left);
        duyetHauTo(node->right);
        cout << node->data << " ";
    }
}
void duyetTrungTo (Node* node)
{
    if (node != nullptr)
    {
        duyetTrungTo(node->left);
        cout << node->data << " ";
        duyetTrungTo(node->right);
    }
}
void duyetTienTo (Node* node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        duyetTienTo(node->left);
        duyetTienTo(node->right);
    }
}


int main()
{
    BinaryTree tree;
    tree.root = new Node(100);
    tree.root->left = new Node(5);
    tree.root->left->left = new Node(7);
    tree.root->left->right = new Node(12);
    tree.root->left->right->left = new Node(1);
    tree.root->left->right->right = new Node(3);
    tree.root->left->right->left->left = new Node(14);
    tree.root->left->right->left->right = new Node(16);
    tree.root->right = new Node(31);
    tree.root->right->right = new Node(34);
    tree.root->right->right->right = new Node(301);

    duyetTienTo(tree.root);
    cout << "\n";
    duyetTrungTo(tree.root);
    cout << "\n";
    duyetHauTo(tree.root);
    cout << "\n";


    






    

}
