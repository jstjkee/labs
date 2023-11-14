#include <iostream>
#include <set>
#include <Windows.h>
//#include <algorithm>

using namespace std;
template <class Os, class K>
Os& operator<<(Os& os, const set<K>& v) {
	bool o{};
	for (const auto& e : v)
		os << (o ? ", " : (o = 1, " ")) << e;
	return os << " }\n";
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set<int> A;
	set<int> B;
	set<int> Res;	

	cout << "Вводите элементы первого множества: ";
	int el; cin >> el;
	while (el!=0)
	{
		Res.insert(el);
		cin >> el;
	}
	cout << "Вводите элементы второго множества: ";
	int el2; cin >> el2;
	while (el2 != 0)
	{
		Res.insert(el2);
		cin >> el2;
	}
	
	cout <<"Объединенное множество: "<<endl<< Res;
	/*for(auto it=Res.begin();it !=Res.end(); )
	{
		for (auto its = Res.begin(); its != Res.end(); )
		{
			if (it == its) {
				it = Res.erase(its);
			}
			else ++its;
		}
		++it;
	}*/

	/*//A.merge(B)
	for (auto it = A.begin(); it != A.end(); )
	{
		//int el;
		Res.emplace(it);
		++it;
	}
	for (auto its = B.begin(); its != B.end(); )
	{
		Res.emplace(its);
		++its;
	}*/
	//cout << Res;
}

