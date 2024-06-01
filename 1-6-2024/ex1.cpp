#include <iostream>
#include <string>
using namespace std;

// Kieu cua cac nut tren cay (chua thong tin ve mot sinh vien).

struct Node
{
    int sbd; // So bao danh
    string hoTen; // Ho ten sinh vien
    Node * left; // Con tro toi nut con trai
    Node * right; // Con tro toi nut con phai
// Ham tao.
    Node(int s, string h, Node * l, Node * r) 
    {
        hoTen = h;
        sbd = s;
        left = l;
        right = r;
    }
};
// Lop cay nhi phan tim kiem.
class BSTree
{
private:
    Node * root; // Con tro toi nut goc cua cay
public:
    void makeEmpty(Node * & t) {
        if (t == NULL)       // Cay da rong roi thi thoat ra
			return;

		makeEmpty(t->left);  // Xoa rong cay con trai
		makeEmpty(t->right); // Xoa rong cay con phai
		delete t;			 // Xoa nut goc
		t = NULL;            // Khong con nut goc de tro den, phai cho t thanh NULL
    }
    // Chen mot sinh vien moi vao cay (viet theo kieu de quy).
    void insert(int sbd, string hoTen, Node *& t) {
        if (t == NULL){ // Cay dang rong thi nut moi se thanh nut goc 
			t = new Node(sbd,hoTen, NULL, NULL);
            return;
        }
		else if (sbd < t->sbd){
			insert(sbd,hoTen,t->left);
        }
		else if (sbd > t->sbd){
			insert(sbd,hoTen,t->right);
        }
		else{
            ;
        }

    }
    
    // Ham tao (ban dau cay rong).
    BSTree() { root = NULL;}

    // Ham huy (xoa het cac nut tren cay).
    ~BSTree() {makeEmpty();}

    // Kiem tra cay co rong hay khong.
    bool isEmpty() {return (root == NULL);}

    // Xoa het cac nut tren cay.
    void makeEmpty() {makeEmpty(root);}

    // Chen mot sinh vien moi vao cay.
    void insert(int sbd, string hoTen) {
        insert(sbd, hoTen, root);
    }

    // Tim sinh vien theo so bao danh.
    Node * search(int sbd) {return search(sbd,root);};

   
    // Tim sinh vien theo so bao danh (viet theo kieu de quy).
    Node * search(int sbd, Node * t)
    {
        if (t == NULL)
			return NULL;
		if (sbd < t->sbd)
			return search(sbd, t->left);
		else if (sbd > t->sbd)
			return search(sbd, t->right);
		else
			return t;

    }




};

int main()
{
    BSTree bst;
    // Chen mot so sinh vien moi vao cay.
    bst.insert(5, "Tuan");
    bst.insert(6, "Lan");
    bst.insert(3, "Cong");
    bst.insert(8, "Huong");
    bst.insert(7, "Binh");
    bst.insert(4, "Hai");
    bst.insert(2, "Son");
    // Tim hai sinh vien co so bao danh 4 va 9.
    Node * n1 = bst.search(4);
    Node * n2 = bst.search(9);
    // In ket qua tim kiem
    if (n1 != NULL)
        cout << "Sinh vien voi SBD=4 la " << n1->hoTen << endl;
    if (n2 == NULL)
        cout << "Khong tim thay sinh vien voi SBD=9" << endl;
    // Lam rong cay.
    bst.makeEmpty();
    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;
    return 0;
}
