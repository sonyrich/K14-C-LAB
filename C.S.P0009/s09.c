#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int inputNum() {
    int n;
    system("clear");
    do {
        n = 0;
        system("clear");
        n = checkInputNumElement();
        __fpurge(stdin);
    } while (n < 1);
    return n;
}

void inputArr(float* arr, int n) {
    int i;
    float flag;

    printf("Input elements:\n");
    for (i = 0; i < n; i++) {
        do {
            printf("\t Element %d = ", i + 1);
            flag = scanf("%f", &arr[i]);
            __fpurge(stdin);
        } while (flag != 1);
    }
}

float lookUpSmallest(float* arr, int n, int* smallBoard, int* countSmall) {
    int i;
    float min = arr[0];
    smallBoard[*countSmall] = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            *countSmall = 1;
            smallBoard[*countSmall] = i+1;
        }
        else if (arr[i] == min) {
            *countSmall += 1;
            smallBoard[*countSmall] = i+1;
        }
    }
    return min;
}
void printResullt(int* smallBoard, int countSmall, float min) {
    int i;
    printf("The smallest element: %.2f", min);
    printf(" - It's position: ");
    for (i = 1; i <= countSmall; i++) {
        printf("%d ", smallBoard[i]);
    }
}

int checkInputNumElement() {
    float n;
    int tmp;
    do{
        printf("Enter a number of element n = ");
        __fpurge(stdin);
    }while(scanf("%f", &n) == 0 || n - (tmp = n) != 0 || getchar() != '\n');
    return n;
}

int main(int argc, char** argv) {
    int n = inputNum();
    float arr[100];
    float min;
    int smallBoard[100];
    int countSmall = 1;
    inputArr(arr, n);
    
    
    min = lookUpSmallest(arr, n, smallBoard, &countSmall);
    printResullt(smallBoard, countSmall, min);
    return (EXIT_SUCCESS);
}