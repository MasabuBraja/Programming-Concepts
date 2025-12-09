#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    char nama[50];
    char nim[9];
}mahasiswa;

typedef struct node{
    mahasiswa data;
    struct node *next;
}node;

node *newNode(char nama[], char nim[]){
    node *new =malloc (sizeof(node));
    node *head =new;
    strcpy(new->data.nama, nama);
    strcpy(new->data.nim, nim);
    new->next=NULL;
    return new;
}

void addAtLast(node *head, char nama[], char nim[]){
    node *new = newNode(nama, nim);
    node *temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
}

void printList(node *head){
    node *temp = head;
    int no=1;
    while(temp!=NULL){
        printf("%d. %s ,%s\n",no, temp->data.nama, temp->data.nim);
        temp=temp->next;
        no++;
    }
}

node *deleteFirst(node *head){
    node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    return head;
}

void deleteLast(node *head){
    node *del = head;
    node *ptr = NULL;
    while(del->next!=NULL){
        ptr=del;
        del=del->next;
    }
    ptr->next=NULL;
    free(del);
    del=NULL;
}

node *addAtBeginning(node *head, char nama[], char nim[]){
    node *temp = newNode(nama, nim);
    temp->next=head;
    head=temp;
    return head;
}

void addAtPosition(node* head, int position, char nama[], char nim[]){
    node *temp = newNode(nama, nim);
    node *ptr = head;
    for(int i=1; i<position-1; i++){
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
}

void freeList(node *head){
    node *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

// void *deleteAtPosition(node* head, int position){
//     node *ptr =head;
//     node *del =NULL;

//     for(int i=1; i<position-1; i++){
//         ptr=ptr->next;
//     }
//     ptr->next=del->next;
//     free(del);
//     del=NULL;
// }




int main(){

    node *head = newNode("Mus'ab Farhad Baraja", "L0125144");
    addAtLast(head, "Kumbang Bintang", "L0125150");
    addAtLast(head, "Fulan Gunawan", "L0529110");
    addAtLast(head, "Budi Sanusi", "L0930170");
    addAtLast(head, "Siti Jumaedi", "R0399049");
    printf("====Print Pertama setelah tambah data===\n");
    printList(head);

    printf("\n==== setelah hapus Data pertama & terakhir ===\n");
    head = deleteFirst(head);
    deleteLast(head);
    printList(head);

    printf("\n==== setelah tambah Data 1,3,terakhir ===\n");
    head = addAtBeginning(head,"Sumantono", "ABCDEFG");
    addAtPosition(head,3,"Indra Jegel", "J0298098");
    addAtLast(head,"Ahmad Luthfi", "P0987654");
    printList(head);

    // printf("\n=== setelah hapus posisi 3===\n");
    // deleteAtPosition(head,3);
    // printList(head);

    freeList(head);
    return 0;
}

// i don' know but it works
//if it works , dont touch it

// WM