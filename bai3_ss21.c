#include<stdio.h>

int main(void){
    FILE *fptr;
    char arr[50];
    fptr= fopen("bt01.txt", "a");
    printf("Moi ban nhap chuoi muon them: ");
    fgets(arr, 50, stdin);
    fprintf(fptr,"%s", arr);
    fclose(fptr);
    printf("Ban da them chuoi thanh cong \n");
    return 0;
}
