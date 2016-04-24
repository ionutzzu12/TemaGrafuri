#include <iostream>
using namespace std;

struct node{
    float data;
    node *left;
    node *right;
};

class Tree{
    node *root;
public:

    Tree(){
        root=NULL;
    }

    ~Tree(){
        erase(root);
    }

    void insert(float n){

        if (!root){
            root=new node;
            root->data=n;
            root->left=root->right=NULL;
        }

        else {
            node **p=&root;
            while (*p){
                if ((*p)->data>n)
                    p=&((*p)->left);
                else p=&((*p)->right);
            }
            *p=new node;
            (*p)->data=n;
            (*p)->left=(*p)->right=NULL;
        }
    }

    bool find(float val){
        if (search(root,val)){
            cout<<"exista\n";
            return true;
        }
        cout<<"nu exista\n";
        return false;
    }

    static bool search(node *root, const float& val){
        if (!root) return false;
        if (root->data==val) return true;
        if (root->data>val) return search(root->left,val);
        return search(root->right,val);
    }

    static void erase(node *root){
        if (root){
            erase(root->left);
            erase(root->right);
            delete root;
        }
    }

    static void srd(node *root){
        if (!root) return;
        srd(root->left);
        cout<<root->data<<" ";
        srd(root->right);
    }

    static void rsd(node *root){
        if (!root) return;
        cout<<root->data<<" ";
        rsd(root->left);
        rsd(root->right);
    }

    void inorder(){
        srd(root);
        cout<<endl;
    }

    void preorder(){
        rsd(root);
        cout<<endl;
    }
};
