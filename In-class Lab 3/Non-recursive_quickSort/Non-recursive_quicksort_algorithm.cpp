#include <bits/stdc++.h>
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

//Swapping function
void swapping(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//Partitioning function
int partition(int Array[], int l, int h)
{
    int x = Array[h];
    int i = (l-1);

    for (int j = l; j <= h - 1; j++) {
        if (Array[j] <= x) {

            i++;
            swapping(&Array[i], &Array[j]);
        }
    }
    swapping(&Array[i+1], &Array[h]);

    return (i+1);
}


void iterativeQuickSort(int Array[], int l, int h)
{
    //Operation using stacks.
    int stack[h-l+1];

    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {

        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        int p = partition(Array, l, h);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main()
{
    int arrayLengths[] = {5000, 10000, 15000, 20000, 25000};

    for(int arrayLength : arrayLengths){
        int list[arrayLength]; //initiating the array
        BuiltArray(list, arrayLength); //inserting random variables

        auto start = high_resolution_clock::now();

        iterativeQuickSort(list, 0, arrayLength - 1);

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
