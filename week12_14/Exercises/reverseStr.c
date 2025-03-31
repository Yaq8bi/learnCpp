#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32; // Convert to uppercase
        }
        else if (str[i] == ' ') // Space remains unchanged
        {
            ;
        }
        else if (isdigit((unsigned char)str[i]))
        {
            ;
        }
        else
        {
            str[i] = str[i] + 32; // Convert to lowercase
        }
    }
}

void toReverse(char *str)
{
    int hasDigit = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) // Check for digits
    {
        if (isdigit((unsigned char)str[i]))
        {
            hasDigit = 1;
            break;
        }
    }

    if (!hasDigit)
    {
        for (int i = 0, j = len - 1; i < j; i++, j--) // Reverse string
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
}

int main()
{
    char string[21]; // Max 20 chars + 1 for null terminator
    int error;

    do
    {
        error = 0;
        printf("Input a string: \n");
        fgets(string, sizeof(string), stdin);

        // Remove newline if present
        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n')
        {
            string[len - 1] = '\0';
        }

        if (strlen(string) > 20)
        {
            error = 1;
            printf("This string is too long, max 20 chars allowed:\n%s\n", string);
        }
    } while (error);

    toUpperCase(string);
    toReverse(string);

    printf("%s\n", string);

    return 0;
}
