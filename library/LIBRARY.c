#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int i;
struct book {
    int book_id , price ;
    char book_name[100] , author_name[100] ;
    struct book *next ;
}*head;
void view(){
    if(head==NULL){
        printf("There are no books \n");
    }else{
        struct book * temp1 = head;
        do{
            printf("BOOK ID = %d \t",temp1->book_id);
            printf("BOOK NAME = %s \t",temp1->book_name);
            printf("BOOK AUTHOR NAME = %s \t",temp1->author_name);
            printf("BOOK PRICE = %d \n \n",temp1->price);
            temp1=temp1->next;
        }while(temp1!=NULL);
    }
}
void search(){
    struct book * temp;
    temp = head ;
    char hii[10];
    printf("Enter name \t");
    scanf(" %s",&hii);
    while(temp!=NULL){
        if(strcmp(temp->book_name,hii)==0){
            printf("BOOK ID = %d \t",temp->book_id);
            printf("BOOK NAME = %s \t",temp->book_name);
            printf("BOOK AUTHOR NAME = %s \t",temp->author_name);
            printf("BOOK PRICE = %d \n \n",temp->price);
            break;
        }else{
        temp=temp->next;
        }
    }
}
void add(){
    struct book * temp ;
    if(head==NULL){
        head=(struct book*)malloc(sizeof(struct book));
        printf("%d",head);
        printf("Enter the boook details : \n");
        printf("Enter book id\t");
        scanf("%d",&head->book_id);
        printf("Enter book name\t");
        scanf("%s",&head->book_name);
        printf("Enter book author name\t");
        scanf("%s",&head->author_name);
        printf("Enter book price\t");
        scanf("%d",&head->price);
        printf("\n \nBook details : %d %s %s %d \n \n",head->book_id ,head->book_name ,head->author_name , head->price );
        head->next=NULL;
    }else{
        struct book *lastnode= head;
        while(lastnode->next!=NULL){
            lastnode=lastnode->next;
        }
        struct book* temp = (struct book*)malloc(sizeof(struct book));
        printf("Enter the boook detail : \n");
        printf("Enter book id\t");
        scanf("%d",&temp->book_id);
        printf("Enter book name\t");
        scanf("%s",&temp->book_name);
        printf("Enter book author name\t");
        scanf("%s",&temp->author_name);
        printf("Enter book price\t");
        scanf("%d",&temp->price);
        printf("\n \n Book details : %d %s %s %d \n \n",temp->book_id ,temp->book_name ,temp->author_name ,temp->price );
        lastnode->next=temp;
        lastnode->next->next=NULL;
    }
}
void delete(){
    printf("Enter the book name you want to delete:\t");
    char name[20];
    struct book * temp = head;
    struct book * current ;
    scanf("%s",&name);
    if(head==NULL){
        printf("There are no books to delete \n \n");
    }else{
        while(temp->next!=NULL){
            int data=strcmp(temp->next->book_name,name);
            if(data==0){
                break;
            }else{
                temp=temp->next;
            }
        }
        if(temp==NULL){
            printf("NO SUCH BOOK EXISTS");
        }else{
            temp->next=temp->next->next;
            printf("Book %s deleted successfully \n \n",name);
        }
    }
}
void main(){
    printf("*****BOOK ORGANISATION***** \n");
    printf("*****  MENU  ***** \n");
    printf("\t 1.VIEW BOOKS \n");
    printf("\t 2.SEARCH BOOK\n");
    printf("\t 3.ADD BOOK   \n");
    printf("\t 4.DELETE BOOK\n");
    printf("\t 5.EXIT       \n");
    scanf("%d", &i);
    while(i!=5){
        switch(i){
            case 1 :
            view();
            main();
            break;
            case 2 :
            search();
            main();
            break;
            case 3: 
            add();
            main();
            break;
            case 4 : 
            delete();
            main();
            break;
            default :
            printf("Please enter a proper choice \n \n");
            main();
        }
    }
}