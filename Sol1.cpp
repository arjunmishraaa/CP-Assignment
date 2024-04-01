#include<iostream>
using namespace std;
#include<algorithm>
int min(int arr[],int size){
  int min=arr[0];
  for(int i=0;i<size;i++){
    if(arr[i]<min) min=arr[i];
  }
  return min;
}
int max(int arr[],int size){
  int max=arr[0];
  for(int i=0;i<size;i++){
    if(arr[i]>max) max=arr[i];
  }
  return max;
}
int sum(int arr[],int size){
  int sum=0;
  for(int i=0;i<size;i++){
    sum+=arr[i];
  }
  return sum;
}
float average(int arr[],float size){
  int sum=0;
  for(int i=0;i<size;i++){
    sum+=arr[i];
    sum=sum;
  }
  return sum/size;
}
int mode(int arr[], int size) {
    int maxFrequency = 0;
    int mode = -1;

    for (int i = 0; i < size; i++) {
        int frequency = 0;
        for (int j = 0; j < size; ++j) {
            if (arr[j] == arr[i]) {
                frequency++;
            }
        }
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            mode = arr[i];
        }
    }

    return mode;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i]; 
     cout<<"min,max,sum,average and mode after addition of"<<arr[i]<<"is"<<min(arr,i+1)<<","<<max(arr,i+1)<<","<<sum(arr,i+1)<<","<<average(arr,i+1)<<","<<mode(arr,i+1);
     cout<<endl;
  }
 

}