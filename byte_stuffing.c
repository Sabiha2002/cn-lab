// f -> flag sequence
// e -> escape sequence

#include <stdio.h>

void main()
{
    char a[20], b[20];
    int i, n, j;
    char f, s;
    printf("At sender side\n");
    printf("Enter the size of the frame : ");
    scanf("%d", &n);
    printf("Enter the characters in frame : \n");
    for (i = 0; i < n; i++)
        scanf(" %c", &a[i]);
    printf("FRAME: ");
    for (i = 0; i < n; i++)
        printf("%c", a[i]);
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 'f')
        {
            b[j] = 'e';
            j++;
            b[j] = a[i];
        }
        else if (a[i] == 'e')
        {
            b[j] = 'e';
            j++;
            b[j] = a[i];
        }
        else
            b[j] = a[i];

        j++;
    }
    printf("\nThe data being sent (with byte stuff): ");
    printf("f");
    for (i = 0; i < j; i++)
    {
        printf("%c", b[i]);
    }
    printf("f\n");
    printf("--------------------------------\n");
    printf("At receiver side\n");
    printf("The stuffed message is: ");
    printf("f");
    for (i = 0; i < j; i++)
    {
        printf("%c", b[i]);
    }
    printf("f\n");
    printf("The Destuffed message is: ");
    for(int i = 0; i < j; i++){
        if(b[i] == 'e'){
            printf("%c", b[++i]);
        }else{
            printf("%c", b[i]);
        }
    }
    printf("\n");


}