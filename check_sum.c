#include <stdio.h>
#include <string.h>

int main()
{
    char a[20], b[20];
    char s[20], com[20];
    int i;
    printf("Enter the first binary string:");
    scanf("%s", a);
    printf("enter the second binary string: ");
    scanf("%s", b);
    int len = strlen(a);
    if (strlen(a) == strlen(b))
    {
        char carry = '0';
        for (int i = len - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0' && carry == '0')
            {
                s[i] = '0';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '0' && carry == '1')
            {
                s[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '0')
            {
                s[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '1')
            {
                s[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '0')
            {
                s[i] = '1';
                carry = '0';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '1')
            {
                s[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '1')
            {
                s[i] = '1';
                carry = '1';
            }
        }
        if (carry == '1')
        {
            for (int i = len - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                    break;
                }else{
                    s[i] = '0';
                }
            }
        }
    }
    else
    {
        printf("Wrong inputs\n");
        return 0;
    }
    for (i = len - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            com[i] = '0';
        }
        else
        {
            com[i] = '1';
        }
    }
    printf("Sum is : ");
    for (i = 0; i < len; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
    printf("Checksum is : ");
    for (i = 0; i < len; i++)
    {
        printf("%c", com[i]);
    }
    printf("\n");
    printf("----Receiver side----\n");
    for (i = len - 1; i >= 0; i--)
    {
        if (s[i] == '0' && com[i] == '0' || s[i] == '1' && com[i] == '1')
        {
            printf("Error\n");
            break;
        }
    }
    if (i == -1)
    {
        printf("No error\n");
    }
    printf("Insert error\n");
    if (s[0] == '0')
    {
        s[0] = '1';
    }
    else
    {
        s[0] = '0';
    }
    for (i = len - 1; i >= 0; i--)
    {
        if (s[i] == '0' && com[i] == '0' || s[i] == '1' && com[i] == '1')
        {
            printf("Error\n");
            break;
        }
    }
    if (i == -1)
    {
        printf("No error");
    }
}
