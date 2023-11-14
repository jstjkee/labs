#include <iostream>
#include <Windows.h>

using namespace std;

void heapify(float arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(float arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int M, N, res=1;
    cout << "Введите числа M и N (N > M): ";
    cin >> M >> N;
	float *X = new float[N];
	float SUM=0, SUMM=0;
    cout << "Вводите элементы: ";
    for (int k = 0; k < N; k++)
    {
        cin >> X[k];
    }
    printArray(X, N);
    heapSort(X, N);
    printArray(X, N);
    for (int i = 0; i <= M; i++)
    {
        SUMM += X[i];
    }
    SUMM = abs(SUMM);
    for (int k = 1; k <= N - M+1; k++)
    {
        for (int i = k; i<= k+ M; i++)
        {
            SUM += X[i];
        }
        SUM = abs(SUM);
        if (SUM < SUMM) { SUMM = SUM; res = k; }
        SUM = 0;
    }    
    cout <<"Индекс: "<<res+1<<"; Расстояние до 0: "<<SUMM ;
}

