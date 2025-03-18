#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Defines a user-defined struct
struct C
{
    int member; // "int" is the type specifier
    char name[9];
} obj, *pObj = &obj;

struct book {
    char title[5];
    char author[10];
};

// Assigns values to struct
struct C example = { 1 };

// Stores the memory address of the struct in a pointer variable
struct C *strptr = &example;

// 
struct packed_struct {
    unsigned int f1:1;
    unsigned int type:4;
    unsigned int my_int:9;
} pack;

struct packed_struct *packed = &pack;


// Array initialization and assigned pointer
int arr[] = { 1, 2, 3 };
int *ptr = arr;

// Memory Allocation
int *mPtr;


int main() {
    strcpy(obj.name, "12345678");
    printf("%d", strptr -> member);
    printf("\n");
    printf("%d", example.member);
    printf("\n");
    printf("%s", obj.name);

    struct book b;
    printf("\n");
    strcpy(b.title, "titl");
    printf("%s", b.title);
    printf("\n");
    strcpy(obj.name, b.title);
    printf("%s", obj.name);
    printf("\n");

    pack.my_int = 1;
    printf("%d", pack.my_int);

    printf("\n");
    printf("%d", packed -> my_int);
    printf("\n");
    packed -> my_int = 2;
    printf("%d", packed -> my_int);
    pack.my_int = 3;
    printf("%d", pack.my_int);
    printf("\n");
    for(int i = 0; i < 2; i++){
        printf("arr[%d]", *ptr);
        ptr++;
        printf("\n");
    }
    mPtr = ( int * ) malloc (10);
    int a = 1234567890;

    *mPtr = a;

    printf("%d", *mPtr);
    free(mPtr);
}