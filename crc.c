#include <stdio.h>
#include <stdbool.h>

void getRemainder(int df[], int rem[], int divisor[], int data_fr_len, int rem_len){
    for(int i = 0; i < data_fr_len; i++){
        if(df[i] == 1){
            int kl = i;
            for(int j = 0, k = i; j < rem_len; j++, k++){
                rem[j] = (df[k] ^ divisor[j]);
            }
            for(int j = 0, k = kl; j < rem_len; j++, k++){
                df[k] = rem[j];
            }
        }
    }
}

bool checkRemainder(int rem[]){
    for(int i = 0; i < 4; i++){
        if(rem[i]) return false;
    }
    return true;
}
int main(){
    int data_fr_len, divisor_len;
    printf("Enter the size of the data frame: ");
    scanf("%d", &data_fr_len);
    printf("Enter the size of the divisor: ");
    scanf("%d", &divisor_len);

    int dup_fr_len = data_fr_len + divisor_len - 1, rec_fr_len = dup_fr_len, rem_len = divisor_len,
        data_frame[data_fr_len],
        duplicate_frame[dup_fr_len], 
        received_frame[rec_fr_len], 
        divisor[divisor_len], 
        rem[rem_len];

    printf("Enter the data frame:\n");
    for(int i = 0; i < data_fr_len; i++){
        scanf("%d", &data_frame[i]);
        duplicate_frame[i] = data_frame[i];
        received_frame[i] = data_frame[i];
    }

    printf("Enter the divisor:\n");
    for(int i = 0; i < divisor_len; i++){
        scanf("%d", &divisor[i]);
    }

    for(int i = data_fr_len; i < dup_fr_len; i++){
        duplicate_frame[i] = 0;
    }

    getRemainder(duplicate_frame, rem, divisor, data_fr_len, rem_len);
    printf("The actual redundant bits that need to be added to the data frame are (remainder of the binary division): ");
    for(int i = 1; i < rem_len; i++){
        printf("%d", rem[i]);
    }
    printf("\n");

    for(int i = data_fr_len, j = 1; i < dup_fr_len; i++, j++){
        received_frame[i] = rem[j];
    }
    printf("The received frame is: ");
    for(int i = 0; i < rec_fr_len; i++){
        printf("%d", received_frame[i]);
    }
    printf("\n");

    getRemainder(received_frame, rem, divisor, data_fr_len, rem_len);
    bool flag = checkRemainder(rem);
    if(flag){
        printf("Frame received correctly\n");
    }else{
        printf("Frame received incorrectly\n");
    }

    while(1){
        int choice;
        printf("Do you want to check other received frame (y-1, n-0): ");
        scanf("%d", &choice);
        if(!choice) break;
        printf("Enter the received frame: \n");
        for(int i = 0; i < rec_fr_len; i++){
            scanf("%d", &received_frame[i]);
        }
        getRemainder(received_frame, rem, divisor, data_fr_len, rem_len);
        bool flag = checkRemainder(rem);
        if(flag){
            printf("Frame received correctly\n");
        }else{
            printf("Frame received incorrectly\n");
        }
    }
    return 0;
}