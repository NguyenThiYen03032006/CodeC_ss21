#include <stdio.h>

int main(void){
    FILE *fptr;
    int line=0;
    char arr[50];
    printf("Moi ban nhap so dong: ");
    scanf("%d", &line);
    getchar();
    fptr = fopen("bt05.txt","w");
    for(int i=0; i<line; i++){
        printf("Moi ban nhap vao dong thu %d: ", i+1);
        fgets(arr, 50, stdin);
        fprintf(fptr,"%s",arr);
    }
    fclose(fptr);
    fptr = fopen("bt05.txt","r");
    while(fgets(arr,50,fptr)!=NULL){
            printf("%s", arr);
    }

    fclose(fptr);
    return 0;
}
