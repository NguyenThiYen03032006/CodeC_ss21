#include<stdio.h>
int main(void){
FILE *fptr ;
fptr = fopen("bt01.txt", "w");
char str[20];
printf("Moi ban nhap ki tu ");
fgets(str,20,stdin);
fprintf(fptr, "%s",str);
fclose(fptr);


return 0;

}
