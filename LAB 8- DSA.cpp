#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)  //n is the heap size

{
    //cout<<"heapify is running"<<endl;
    int left = root*2 +1;
    int right = root*2 +2;
    int largest= root;

    if (arr[left]> arr[root] && left<n){
        largest=left;
    }


    if (arr[right]> arr[largest] && right<n){
        largest= right;


    }

    if (largest!=root){
        int a = arr[root];
        arr[root]=arr[largest];
        arr[largest]=a;
        heapify(arr, n, largest);


    }
}
void buildheap(int arr[], int n){

   // cout<<"Biuld heap is running"<<endl;

    int indexNum= n/2 -1; //we don;t have to heapify from index n/2 to n, as they are leaf nodes

    for (int j=indexNum; j>=0; j--){
            heapify(arr,n,j);

    }
}

// implementing heap sort
void heapSort(int arr[], int n)

{  // cout<<"Heap sort is running"<<endl;
    buildheap(arr,n);

   // build heap
   for (int i=0; i<n; i++){
        swap(arr[0],arr[n-1-i]);


        if(i!=n-1){
              heapify(arr, n-1-i,  0);
        }
   }
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

   cout<<"Enter the array size : "<<endl;
   int n;
   cin>>n;
   cout<<"Enter the elements of the array : "<<endl;
   int heap_arr[n];
   for(int i=0; i<n; i++){
        cin>>heap_arr[i];

   }



 //  int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

  heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
