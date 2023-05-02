#include <iostream>
#include <random>
#include <chrono>
using namespace std;

using namespace std::chrono;

void BuiltArray(int A[], int n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    for(int i = 0; i < n; i++){
        A[i] = dis(gen);
    }
}

void swapping(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition (int Array[], int p, int r)
{
    int x = Array[r];
    int i = p - 1;

    for (int j = p; j <= r-1; j++)
    {
        if (Array[j] <= x)
        {
            i++;
            swapping (&Array[i], &Array[j]);
        }
    }
    swapping (&Array[i+1], &Array[r]);

    return (i+1);
}

void quickSort(int Array[], int p, int r){

    if (p < r)
    {
        int q = partition(Array, p,r);

        quickSort(Array, p, q-1);
        quickSort(Array, q+1, r);
    }
}
int main()
{
    int arrayLengths[] = {5000, 10000, 15000, 20000, 25000};

    for(int arrayLength : arrayLengths){
        int list[arrayLength]; //initiating the array
        BuiltArray(list, arrayLength); //inserting random variables

        auto start = high_resolution_clock::now();

        quickSort(list,0,arrayLength-1);

        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start);

        cout << "Time taken for "
             << arrayLength
             << " inputs: "
             << duration.count()
             << " microseconds"
             << endl;
    }

    return 0;
}
