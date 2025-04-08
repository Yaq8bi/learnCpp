#include <stdio.h>
#include <esp_timer.h>
#include <driver/gpio.h>
#include <esp_task_wdt.h>

class Metro
{
private:
    int64_t counter;
    const int64_t interval;

public:
    // prev_micro => timer; local to the class interval => (passed in _interval * 1000);
    // Metro(int64_t _interval) : prev_micro{esp_timer_get_time()}, interval{1000 * _interval} {}
    Metro(int64_t _passedArg) : counter{esp_timer_get_time()}, interval{1000 * _passedArg} {}

    bool check(void)
    {
        bool checked{false};
        int64_t now{esp_timer_get_time()};
        if (now - counter >= interval)
        {
            checked = true;
            counter = now;
        }
        return checked;
    }
};

extern "C" void
app_main(void)
{
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle())); // watchdog timer, delete the idle task.
    ESP_ERROR_CHECK(gpio_reset_pin(GPIO_NUM_4));                    // We get teh pin4, and reset it(initialize it?)
    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_4, GPIO_MODE_INPUT_OUTPUT));

    Metro LED{500};
    Metro print{1000};

    while (1)
    {
        if (LED.check())
        {
            ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_4, !gpio_get_level(GPIO_NUM_4)));
        }

        if (print.check())
        {
            printf("HELLO WORLD\n");
        }
    }
}