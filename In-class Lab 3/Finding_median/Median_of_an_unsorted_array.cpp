//Finding running median.

#include <bits/stdc++.h>

using namespace std;

int binarySearch(float Array[], float value, int low, int high)
{
    if (low >= high) {
        return (value > Array[low]) ? (low+1) : low;
    }

    int mid = (low + high)/2;

    if (value == Array[mid]){
        return mid+1;
    }

    if (value > Array[mid]){
        return binarySearch(Array, value, mid+1, high);
    }

    return binarySearch(Array, value, low, mid-1);
}

// Function to print median of stream of integers
void findMedian(float Array[], int n)
{
    int i, j, position;
    float number;
    int count = 1;

    cout << "Median after reading 1"<< " element is " << Array[0] << "\n";

    for (i = 1; i < n; i++) {

        float median;
        j = i-1;
        number = Array[i];

        // find position to insert current element in sorted part of array
        position = binarySearch(Array, number, 0, j);

        // move elements to right to create space to insert the current element
        while (j >= position) {
            Array[j+1] = Array[j];
            j--;
        }

        Array[j+1] = number;

        // increment the count.
        count++;


        if (count%2 != 0) {
            median = Array[count/2];
        }
        else {
            median = (Array[(count/2)-1] + Array[count/2])
                     / 2;
        }

        cout << "Median after reading " << i+1 << " elements is " << median << "\n";
    }
}

int main()
{
    float Array[] = {8, 5, 4, 7, 12, 5, 3, 4, 9};

    int n = sizeof(Array)/sizeof(Array[0]);

    cout << "The array to be sorted is: ";
    for (int i=0; i<n; i++){
        cout << Array[i] << " ";
    }

    cout << "\n";
    findMedian(Array, n);

    return 0;
}
