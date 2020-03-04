#include <stdio.h>
#include <stdlib.h>
 
void convertToBinary(int a[], int n) {
    int count = 0;
 
    do {
        count++;
        a[count] = n%2;
        n = n/2;
    } while (n != 0);
   
    reverseArray(a,count);
    for (int i=0; i<count; i++){
        printf("%d",a[i]);
    }
}

void reverseArray(int a[], int n){
    int t;
    for (int i=0; i<= (n)/2; i++){
        t = a[i];
        a[i] = a[n - i];
        a[n - i] = t;
    }
}

int main(){
    int decNum;
    int arr[1000];
    
    do {
        do {
            decNum = 0;
            system("clear");
            printf("please enter a positive number: ");
            scanf("%d", &decNum);
            fflush(stdin);
        } while (decNum < 0);
        
        printf("binary Number: ");
        convertToBinary(arr,decNum);
        
        printf("\nPress enter to continue, ESC to exit: ");
        getchar();
        fflush(stdin);
    } while (getchar() != 27);
    return 0;
}
 
