#include<stdio.h>

/**
 * A void* is a generic pointer type, meaning it can hold the address of any data type (e.g., int, char, float, or even user-defined types like struct).
 * It is a feature that enables type-agnostic programming by allowing pointers to refer to data of unknown or flexible types.
 * 
 * Key features:
 *   No Dereferencing Without Casting: 
 *      - A void* pointer cannot be directly dereferenced because the compiler does not know the size or type of the data it points to.
 *      - Before dereferencing or performing pointer arithmetic, a void* must be explicitly cast to the appropriate pointer type.
 *   Memory-Agnostic:
 *      It provides a way to work with raw memory, independent of the underlying data type.
 */

void printBytes(void *arr, int nBytes){
    // printBytes can be reused to print any type of structures.
    for(int i=0; i < nBytes; i++){
        printf("%02x ", ((char*)arr)[i]); // need to cast the void* to char* before the dereference
    }
    printf("\n");
}


int main(int argc, char* argv[]){
    int intValues[] = {8, 16, 32, 64};
    long long lonValues[] = {8, 16, 32, 64};

    printBytes(intValues, 4 * sizeof(int));
    printBytes(lonValues, 4 * sizeof(long long));

    return 0;
}
