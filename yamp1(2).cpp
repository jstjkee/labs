#include <iostream>

using namespace std;

struct list
{
	int val;
	list* next;
};

void POSTROENIE(list** phead)
{
	list* t;
	int el;
	//создаем  звено
	t = *phead; t->next = NULL;
	cout << "Введите элементы звеньев списка: ";
	cin >> el;
	while (el != 0)
	{
		t->next = new(list); t = t->next;
		t->val = el; t->next = NULL;
		cin >> el;
	}
}
void OCHISTKA(list** phead)
{
	struct list* q, * q1;		//рабочие указатели
	q = *phead;
	q1 = q->next;
	while (q1 != NULL)
	{
		q = q1;
		q1 = q1->next;
		delete q;
	}
	delete* phead;
}
list* search(list* head)
{
	
	list* t = head->next;
	list* PUTIN = t;
	list* Zhirinovskiy=t->next;
	while (Zhirinovskiy != NULL)
	{								
		if (Zhirinovskiy->val < PUTIN->val) PUTIN = t;
		
		t = Zhirinovskiy;
		Zhirinovskiy = Zhirinovskiy->next;
		
	}
	Zhirinovskiy = PUTIN->next;
	if (&head < &Zhirinovskiy) {
		cout << "Наименьший эл-т расположен на первом месте"; return head;
	}
	else {
		cout << PUTIN->val;
		return PUTIN;
	}
}
void elementvstavka(list* t)
{
	
	int el;
	
	cout << endl<< "Введите вставляемый элемент: ";
	cin >> el;
	t->val = el;
	
}

list* sortir(list* head)
{
	
	list* ez = head;
	list* PUTIN = ez;
	list* Zhirinovskiy = PUTIN->next;
	while (Zhirinovskiy != NULL)
	{
		if (Zhirinovskiy->val > PUTIN->val) PUTIN = Zhirinovskiy;
		cout << PUTIN->val << " khuy";
 		Zhirinovskiy = Zhirinovskiy->next;

	}
	if (ez->val < PUTIN->val) { /*int temp; temp = ez->val; ez->val = PUTIN->val; PUTIN->val = temp;*/ swap(ez->val, PUTIN->val); }
	ez = ez->next;
	while (ez != NULL) {
		return sortir(ez);
	}
	

}

void Show(list* head)
{
	list* tmp = head->next;
	cout << endl << "элементы списка: " << endl;
	while (tmp != NULL)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	list* head, * prev, * phead;
	phead = new (list);
	int el;
	POSTROENIE(&phead);
	//search(phead);
	Show(phead);
	elementvstavka(search(phead));
	Show(phead);
	sortir(phead);
	Show(phead);

	OCHISTKA(&phead);
}
