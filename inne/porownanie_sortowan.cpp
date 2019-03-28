//PORÓWNANIE SORTOWAŃ
//_________________________

#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;

const int MAX = 100000;

void ArrayRandomize(int t[])
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        t[i] = rand();
    }
}

void ArrayShow(int t[])
{
    cout << "---" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
    cout << "---" << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Sortowanie przez wstawianie
void InsertionSort(int t[])
{
    for (int i = 1; i < MAX; i++)
    {
        int x = t[i]; // x - wartość porównywana
        int j = i - 1;
        while (t[j] > x and j >= 0)
        {
            t[j + 1] = t[j];
            j--;
        }
        t[j + 1] = x;
    }
}

//Sortowanie przez wybieranie
void SelectionSort(int t[])
{
    for (int i = 0; i < MAX; i++)
    {
        int k = i;
        for (int j = i + 1; j < MAX; j++)
        {
            if (t[j] < t[k])
                k = j;
        }
        swap(t[i], t[k]);
    }
}

//Sortowanie bąbelkowe
void BubbleSort(int t[])
{
    for (int n = MAX; n > 0; n--)
    {
        for (int i = 0; i < n; i++)
        {
            if (t[i] > t[i + 1])
            {
                swap(t[i], t[i + 1]);
            }
        }
    }
}

void Merge(int tab[], int p, int mid, int k){
    int left=p, right=mid+1, i=0;
    int *tmp = new int[k-p+1];
    while(left<=mid and right <= k){
        tmp[i++]=(tab[left] <= tab[right] ? tab[left++] : tab[right++]);
    }
    while(left<=mid){
        tmp[i++]=tab[left++];
    }
    while(right<=k){
        tmp[i++]=tab[right++];
    }
    for(int j=0; j<k-p+1; j++){
        tab[p+j]=tmp[j];
    }
}

void MergeSortInt(int tab[], int p, int k){
    if(p!=k){
        int q=(p+k)/2;
        MergeSortInt(tab, p, q);
        MergeSortInt(tab, q+1, k);
        Merge(tab, p, q, k);
    }
}
void MergeSort(int tab[]){
    MergeSortInt(tab, 0, MAX-1);
}

// KOPIEC ang. HEAP
//------------------------------------------
int parent(int i)
{
    return i / 2;
}
int left(int i)
{
    return 2 * i;
}
int right(int i)
{
    return 2 * i + 1;
}
// Porządkowanie kopca (jeden z elementów jest za mały)
void heapify(int t[], int i)
{
    int l = left(i);
    int r = right(i);
    int max = i;
    if (l <= t[0] and t[l] > t[max])
        max = l;
    if (r <= t[0] and t[r] > t[max])
        max = r;
    if (max != i){
        swap(t[i],t[max]);
        heapify(t, max);
    }
}
//Budowa kopca
void build(int t[]){
    for(int i=t[0]/2; i>0; i--){
        heapify(t, i);
    }
}

//Heapsort

void HeapSort(int t[]){
    build(t);
    for(int i=t[0]; i>0; i--){
        swap(t[i], t[1]);
        t[0]--;
        heapify(t, 1);
    }
}

int main()
    {
    int* t = new int[MAX];
    ArrayRandomize(t);
        
 //   ArrayShow(t);
    clock_t begin = clock();
    SelectionSort(t);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "---" << endl;
    cout << "Czas insertion: " <<  elapsed_secs<< endl;
 //   ArrayShow(t);

    ArrayRandomize(t);
 //   ArrayShow(t);
    begin = clock();
    SelectionSort(t);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "---" << endl;
    cout << "Czas selection: " << elapsed_secs<< endl;
 //   ArrayShow(t);

    ArrayRandomize(t);
 //   ArrayShow(t);
    begin = clock();
    SelectionSort(t);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "---" << endl;
    cout << "Czas bubble: " << elapsed_secs<< endl;

    //   ArrayShow(t);
    begin = clock();
    MergeSort(t);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "---" << endl;
    cout << "Czas merge: " <<  elapsed_secs<< endl;
   // ArrayShow(t);

    ArrayRandomize(t);
    t[0]=MAX;
 //   ArrayShow(t);
    begin = clock();
    HeapSort(t);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "---" << endl;
    cout << "Czas heapsort: " << elapsed_secs<< endl;
    
 //   ArrayShow(t);

        cout << endl;
        system("pause");
        return 0;
    }
