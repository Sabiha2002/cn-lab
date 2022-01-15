#include <stdio.h>

int main() {
    int a[20], b[30];
    printf("Enter the frame size: ");
    int n;
    scanf("%d", &n);
    printf("Enter the frame in the form of 0 and 1\n");
    int k = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i]){
            count++;
        }else{
            count = 0;
        }
        b[k++] = a[i];
        if(count == 5){
            b[k++] = 0;
        }
    }
    printf("Frame without stuffing: ");
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
    printf("Frame with stuffing: ");
    for(int i = 0; i < k; i++){
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}
