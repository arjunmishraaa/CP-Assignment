#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"Enter size of first array: ";
  cin>>n;
  int a[n];
  cout<<"Enter elements of first array: ";
  for(int i=0;i<n;i++){
    cin>>a[i];

  }
  int m;
  cout<<"Enter size of second array: ";
  cin>>m;
  int b[m];
  cout<<"Enter elements of second array: ";
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  int c[n+m];
  int k=0;
  for(int i=0,j=0;i<n||j<m;){
    if(i==n) c[k++]=b[j++];
    else if(j==m) c[k++]=a[i++];
    else if(a[i]<b[j]) c[k++]=a[i++];
    else c[k++]=b[j++];
  }
  for(int i=0;i<n+m;i++){
    cout<<c[i]<<" ";
  }
}