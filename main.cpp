#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Function to draw the array in terminal
void drawArray(const vector<int>& arr, int a = -1, int b = -1) {
    system("cls"); // clear extra terminal screen
    for (int i = 0; i < arr.size(); i++) {
        if (i == a || i == b){
            cout<<">"; // Indices Comparision
        }
        else {
            cout<<" ";
        }

        for (int j = 0; j < arr[i]; j++) {
            cout<<"#";\
        }
        cout<<" ("<<arr[i]<<") \n";
    }
    Sleep(1200); // delay the steps in sorting
}

// Bubble Sort Algorithm
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            drawArray(arr, j, j + 1);
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    drawArray(arr);
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            drawArray(arr, minIdx, j);
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    drawArray(arr);
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            drawArray(arr, j, j + 1);
            j--;
        }
        arr[j + 1] = key;
    }
    drawArray(arr);
}

// Quick Sort Helper
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        drawArray(arr, j, high);
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort Helper
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        drawArray(arr, l + i, m + 1 + j);
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Main
int main(){
    srand(time(0));

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 20 + 1; // values between 1 and 20
    }

    cout << "Choose sorting algorithm:"<<endl;
    cout << "1. Bubble Sort"<<endl;
    cout << "2. Selection Sort"<<endl;
    cout << "3. Insertion Sort"<<endl;
    cout << "4. Quick Sort"<<endl;
    cout << "5. Merge Sort"<<endl;
    cout << "Enter choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: bubbleSort(arr); break;
        case 2: selectionSort(arr); break;
        case 3: insertionSort(arr); break;
        case 4: quickSort(arr, 0, n - 1); drawArray(arr); break;
        case 5: mergeSort(arr, 0, n - 1); drawArray(arr); break;
        default: cout << "Invalid choice!"<<endl; 
        return 0;
    }
    
    cout<<endl;
    cout<<"Sorting complete!"<<endl;
    return 0;
}
