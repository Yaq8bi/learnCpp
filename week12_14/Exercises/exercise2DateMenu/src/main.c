#include <stdio.h>
// #include <ctype.h>
#include <time.h>
#include <esp_sntp.h>
#include <esp_task_wdt.h>

#define FORMAT "YYYY-MM-DD HH:MM:SS"

enum
{
    OKAY,
    USER_DATE_EMPTY,
    INVALID
};

// void functionPrint(int enumVal)
// {
//     (void)printf("You picked a %s", (enumVal == 0) ? "OKAY" : "NOT_OKAY");
// }

static char myGetchar(void)
{

    while (EOF != getchar()) // goes to buffer, takes any value in the buffer, returns. [getchar() consumes the items from buffer(they don't exist anymore.)]
    {
        ;
    }

    int ch = EOF;

    while ((ch != 'S') && (ch != 'G'))
    {
        ch = toupper(getchar());

        if (ch == '\r') // for some terminals that need it.
        {
            ch = '\n';
        }
    }

    putchar(ch);

    return ch;
}

static int getDateTime(struct tm *_usrDateTime)
{
    char ch = 0;       // hold chars
    size_t i = 0;      // index
    int status = OKAY; // check flag
    char _stringBuff[sizeof(FORMAT)] = {0};

    while (i < sizeof(_stringBuff) - 1)
    {
        ch = getchar();

        if (isdigit(ch) || isspace(ch) || (ch == ':') || (ch == '-') || (ch == '\n'))
        {
            if (ch == '\n')
            {
                break;
            }

            putchar(ch);
            _stringBuff[i] = ch;
            i++;
        }
    }
    printf("\n");

    if (i == 0)
    {
        status = USER_DATE_EMPTY;
    }
    else if (i < sizeof(FORMAT) - 1) // removing null terminator and then compare.
    {
        status = INVALID;
    }
    else
    {
        i = 0;
        while (i < sizeof(FORMAT) - 1) // Hafizayi okudugumuz icin null terminator orada ve total byte'a ekleniyor. [0][1][2][3][4][5]['\n']
        {
            if (isalpha((int)FORMAT[i])) // when going through the format, we stop at the alphabet("Y") to compare it against the users input to see if they have inputted a digit or not.
            {
                if (!isdigit((int)_stringBuff[i]))
                {
                    status = INVALID;
                    break;
                }
            }
            else
            {
                if (FORMAT[i] != _stringBuff[i])
                {
                    status = INVALID;
                    break;
                }
            }
            i++;
        }

        if (status == OKAY)
        {
            (void)sscanf(_stringBuff, "%04d-%02d-%02d %02d:%02d:%02d", &_usrDateTime->tm_year, &_usrDateTime->tm_mon, &_usrDateTime->tm_mday,
                         &_usrDateTime->tm_hour, &_usrDateTime->tm_min, &_usrDateTime->tm_sec); // Split them up into parts that go into the variables inside the struct that is a pointer passed in as argument to THIS function.

            // _usrDateTime->tm_mon -= 1;
            _usrDateTime->tm_year -= 1900;

        }
    }

    return status;
}

void app_main(void)
{
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    while (1)
    {
        int command = myGetchar(); // returns the ch
        (void)printf("\nWrite G to recieve, S to set:");

        switch (command)
        {
        case 'S':
        {
            // struct to hold the users date.
            struct tm usrDateTime = {0};
            (void)printf("\nEnter current date: (%s)", FORMAT);

            switch (getDateTime(&usrDateTime))
            {
            case OKAY: // if getdatetime returns OKAY, run code below.
            {
                struct timeval now = {0}; // timeval
                now.tv_sec = mktime(&usrDateTime);
                settimeofday(&now, NULL);
            }
            break;
            case INVALID:

                printf("Invalid time.");
                break;
            default:
                break;
            }
            printf("\n");
        }

        break;

        case 'G':
        {
            time_t now = time(NULL);                  // Struct for seconds and microseconds for machine(time_t is a counter in seconds since epoc 1970 january 1).
            char datetime[32] = {0};                  // To hold the date value
            struct tm *_infoOfTime = localtime(&now); // holds human readable time, we pass in

            strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", _infoOfTime);

            printf("\nThe current time: %s\n\n", datetime);
        }
        break;
        case '\n':
            printf("\n");
            break;

        default:
            break;
        }
    }
}