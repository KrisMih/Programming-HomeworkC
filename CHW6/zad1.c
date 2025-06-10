#include <limits.h>
#include <stdio.h>

int main(void) {
    printf(" %-12s  %-12s  %-10s  %-18s  %-18s  %-18s  %-18s \n", 
           "Type", "Size (bytes)", "Format", "Max signed", "Min signed", "Format unsigned", "Max unsigned");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("%-12s  %-12.2zu  %-10s  %-18d  %-18d  %-18s  %-18u \n", "int", sizeof(int), "d", INT_MAX, INT_MIN, "u", UINT_MAX);
    printf("%-12s  %-12.2zu  %-10s  %-18ld  %-18ld  %-18s  %-18lu \n","long", sizeof(long), "ld", LONG_MAX, LONG_MIN, "ul", ULONG_MAX);
    printf("%-12s  %-12.2zu  %-10s  %-18lld  %-18lld  %-18s  %-18llu \n", "long long", sizeof(long long), "lld", LLONG_MAX, LLONG_MIN, "ull", ULLONG_MAX);
    printf("%-12s %-12.2zu %-10s %-18hd  %-18hd  %-18s  %-18hu \n", "short", sizeof(short), "hd", SHRT_MAX, SHRT_MIN, "hu", USHRT_MAX);

    return 0;
}
