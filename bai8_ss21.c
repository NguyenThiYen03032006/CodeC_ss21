#include <stdio.h>
#include<string.h>
struct SinhVien{
    int id;
    char name[50];
    int age;
};
struct SinhVien sv;
int main (void){
    FILE *fptr;
    int member;
    printf("Moi ban nhap so luong sinh vien: ");
    scanf("%d", &member);
    getchar();
    struct SinhVien sv[member];
    fptr= fopen(" students.txt", "w");
    for(int i=0; i<member; i++){
        printf("id sv thu %d: ", i+1);
        scanf("%d", &sv[i].id);
        getchar();
        printf("ten sv thu %d: ", i+1);
        fgets(sv[i].name, 50, stdin);
        sv[i].name[strcspn(sv[i].name, "\n")] = '\0';
        printf("tuoi sv thu %d: ", i+1);
        scanf("%d", &sv[i].age);
        getchar();
        fprintf(fptr, "%d %s %d\n", sv[i].id, sv[i].name, sv[i].age);
    }
    fclose(fptr);
    for(int i=0; i<member; i++){
            printf("%d %s %d\n", sv[i].id, sv[i].name, sv[i].age);
    }
    return 0;
}
