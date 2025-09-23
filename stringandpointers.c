#include <stdio.h>

//STRING DISPLAY
void display(char str[])
{
    char *p = str;
    while (*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
    printf("\n");
}

//STRING LENGTH
void length(char str[])
{
    char *p = str;
    int length = 0;
    while (*p != '\0')
    {
        p++;
        length++;
    }
    printf("Length: %d\n", length);
}
//STRING REVERSE
void reverse(char str[])
{
    char *p = str;
    
    while (*p != '\0')
    {
        p++;
    }
    p--;
    while (p >= str)
    {
        printf("%c", *p);
        p--;
    }
    printf("\n");
}

//STRING PALINDROME
void palindrome(char str[])
{
    char *p = str;
    char *q = str;
    int isPalindrome = 1;

    
    while (*p != '\0')
    {
        p++;
    }
    p--;

    while (p > q)
    {
        if (*p != *q)
        {
            isPalindrome = 0;
            break;
        }
        p--;
        q++;
    }

    if (isPalindrome)
    {
        printf("IT IS A PALINDROME\n");
    }
    else
    {
        printf("NOT A PALINDROME\n");
    }
}

int main()
{
    char str[100];
    printf("ENTER STRING: ");
    scanf("%s", str); 

    printf("Display: ");
    display(str);
    printf("Reverse: ");
    reverse(str);
    printf("Length: ");
    length(str);
    printf("Palindrome Check: ");
    palindrome(str);

    return 0;
}