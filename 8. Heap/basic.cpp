#include <iostream>
using namespace std;

class heap{
    int size;
    int arr[100];
public:
    heap(){
        size = 0;
        arr[0] = -1;
    }

    void insert(int value){
        size = size +1;
        int index = size;
        arr[index] = value;

        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap (arr[parent], arr[index]);
                index = parent;

            }
            else{ 
                return ;
            }
        }

    }

    void deletefromHeap() {
        if(size == 0)
        {
            cout<<"nothing to delete";
            return;
        }
        //step 1 put last node at 1st
        arr[1] = arr[size];
        size--;

        // step 3 root node to the correct position
        int index = 1;
        int leftchild = 2*index;
        int rightchild = 2*index + 1;
        while(index < size)
        {
            if(leftchild < size && arr[index] < arr[leftchild])
            {
                swap(arr[index], arr[leftchild]);
                index = leftchild;
            }
            else if(rightchild < size && arr[index] < arr[rightchild])
            {
                swap(arr[index], arr[rightchild]);
                index = rightchild;
            }
            else {
                return ;
            }
        }
    }


    void print(){
        
        for(int i = 1; i<=size; i++ ){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest =i;
    int left = 2*i;
    int right = 2*i +1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        //step 1
        swap(arr[1], arr[size]);
        size--;
        // step 2 place root to correct position
        heapify(arr, size, 1);
    }
}



int main(){
    // heap h;
    // h.insert(20);
    // h.insert(40);
    // h.insert(30);
    // h.insert(60);
    // h.insert(50);
    // //h.insert(55);

    // h.print();

    // h.deletefromHeap();
    // h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }

    cout<<"printing heap";
    for(int i=1; i<=n; i++)    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr, n);
    cout<<"printing Sorted array";
    for(int i=1; i<=n; i++)    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
