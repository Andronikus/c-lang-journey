#include<stdio.h>
#include<string.h>

void compare_result(void *s1, void *s2, int size_bytes){
    /**
     * The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.
     */
    int cmp_res = memcmp(s1, s2, size_bytes);
    printf("comparation between s1 and s2: %d\n", cmp_res);
}

int main(int argc, char *argv[]){
    int cmp1_arr[] = {1, 2};
    int nbr_elems = sizeof(cmp1_arr) / sizeof(int);

    /**
     *  arrays have the same size and the values (byte by byte) are equal -> memcmp return 0
     * 
     *  cmp1_arr: 01 00 00 00 02 00 00 00 (4 bytes per element)
     *  cmp2_arr: 01 00 00 00 02 00 00 00 (4 bytes per element)
     * 
     *  difference between each byte is 0.
     */ 
    int cmp2_arr[] = {1, 2};
    compare_result(cmp1_arr, cmp2_arr, nbr_elems * sizeof(int));
    
    /**
     *  arrays have the same size. Array cmp1 elements are less (byte by byte) that elems of cmp3 -> memcmp return -1
     * 
     *  cmp1_arr: 01 00 00 00 02 00 00 00 (4 bytes per element)
     *  cmp3_arr: 01 00 00 00 03 00 00 00 (4 bytes per element)
     * 
     *  0x02 - 0x03 = -1
     */
    int cmp3_arr[] = {1, 3};
    compare_result(cmp1_arr, cmp3_arr, nbr_elems * sizeof(int));

    /**
     *  arrays have the same size. Array cmp1 elements are less (byte by byte) that elems of cmp4 -> memcmp return 1
     * 
     *  cmp1_arr: 01 00 00 00 02 00 00 00 (4 bytes per element)
     *  cmp4_arr: 01 00 00 00 01 00 00 00 (4 bytes per element)
     * 
     *  0x02 - 0x01 = 1
     */
    int cmp4_arr[] = {1, 1};
    compare_result(cmp1_arr, cmp4_arr, nbr_elems * sizeof(int));

    /**
     *  arrays have the same size but different types. Comparing byte to byte, the fisrt three bytes are the same
     *  fourth byte com cmp1_arr is less than cmp5_arr by two - memcmp returns -2
     * 
     *  cmp1_arr: 01 00 00 00 02 00 00 00 (4 bytes per element)
     *  cmp5_arr: 01 00 00 02             (2 bytes per element)
     * 
     *  0x00 - 0x02 = -2
     */
    short int cmp5_arr[] = {1, 2};
    compare_result(cmp1_arr, cmp5_arr, 2 * sizeof(short int));

    /*
     * memcpy - copy to a dst memory area, N bytes from an origin memory area (memory should not overlap). return  a pointer to the dst memory area.
     */
    int cpy1_arr[] = {0, 0};
    int cpy2_arr[] = {1, 2};
    
    printf("before copy: \tcpy1 arrays values: %d, %d\n", cpy1_arr[0], cpy1_arr[1]);
    memcpy(cpy1_arr, cpy2_arr, 2 * sizeof(int));
    printf("after copy: \tcpy1 arrays values: %d, %d\n", cpy1_arr[0], cpy1_arr[1]);

    /**
     * The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
     */
    int set_arr[] = {1, 1};

    printf("before set: \tset arrays values: %d, %d\n", set_arr[0], set_arr[1]);
    memset(set_arr, 0, 2 * sizeof(int));
    printf("after set: \tset arrays values: %d, %d\n", set_arr[0], set_arr[1]);

    /**
     * memchr() 
     */
    const int chr_arr[] = {1, 4}; // 01 00 00 00 04 00 00 00
    int search_value = 5;

    void *chr_res = memchr(chr_arr, search_value, 2 * sizeof(int));

    if (chr_res == NULL){
        /* memchr returns null when the value to search is not found in the memory area*/
        printf("value %d not found in memory area of chr_arr\n", search_value);
    }

    search_value = 4;
    chr_res = memchr(chr_arr, search_value, 2 * sizeof(int));

    if(chr_res != NULL){
        /* when the value to search is found in the memory area, memcpy returns the memory address of value found*/
        printf("value %d found in memory area of chr_arr. position: %p\n", search_value, chr_res);
    }

    return 0;
}
