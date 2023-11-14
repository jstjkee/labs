#include <iostream>
#include <Windows.h>

using namespace std;

struct tree {

    int key;
    //int count;
    tree* left;
    tree* right;

};

tree* Tree = NULL;

tree** SetRoot(int N, tree** p)
{
    tree* temp = new(tree);
    temp->key = 0;
    if (*p == NULL)
    {
        *p = new(tree);
        (*p)->key = N;
        if ((*p)->key % 2 == 1) { (*p)->left = NULL; (*p)->right = NULL; }
        if (N % 2 == 0) { (*p)->left = NULL; (*p)->right = temp; }
    }
    return p;
}

/**/
bool ObhodStrat(tree** w)
{
    bool count = 0;
    if (*w != NULL)
    {
        ObhodStrat(&(**w).left);
        ObhodStrat(&(**w).right);
    }
    else {
        count = 1;
        return count;
    }
    return count;
}

tree SetTree(int N, tree** p)
{
    tree* temp = new(tree);
    temp->key = 0;
    tree* rsp = NULL;
    int rspn = 1;
    
        while (N != 1)
        {

            if (N % 2 == 0)
            {
                N /= 2;
                (*p)->left = new(tree);
                ((*p)->left)->key = N;
                ((*p)->left)->left = NULL;
                ((*p)->left)->right = temp;
                return SetTree(N, &(*p)->left);
            }
            if (N % 2 == 1)
            {
                int K = N - N / 2;
                (*p)->right = NULL;
                (*p)->right = new(tree);
                ((*p)->right)->key = K;
                if (K % 2 == 0)
                {
                    ((*p)->right)->left = NULL;
                    ((*p)->right)->right = temp;
                }
                else
                {
                    ((*p)->right)->left = NULL;
                    ((*p)->right)->right = NULL;
                }
                rsp = (*p)->right;
                rspn = K;

                N /= 2;
                (*p)->left = new(tree);
                ((*p)->left)->key = N;
                if (N % 2 == 0)
                {
                    ((*p)->left)->left = NULL;
                    ((*p)->left)->right = temp;
                }
                else
                {
                    ((*p)->left)->left = NULL;
                    ((*p)->left)->right = NULL;
                }

                return SetTree(N, &(*p)->left);
                return SetTree(K, &(*p)->right);
            }

        }
        while (ObhodStrat(p))
        {
        if (rsp != NULL) return SetTree(rspn, &rsp);
        }
    //delete temp;
}
/*
bool ch = 0;
    if (NULL == p) { ch = 1; return ch; }      //Если дерева нет, выходим

    Show(&(*p)->left); //Обошли левое поддерево
    Show(&(*p)->right); //Обошли правое поддерево
bool Show(tree *&p)
{
    bool ch = 0;
    if (p == NULL) { ch = 1; return ch; }

    Show(p->left); //Обошли левое поддерево
    Show(p->right); //Обошли правое поддерево
    return ch;
}


tree ObhodStrat2(tree** w)
{
    tree* rsp = *w;
    *w = (*w)->left;
    if (*w != NULL)
    {

        ObhodStrat2(&((**w).left));
        ObhodStrat2(&((**w).right));
    }
    else
    {

    }

}


tree SetLeftTree(int N, tree** p)
{
    while (N != 1)
    {
        if (N % 2 == 0)
        {
            N /= 2;
            (*p)->left = new(tree);
            ((*p)->left)->key = N;
            ((*p)->left)->left = NULL;
            return SetLeftTree(N, &(*p)->left);
        }
        else
        {
            N /= 2;
            (*p)->left = new(tree);
            ((*p)->left)->key = N;
            ((*p)->left)->left = NULL;
            ((*p)->left)->right = NULL;
            return SetLeftTree(N, &(*p)->left);
        }
    }
}
tree SetRightTree(int N, tree** p)
{
    while (N != 1)
    {
        if (N % 2 == 1)
        {
            N = N - N / 2;
            (*p)->right = NULL;
            (*p)->right = new(tree);
            ((*p)->right)->key = N;
            ((*p)->right)->left = NULL;
            ((*p)->right)->right = NULL;
            return SetRightTree(N, &(*p)->right);
        }
    }
}
tree SetFullTree(int N, tree** p)
{
    bool isit = 1;
    tree* i = *p;
    while (ObhodStrat(p))
    {
        if (i->right == NULL) isit = 1;

    }


    while (i->key != 1)
    {
        if (i->right == NULL)
        {
            i->right = new(tree);

        }
    }
}



void Add(int x, tree** p)
{
    int K = x;
    while (K != 1) {
        if (*p == nullptr)
        {
            *p = new(tree);
            (**p).key = x; (**p).count = 1;
            (**p).left = (**p).right = nullptr;
        }
        else if (K % 2 == 0)
        {
            K = x / 2;
            Add(K, &((**p).left));
        }
        else if (K % 2 == 1) {
            K = x / 2;
            Add(K, &((**p).left));
            K = x - x / 2;
            Add(K, &((**p).right));
            }
            else (**p).count = (**p).count + 1;
    }
}
void BuildTree(tree** Tree)
{
    int N, K;
    *Tree = nullptr;
    cout << "\nВводите ключи вершин дерева ";
    cin >> N;
    Add(N, Tree);
}
void postroenie(int N, int K, tree** koren)
{
    tree* rsp;
    int l, r;
    *koren = new(tree);
    rsp = *koren;
    (**koren).key = N; (**koren).count = 1;
    (**koren).left = NULL;
    (**koren).right = NULL;
}
void vivod(tree** w, int l)
{
    int i;
    if (*w != nullptr)
    {
        vivod(&((*w)->right), l + 1);
        for (i = 1; i <= l; i++) cout << " ";
        cout << (**w).key << endl;
        vivod(&((*w)->left), l + 1);
    }
}

*/

void print(tree* t, int u)
{
    if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
    else //Иначе
    {
        print(t->left, ++u);                   //С помощью рекурсивного посещаем левое поддерево
        for (int i = 0; i < u; ++i) if (t->key != 0) cout << "|";
        if (t->key != 0) cout << t->key << endl;            //И показываем элемент
        u--;
    }
    print(t->right, ++u);                       //С помощью рекурсии посещаем правое поддерево
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    tree* der = Tree;
    tree** pder = &der;
    int N;
    cout << "Введите корень дерева: ";
    cin >> N;
    // SetRoot(N, pder);
    SetTree(N, SetRoot(N, pder));
    //vivod(pder, 0);
   // SetTree(N, pder);
    print(der, 0);
}