#include <bits/stdc++.h>
using namespace std;

typedef struct findd
{
    int i,j;
}findd;

findd search(int m, int n, int arr[][10], int ele)
{
    int i = 0, j = n-1;
    findd f;
    f.i=-1;
    f.j=-1;
    while(i>=0 && i<m && j>=0 && j<n)
    {
         if(arr[i][j]==ele)
         {
             f.i= i;
             f.j = j;
             break;
         }

         else if(arr[i][j]>ele)
         j--;

         else 
         i++;
    }
    return f;
}

int main()
{
    int a[10][10],m,n,i,j,ele;
    cin>>m>>n;
    cout<<"inputs: "<<endl;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++){
        cin>>a[i][j];
        }
    }
    cout<<"ele: ";
    cin>>ele;
    findd f = search(m,n,a,ele);
    cout<<"found at "<<f.i<<" "<<f.j<<endl;

}