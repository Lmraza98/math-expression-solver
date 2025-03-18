#include <stdio.h>
#include <stdlib.h>
struct dynamic_array {
    int* numbers;
    int count;
};
int main(int argc, char *argv[]){
    char* input = argv[1];
    printf("input: %s\n", input);
    struct dynamic_array arr = { NULL, 0};
    int capacity = 5;

    arr.numbers = (int*)malloc(capacity * sizeof(int));
    while(*input != '\0'){
        int i = *input - '0';
        printf("%d\n", i);
        if(arr.count == capacity){
            capacity *= 2; 
            arr.numbers = (int*)malloc(capacity * sizeof(int)); 
        }
        arr.numbers[arr.count] = i; 
        arr.count++;
        input++;
    }

    for(int i = 0; i < arr.count; i++){
        printf("%d\n", arr.numbers[i]);
    }
};