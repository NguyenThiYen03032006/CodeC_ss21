#include<stdio.h>
int main(void){
    FILE *fptr;
    char temp;
    fptr = fopen("bt01.txt","r");
    temp = fgetc(fptr);
    printf("Ky tu dau tien trong file la: %c \n", temp);
    return 0;
}
