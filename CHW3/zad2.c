        #include <stdio.h>
        #include <math.h>   
        #define ARRAY_SIZE 5
        void main(){
        #if (ARRAY_SIZE > 0 && ARRAY_SIZE < 11)
        int arr[ARRAY_SIZE];
        for(int i = 0; i < ARRAY_SIZE; i++){
            arr[i] =(int)pow(2,i);
            printf("%d ", arr[i]);
        }
        printf("\n");
        #else
        printf("This array size is not supported by this application");
        #endif
    }