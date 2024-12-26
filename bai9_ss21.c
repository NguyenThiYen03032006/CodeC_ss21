#include <stdio.h>
#include <string.h>
struct Book{
    int id;
    char name[50];
    char author[50];
    float price;
    char category[15];
};

void addBook(struct Book *book1, int *member);
int saveBook(struct Book *book1, int member);
int readBook(struct Book *book2, int member);
void showBook(struct Book *book2, int member);
int main(void){
    struct Book book1[50];
    struct Book book2[50];
    int choose=0;
    int member=0;
    printf("MENU \n 1. Nhap so luong va thong tin sach \n 2. Luu thong tin sach vao file \n 3. Lay thong tin sach tu file \n 4. Hien thi thong tin sach \n 5. Thoat \n ");
    do{
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
                addBook( book1, &member);
                break;
            case 2:
                saveBook( book1, member);
                break;
            case 3:
                readBook(book2, member);
                break;
            case 4:
                showBook(book2, member);
                break;
    
            case 5:
                printf("Ban da chon thoat \n");
                break;
                
            default:
                printf("Lua chon cua ban khong co trong MENU \n");
                break;
        }
    }while(choose!=5);
    return 0;
}

void addBook(struct Book *book1, int *member){
    printf("Moi ban nhap so luong sach: ");
    scanf("%d", member);
    getchar();
    printf("Moi ban nhap lan luot thong tin cua %d cuon sach: \n", *member);
    for(int i=0; i< *member; i++){
        printf("Moi ban nhap id cuon sach thu %d: ", i+1);
        scanf("%d", &book1[i].id);
        getchar();
        printf("Moi ban nhap ten cuon sach thu %d: ", i+1);
        fgets(book1[i].name, 50, stdin);
        book1[i].name[strcspn(book1[i].name, "\n")] = '\0';
        printf("Moi ban nhap ten tac gia cuon sach thu %d: ", i+1);
        fgets(book1[i].author, 50, stdin);
        book1[i].author[strcspn(book1[i].author, "\n")] = '\0';
        printf("Moi ban nhap gia cuon sach thu %d: ", i+1);
        scanf("%f", &book1[i].price);
        getchar();
        printf("Moi ban nhap the loai cuon sach thu %d: ", i+1);
        fgets(book1[i].category, 50, stdin);
        book1[i].category[strcspn(book1[i].category, "\n")] = '\0';
    }
}

void showBook(struct Book *book2, int member){
    
    for(int i=0; i<member; i++){
        printf("%d \t %s \t %s \t %f \t %s \n", book2[i].id,book2[i].name,book2[i].author,book2[i].price,book2[i].category );
    }
}

int saveBook(struct Book *book1, int member){
    FILE *file;
    int count=0;
    file = fopen("book1.bin","wb");
    if(file ==NULL){
        printf("Loi mo file \n");
        return 1;
    }
    for(int i=-0; i< member; i++){
        count+=fwrite(&book1[i], sizeof(struct Book),1, file);
    }
    if(count != member){
        printf("Loi ghi du lieu vao file \n");
    }else{
        printf("Ghi du lieu thanh cong \n");
    }
    fclose(file);
    return 0;
}
int readBook(struct Book *book2, int member){
    FILE *file1;
    int count=0;
    file1 = fopen("book1.bin","rb");
    if(file1 ==NULL){
        printf("Loi mo file \n");
        return 1;
    }
    for(int i=0; i<member; i++){
       count += fread(&book2[i], sizeof(struct Book),1, file1);
    }
    if(count != member){
        printf("Loi ghi du lieu vao file \n");
    }else{
        printf("Lay giu lieu thanh cong \n");
    }
    fclose(file1);
    return 0;
}
