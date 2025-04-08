#include <stdio.h>
#include <ctype.h>
#include <esp_task_wdt.h>

#define MAX_DIGIT 4

enum
{
    IS_PRIME,
    IS_NOT_PRIME,
};

static int getNum(void)
{
    while (EOF != getchar()) // clean buffer
    {
        ;
    }

    int ch = 0;
    size_t i = 0;
    int _usrNumber = 0; // keep number.
    while (i < MAX_DIGIT)
    {
        ch = getchar();
        if (isdigit(ch) || (ch == '\n'))
        {
            if (ch == '\n')
            {
                break;
            }

            putchar(ch);
             
            _usrNumber = (_usrNumber * 10); // [125] so an input of 1, 2, 3 => 123; 1x10=10, 2x
            _usrNumber += ch - '0';
            i++;
        }
    }
    putchar('\n');

    return _usrNumber;
}

static int primeCheck(int _theNum)
{
    int status = IS_PRIME;

    for (size_t i = 2; i < _theNum; i++)
    {
        if (_theNum % i == 0)
        {
            status = IS_NOT_PRIME;
            break;
        }
    }
    return status;
}


void app_main()
{
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    while (1)
    {
        (void)printf("Enter a number in the range of [2,1000]: ");

        int userInt = 0;
        userInt = getNum();

        if (userInt < 2 || userInt > 1000)
        {
            (void)printf("INVALID\n");
        }
        else if (userInt)
        {

            switch (primeCheck(userInt))
            {
            case IS_NOT_PRIME:
            {
                (void)printf("%i is not a prime!\n", userInt);
                break;
            }

            case IS_PRIME:
            {
                (void)printf("%i is a prime number!\n", userInt);
                break;
            }
            default:
            }
        }
        else
        {
            ;
        }
    }
}
