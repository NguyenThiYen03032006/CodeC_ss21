#include <stdio.h>
int main(void){
    char arr[100];
    FILE *fptr1, *fptr6;
    fptr1= fopen("bt01.txt", "r");
    fptr6= fopen("bt06.txt", "w");
    while(fgets(arr,100,fptr1)!=NULL){
        fputs(arr,fptr6);
    }
    fclose(fptr1);
    fclose(fptr6);
    return 0;
}
