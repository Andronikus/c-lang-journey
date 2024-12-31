#include<stdio.h>

int main(int argc, char* argv[]){

    char a_char = 'A';
    printf("a_char: %c\n", a_char);

    int an_int = 255;
    printf("an_int: %d\n", an_int);

    unsigned int an_unsigned_int = 256;
    printf("an_unsigned_int: %u\n", an_unsigned_int);

    long long a_long_long = 257; // 64bits 
    printf("a_long_long_int: %lld\n", a_long_long);

    unsigned long long a_long_long_unsigned_int = 258;
    printf("a_long_long_unsigned_int: %llu\n", a_long_long_unsigned_int);

    float a_float = 2.559;
    printf("a_float: %f\n", a_float);
    printf("a_float (2 decimal numbers) : %.2f\n", a_float);

    // format to print sizes should the the %lu (for example the size_t)
    int a_size_int = 0;
    printf("a size of an int: %lu\n", sizeof(a_size_int));

    // format with left padding
    int padd_1 = 34, padd_2 = 68;
    printf("%6d\n%6d\n", padd_1, padd_2);
    printf("%06d\n%06d\n", padd_1, padd_2); // fullfil with a char (0)

    // print in hexadecimal
    int as_hex = 16;
    printf("%d as hex: %#x\n", as_hex, as_hex);

    // print address
    int as_addr = 16;
    printf("address of %d (as_addr): %p", as_addr, &as_addr);

    return 0;
}