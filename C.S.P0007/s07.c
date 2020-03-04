#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
 
int isNum(char ch){
    return ch >= '0' && ch <= '9';
}
 
int isAlpha(char ch){  
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
int isSpace(char ch){
    return ch == ' ';
}
 
int exitSpecialChar(char* s){
    for(int i = 0; i < strlen(s); i++){
        if (!isNum(s[i]) && !isAlpha(s[i]) && !isSpace(s[i])) return 1;
    }  
    return 0;
}
 
void lTrim(char *s) {
    int i = 0;
    while (s[i] == ' ') i++;
    strcpy(s, s + i);  
}
 
void rTrim(char *s) {
    int i = strlen(s);
    while (s[i - 1] == ' ') i--;
    s[i] = '\0';
}
 
void trim(char *s) {
    lTrim(s);
    rTrim(s);
   
    int originSize = strlen(s);
    for(int i = 0; i < originSize; i++){
        int j = i;
        if (isSpace(s[i])){
            while(isSpace(s[i + 1])) i++;
            strcpy(s + j + 1, s + i + 1);          
        }      
    }          
}
 
int main() {
    do {
        char str[100];
        __fpurge(stdin);
        system("clear");
        
        do {
            printf("Please enter a string(Do not contain special characters): ");
            
            scanf("%[^\n]", str);
            getchar();
            __fpurge(stdin);
        }while(exitSpecialChar(str));      
       
        printf("The string after removing: ");
       
        trim(str);
        puts(str);     
       
        printf("Enter to continue. ESC to exit: \n");
        __fpurge(stdin);
    } while(getchar() != 27);
   
    return 0;
}