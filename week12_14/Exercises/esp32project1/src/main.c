#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <esp_task_wdt.h>

#define MAX_STRING_LEN 20

void toReverse(char *str) // pointer to the str
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
        for (int left = 0, right = len - 1; left < right; left++, right--) // reverse string
        {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
        }
    }
}

static size_t get_string(char *str, size_t length)
{
    char chr = 0;
    size_t position = 0;

    while (position < length)
    {

        chr = getchar();
        if (chr == '\n')
        {
            break;
        }
        else if ((chr >= 'a') && (chr <= 'z'))
        {
            putchar(chr);
            str[position] = toupper(chr);
            position++;
        }
        else
        {
            ;
        }
    }
    str[position] = '\0';

    return position;
}

void app_main(void)
{
    // Exclude the Idle Task from the Task WDT
    //  You can also do it by running: pio run -t menuconfig
    //  Component Config -> ESP System Settings -> Watch CPU0 Idle Task
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    char string[MAX_STRING_LEN + 1]; // Max 20 chars + 1 for null terminator

    while (1)
    {
        while (EOF != getchar()) // clean buffer
        {
            ;
        }
        printf("Enter a String: ");

        // Comunicationi between esp32 and pc is serial, so data is tranferred in bytes{ Putchar, getchar}.
        size_t length = get_string(string, MAX_STRING_LEN);


        if (length > 0)
        {
            toReverse(string);
        }

        printf("\n%s\n", string);
    }
}
