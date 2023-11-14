#include <iostream>
#include <string>
#include <string.h>
#include <Windows.h>

using namespace std;

struct Tree
{
    int Key;
    int Count;
    Tree* left;
    Tree* right;
    Tree* parent;
};
Tree** Search(bool f,int x, Tree** p, Tree* batya)
{
    if (*p == nullptr)
    {
        *p = new(Tree); (**p).Key = x; (**p).Count = 1;
        (**p).left = (**p).right = nullptr;
        (*p)->parent = (batya);
        //(**p).left->parent = (**p).right->parent = *p;
    }
    else if (x < (**p).Key) Search(0, x, &((**p).left), (*p));
    else if (x > (**p).Key) Search(0, x, &((**p).right), (*p));
    else (**p).Count = (**p).Count + 1;
    if (f) return p;
}
Tree* BuildTree(Tree** tree)
{
    int el;    
    *tree = nullptr; //(*tree)->parent = &(**tree);
    cout << "Вводите ключи вершин дерева...\n";
    cin >> el;
    bool tt = 1;
    while (el != 0)
    {
        if (tt)
        {
            *tree = new(Tree); (**tree).Key = el; (**tree).Count = 1;
            (**tree).left = (**tree).right = nullptr;
            (*tree)->parent = (*tree);
            tt = 0;
        }
        else
        Search(0, el, tree, (*tree)->parent); cin >> el;
    }
    return *tree;
}
void print(Tree* t, int u)
{
    if (t == nullptr) return;
    else
    {
        print(t->right, ++u);
        for (int i = 0; i < u; ++i)  cout << "|";
        cout << t->Key << endl;
        u--;
    }
    print(t->left, ++u);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tree* tmp;
    
    Tree** P2;
    Tree* S;
    Tree** q = &S;
    Tree** P = &S;
    tmp = BuildTree(q);
    print(*q, 0);
    int k;
    cout << "Введите вершину, которую хотите добавить: "; cin >> k;
    if (tmp == nullptr) 
    {
        *P = nullptr;
        *P = new(Tree); (**P).Key = k; (**P).Count = 1;
        (**P).left = (**P).right = nullptr;
        (*P)->parent = *P;
        //P = Search(1, k, &tmp, (tmp)->parent); cout << P << " - адрес листа"<<endl; print(*P, 0);
        cout << P << " - адрес листа" << endl; print(*P, 0);
    }
    else
    {
        if (k < (tmp)->Key) Search(0, k, &(tmp)->left, (tmp)->left->parent);
        else if (k > (tmp)->Key) Search(0, k, &(tmp)->right, (tmp)->right->parent);
        P2 = &tmp;
        cout << P2 <<" - адрес корня со значением " << (*P2)->Key<<endl;
        print(tmp, 0);
    }

}