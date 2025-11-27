#include<stdio.h>
int main(){
    int arr[] = {10,20,30,40,50};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i< n; i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
    int brr[n];
    for(int i=0; i< n; i++){
        brr[i]=arr[n-1-i];
        printf(" %d ",brr[i]);
    }

    return 0;
}