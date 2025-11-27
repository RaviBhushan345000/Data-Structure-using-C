#include<stdio.h> 
#include <stdbool.h> 

bool search(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int arr[10] = { 5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    int key; 
    printf("Enter the element to search for: "); 
    scanf("%d",&key); 

    bool found = search(arr, 10, key); 

    if(found) {
        printf("Key is present\n"); 
    } else {
        printf("Key is absent\n"); 
    }

    return 0; 
}