#include <iostream>
#include <Windows.h>

using namespace std;

struct pari {
	char fir;
	char sec;
	pari* next;
	pari* prev;
};

struct result {
	char el;
	result* next;
	result* prev;
};

void postroenie (pari** nsp, pari** ksp)
{	pari* rsp;
	char a,b;
	*nsp = new(pari);
	rsp = *nsp;
	(**nsp).prev = (**nsp).next = nullptr;
	cout << "Вводите пары элементов: "; cin >> a>>b;
	while (a != '0' && b!='0')
	{
		rsp->next = new(pari); (rsp->next)->prev = rsp;
		rsp = rsp->next; rsp->next = nullptr; rsp->fir = a; rsp->sec = b;
		cin >> a>>b;
	}
	*ksp = rsp;
}
/*void postroenieres(result** nsp, result** ksp, pari* lsd)
{
	result* rsp;
	*nsp = new(result);
	rsp = *nsp;
	(**nsp).prev = (**nsp).next = nullptr;
	rsp->el = lsd->fir;
	rsp->next->el = lsd->sec;
	*ksp = rsp;
}*/
void postroenieres(result** nsp, result** ksp, pari* lsd)
{
	result* rsp=*nsp;
	char elem = lsd->fir;
	rsp->next = new(result);
	(*((*rsp).next)).prev = rsp;
	//(rsp->sled)->pred=rsp
	rsp = rsp->next;
	rsp->next = nullptr;
	rsp->el = elem;
	*ksp = rsp;
}
void VyvodForward(pari** head, pari** ksp)
// *nsp - указатель на начало списка,
// *ksp - указатель на конец списка.
{
	pari* rsp;
	rsp = (**head).next;
	cout << "Двунаправленный список содержит следующие пары элементов: "<<endl;
	while (rsp != nullptr)
	{
		cout << rsp->fir << " " << rsp->sec<<endl; rsp = rsp->next;
	}
	cout << endl;
}

void VyvodForwardRes(result** head, result** ksp)
// *nsp - указатель на начало списка,
// *ksp - указатель на конец списка.
{
	result* rsp;
	rsp = (**head).next;
	cout << "Последовательность: ";
	while (rsp != nullptr)
	{
		cout << rsp->el <<' '; rsp = rsp->next;
	}
	cout << endl;
}
void Deletee(pari** nsp, pari** ksp, pari* Res)
{
	if ((*Res).next != NULL)
	{
		(*(*Res).next).prev = (*Res).prev;
		(*(*Res).prev).next = (*Res).next; delete Res;
	}
	else
	{
		(*(*Res).prev).next = NULL; *ksp = (**ksp).prev;
		delete Res;
	}
}
pari* proverka(pari* head, pari* tail)
{
	pari* rsp = head;
	pari* rsp2 = rsp->next;
	pari* rspmaxx = head;
	while (rsp2 != NULL)
	{
		
		while (rsp2 != NULL)
		{
			if (rsp->fir == rsp2->fir)
			{
				if (rsp->sec == rsp2->sec) rspmaxx = rsp2;
			}
			rsp2=rsp2->next;
		}
		rsp=rsp->next;
		rsp2 = rsp->next;
	}
	return rspmaxx;
}
bool proverka2(pari* head, pari* tail)
{
	bool damn=1;
	pari* rsp = head;
	pari* rsp2 = rsp->next;
	pari* rspmaxx = head;
	while (rsp2 != NULL)
	{

		while (rsp2 != NULL)
		{
			if (rsp->fir == rsp2->fir) damn = 0;
			if (rsp->sec == rsp2->sec) damn = 0;
			rsp2 = rsp2->next;
		}
		rsp = rsp->next;
		rsp2 = rsp->next;
	}
	return damn;
}
bool proverka3(pari* head, pari* tail) 
{
	bool sadd = 0;
	pari* rsp = head;
	pari* rsp2 = head;
	pari* firstone = rsp;
	pari* lastone = firstone->next;
	pari* rspch = rsp->next;
	int count1 = 0,count2=0;
	while (rsp != NULL)
	{
		count1++; rsp = rsp->next;
	}
	while (rspch != NULL)
	{
		if (rspch->fir == lastone->sec) lastone = rspch;
		if (rspch->sec == firstone->fir) firstone = rspch;
		rspch=rspch->next;
	}
	rsp2 = firstone;
	while (rsp2 != lastone->next)
	{
		count2++;
		rsp2 = rsp2->next;
	}
	if (count1 == count2)sadd = 1;
	return sadd;
}
void InsBefore(int elem, result** nsp, result** ksp, result* Res)
{
	result* q;
	q = new (result);
	(*q).el = elem;
	(*q).next = (*(*Res).prev).next;
	(*q).prev = (*Res).prev;
	(*(*Res).prev).next = q; (*Res).prev = q;
}
void InsAfter(int elem, result** nsp, result** ksp, result* Res)
{
	result* q;
	q = new(result);
	q->el = elem;
	if (Res->next != nullptr)
	{
		q->next = Res->next;
		q->prev = (Res->next)->prev; (Res->next)->prev = q;
		Res->next = q;
	}
	else
	{
		q->next = nullptr; q->prev = Res; *ksp = q;
		Res->next = q;
	}
}
void OCHISTKA(pari** phead)
{
	struct pari* q, * q1;		//рабочие указатели
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
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	pari* tail;
	pari* phead = new(pari);
	pari* rsp = phead;
	phead->prev = nullptr;
	(*phead).next = nullptr;
	bool damn = 1;
	while (damn)
	{
		postroenie(&phead, &tail);
		pari* head = phead->next;
		VyvodForward(&phead, &tail);
		//cout << proverka(head, tail, chek);
		while (proverka(head, tail) != head)
		{
			Deletee(&head, &tail, proverka(head, tail));
		}
		if (!proverka2(head, tail)) {
			cout << "Ошибка введенных данных: пары с одинаковыми предшествующими или последующими элементами." << endl;
			cout << "Хотите ввести список заново?" << endl << "1. Да" << endl << "2. Нет" << endl;
			int c; cin >> c;
			while (c != 1 && c != 2)
			{
				cout << "Введите один из предложенных вариантов: ";
				cin >> c;
			}
			if (c == 2) damn = 0;
			OCHISTKA(&phead);
		}
		
		if (damn)
		{
		
			
			if (proverka3(head, tail))
			{
				result* tail;
				result* headd = new(result);
				result* rspres = headd;
				headd->prev = nullptr;
				(*headd).next = nullptr;
				postroenieres(&headd,&tail,head);
				
				 pari* rsp=head->next;
				while (rsp != NULL)
				{
					while (rspres != NULL)
					{
						if (rsp->sec == rspres->el) InsBefore(rsp->fir, &headd, &tail, rspres);
						if (rsp->fir == rspres->el) InsAfter(rsp->sec, &headd, &tail, rspres);
						rspres = rspres->next;
					}
					rsp = rsp->next;
				}
				VyvodForwardRes(&headd, &tail);
			}

		}

		damn = 0;
	}



	return 0;
}
