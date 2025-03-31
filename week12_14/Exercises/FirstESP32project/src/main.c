#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <driver/gpio.h>
#include <esp_task_wdt.h>

#define MAX_STRING_LEN 20
/* CHAT GPT to convert my code, it gave me this, analyze first !!!!*/
int toUpperCase(char *str)
{
    int _status = 1; // true{1}, false{0}

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32; // Convert to uppercase
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            _status = 0; // False
        }
        else if (str[i] == ' ') // Space remains unchanged
        {
            ;
        }
        else if (isdigit((unsigned char)str[i])) // What does this do? Unsigned char? Huh????
        {
            ;
        }
        else
        {
            ;
        }
    }
    return _status;
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

void app_main(void)
{

    // Exclude the Idle Task from the Task WDT
    //  You can also do it by running: pio run -t menuconfig
    //  Component Config -> ESP System Settings -> Watch CPU0 Idle Task
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    char string[MAX_STRING_LEN + 1]; // Max 20 chars + 1 for null terminator
    int error;

    while (1)
    {

        do
        {
            error = 0;
            printf("Input a string: \n");
            fgets(string, sizeof(string), stdin); // getline functionality just like in c++.

            // Remove newline if present
            size_t len = strlen(string);
            if (len > 0 && string[len - 1] == '\n') // replace new line with terminating null char.
            {
                string[len - 1] = '\0';
            }

            if (strlen(string) > MAX_STRING_LEN)
            {
                error = 1;
                printf("This string is too long, max 20 chars allowed: %s\v", string);
            }
            else if (!toUpperCase(string))
            {
                error = 1;
                printf("This string has capital letters, only small letters allowed: %s\v", string);
                continue;
            }
        } while (error);

        toUpperCase(string);
        toReverse(string);

        printf("\n%s\n", string);
    }
}
