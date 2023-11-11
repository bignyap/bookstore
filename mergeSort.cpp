#include<iostream>

using namespace std;


void printArray(int array[], int size){ 
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void merge(int array[], int l, int m, int r) {
   
   // size of temp arrays
   int n1 = m - l + 1;
   int n2 = r - m;

   // Temp arrays
   int a[n1];
   int b[n2];

   // copy the left sub array
    for (int i = 0; i < n1; i++){
        a[i] = array[l + i];
    }

    // copy the right sub array
    for (int i = 0; i < n2; i++){
        b[i] = array[m + 1 + i];
    }

    // merge the 2 sub arrays
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (a[i] < b[j]){
            array[k] = a[i];
            i++; k++;
        }else{
            array[k] = b[j];
            j++; k++;
        }
    }

    while (i < n1){
        array[k] = a[i];
        k++; i++;
    }

    while (j < n2){
        array[k] = b[j];
        j++; k++;
    }
}

void mergeSort(int array[], int l, int r) {
   if(l < r) {
      int m = l + (r - l) / 2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m + 1, r);
      merge(array, l, m, r);
   }
}

int main(){
    int array[] = {10, 43, 15, 67, 23, 49, 76};
    mergeSort(array, 0, 6);
    printArray(array, 7);
}