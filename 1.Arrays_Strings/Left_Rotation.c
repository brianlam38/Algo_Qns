// Given an array of  integers and a number, , perform  left rotations on the array.
// Print the updated array as a single line of space-separated integers.

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// O(n) runtime | O(n) space

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    
    // Copy array to store original values
    int *arr = malloc(sizeof(int)*n);
    for (int j = 0; j < n; j++) {
        arr[j] = a[j];
    }
    
    // Shift orig pos into new pos, in one go.
    for (int i = 0; i < n; i++) {
        // Change to shift right
        int shiftRight = (n - k) % n;
        // Calculate new index after K-shifts
        int newPos = (i + shiftRight) % n;
        a[newPos] = arr[i];            
    }
    
    for (int m = 0; m < n; m++) {
        printf("%d ",a[m]);
    }
    
    return 0;
}
