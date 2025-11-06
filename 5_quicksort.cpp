#include<bits/stdc++.h>
using namespace std;

// ------------------ DETERMINISTIC ------------------
int piv_sort(vector<int> &arr,int l,int h){
    int pivot = arr[l];
    int i = l, j = h;
    while(i < j){
        while(arr[i] <= pivot && i <= h-1) i++;
        while(arr[j] > pivot && j >= l+1) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void qs(vector<int> &arr,int l,int h){
    if(l < h){
        int piv = piv_sort(arr, l, h);
        qs(arr, l, piv-1);
        qs(arr, piv+1, h);
    }
}

// ------------------ RANDOMIZED ------------------
int piv_sort_rand(vector<int> &arr,int l,int h){
    int randomIndex = l + rand() % (h - l + 1);
    swap(arr[l], arr[randomIndex]);   // choose random pivot

    int pivot = arr[l];
    int i = l, j = h;
    while(i < j){
        while(arr[i] <= pivot && i <= h-1) i++;
        while(arr[j] > pivot && j >= l+1) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void qs_rand(vector<int> &arr,int l,int h){
    if(l < h){
        int piv = piv_sort_rand(arr, l, h);
        qs_rand(arr, l, piv-1);
        qs_rand(arr, piv+1, h);
    }
}

// ------------------ MAIN ------------------
int main(){
    srand(time(NULL));

    vector<int> arr = {6,4,2,8,2,0,1};
    vector<int> arr_rand = arr;
    int n = arr.size();

    // deterministic
    qs(arr, 0, n-1);

    // randomized
    qs_rand(arr_rand, 0, n-1);

    cout << "Deterministic Quick Sort:\n";
    for(int it : arr) cout << it << " ";
    cout << "\n";

    cout << "Randomized Quick Sort:\n";
    for(int it : arr_rand) cout << it << " ";
    cout << "\n";

    return 0;
}

