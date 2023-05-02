#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int maximum = root;  //Initializing largest value as the root
   int left = 2*root + 1;  //Left child node
   int right = 2*root + 2;  //Right child node

   //If left node is larger than the root
   if (left<n && arr[left]>arr[maximum]){
        maximum = left;
   }

   //If right node is larger than largest so far
   if (right<n && arr[right]>arr[maximum]){
        maximum = right;
   }

   //If largest is not the root
   if (maximum != root) {

        swap(arr[root], arr[maximum]);

        //Recursively heapify
        heapify(arr, n, maximum);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
   }

    //Extracting elements from the heap
    for (int i=n-1; i>=0; i--) {
        //Move current root to end
        swap(arr[0], arr[i]);

        //call max heapify
        heapify(arr, i, 0);
    }


   //extracting elements from heap one by one
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program

int main()
{
   int heap_arr[] = {9,-4,3,5,1,0,-6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
