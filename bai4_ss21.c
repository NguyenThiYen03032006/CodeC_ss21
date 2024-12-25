#include <stdio.h>
int main(void){
    FILE *fptr;
    fptr=fopen("bt01.txt","r");
    char arr[100];
    fgets(arr,100,fptr);
    printf("Dong dau tien cua file la: %s",arr);
    fclose(fptr);
    return 0;
}
