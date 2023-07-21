#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int comparison = 0;

int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i], arr[j]);
        }
        comparison++;
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int Randomized_Partition(int arr[], int p, int r){
    int x = p + (rand() % (r - p + 1));
    swap(arr[x], arr[r]);
    return partition(arr, p, r);
}

void Randomized_QuickSort(int arr[], int p, int r){
    if(p < r){
        int q = Randomized_Partition(arr, p, r);
        Randomized_QuickSort(arr, p, q - 1);
        Randomized_QuickSort(arr, q + 1, r);
    }
}

int main(){
    srand(time(0));
    int n;
    cout << "Enter Size of Array : " << endl;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Randomized_QuickSort(arr, 0, n - 1);
    cout << "No of Comparisons : " << comparison << endl;

    return 0;
}