#include<stdio.h>

int main(){
    int hammingcode[8], data[4], received_data[8], parity_error[3];
    printf("Enter the data:\n");  
    for(int i = 0; i < 4; i++){
        scanf("%d", &data[i]);
    }
    int d[4] = {1, 2, 3, 5};
    for(int i = 0; i < 4; i++){
        hammingcode[d[i]] = data[i];
    }
    hammingcode[7] = (hammingcode[1]^hammingcode[3]^hammingcode[5]);
    hammingcode[6] = (hammingcode[1]^hammingcode[2]^hammingcode[5]);
    hammingcode[4] = (hammingcode[1]^hammingcode[2]^hammingcode[3]);
    printf("Encoded data is: ");
    for(int i = 1; i <= 7; i++){
        printf("%d", hammingcode[i]);
    }
    printf("\n");

    printf("Enter received data bits one by one:\n");
    for(int i = 1; i <= 7; i++){
        scanf("%d", &received_data[i]);
    }
    parity_error[0] = received_data[7]^received_data[1]^received_data[3]^received_data[5];
    parity_error[1] = received_data[6]^received_data[1]^received_data[2]^received_data[5];
    parity_error[2] = received_data[4]^received_data[1]^received_data[2]^received_data[3];
    int error = 0;
    for(int i = 0; i < 3; i++){
        error += ((1 << i)*parity_error[i]);
    }
    if(error == 0){
        printf("No error while transmission of data\n");
    }else{
        printf("Error at the position %d in the received data\n", error);
        printf("********Error Correction********\n");
        printf("Data sent: ");
        for(int i = 1; i <= 7; i++){
            printf("%d", hammingcode[i]);
        }
        printf("\n");
        printf("Data received: ");
        for(int i = 1; i <= 7; i++){
            printf("%d", received_data[i]);
        }
        printf("\n");
        printf("Correct Message\n");
        received_data[8-error] ^= 1;
        for(int i = 1; i <= 7; i++){
            printf("%d", received_data[i]);
        }
        printf("\n");
    }
    return 0;
}