#include <bits/stdc++.h>
using namespace std;

//quickselect is a selection algorithm to find the k-th smallest element in an unordered list.
//Algorithm is similar to quick sort.
//Difference is instead of recurring for both sides (after finding pivot), it recurs only for the part that contains k-th smallest elment
//if index of partitioned element is more than k, we recur for left part
//if index is same as k, we have found k-th smallest element and return
//if index is less than k, we recur for right.
//tc : O(n) <tc< O(n^2)

//Partition process of quicksort
//considering last element as pivot and moves all smaller elements to left of it and greater to right

int partition(vector<int>&v, int l, int r){
    int x = v[r], i=l;
    for(int j=l; j<=r-1; j++){
        if(v[j]<=x){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
        }
    }

    int temp = v[i];
    v[i] = v[r];
    v[r] = temp;

    return i;
}

int kthSmallest(vector<int>&v, int k, int l, int r){
    //if k is smaller than number of elements in array
    if(k>0 && k<=r-l+1){
        // partition the array around last element and get position of pivot element in sorted array
        int index = partition(v, l, r);

        //if position is same as k
        if(index-l==k-1)
            return v[index];

        //if position is more, recur for left subarray
        if(index-l>k-1)
            return kthSmallest(v, k, l, index-1);

        //if position is more, recur for right subarray

        return kthSmallest(v, k-index+l-1, index+1, r);

    }

    return INT_MAX;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>v(n);

    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<k<<"th smallest element is "<<kthSmallest(v, k, 0, n-1)<<endl;

    return 0;
}