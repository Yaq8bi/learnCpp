#include <stdio.h>
#include <driver/ledc.h>
#include <esp_task_wdt.h>
#include <esp_adc/adc_cali.h>
#include <esp_adc/adc_oneshot.h>
#include <esp_adc/adc_cali_scheme.h>

#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_DUTY_RES LEDC_TIMER_12_BIT // Duty resolution
#define LEDC_FREQUENCY 4000U            // PWM frequency in Hertz

static void led_init(void)
{
    // Prepare and then apply the LEDC PWM timer configuration
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY, // Set output frequency at 4 kHz
        .clk_cfg = LEDC_AUTO_CLK};
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepare and then apply the LEDC PWM channel configuration
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = GPIO_NUM_4};
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}

static void pot_init(adc_oneshot_unit_handle_t *adc_handle, adc_cali_handle_t *cali_handle)
{
    // ADC1 Initialization
    adc_oneshot_unit_init_cfg_t adc_config = {
        .unit_id = ADC_UNIT_1,
    };
    ESP_ERROR_CHECK(adc_oneshot_new_unit(&adc_config, adc_handle));

    // ADC1 Configuration
    adc_oneshot_chan_cfg_t channel_config = {
        .bitwidth = ADC_BITWIDTH_DEFAULT,
        .atten = ADC_ATTEN_DB_12,
    };
    ESP_ERROR_CHECK(adc_oneshot_config_channel(*adc_handle, ADC_CHANNEL_0, &channel_config));

    // ADC1 Calibration
    adc_cali_curve_fitting_config_t cali_config = {
        .unit_id = ADC_UNIT_1,
        .chan = ADC_CHANNEL_0,
        .atten = ADC_ATTEN_DB_12,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
    };
    ESP_ERROR_CHECK(adc_cali_create_scheme_curve_fitting(&cali_config, cali_handle));
}

static float map(float value, float from_min, float from_max, float to_min, float to_max)
{
    if (value > from_max)
    {
        value = from_max;
    }
    else if (value < from_min)
    {
        value = from_min;
    }
    else
    {
        ;
    }

    return ((value - from_min) * ((to_max - to_min) / (from_max - from_min)) + to_min);
}

void app_main(void)
{
    // Exclude the Idle Task from the Task WDT
    ESP_ERROR_CHECK(esp_task_wdt_delete(xTaskGetIdleTaskHandle()));

    led_init();

    adc_cali_handle_t cali_handle;
    adc_oneshot_unit_handle_t adc_handle;
    pot_init(&adc_handle, &cali_handle);

    int value, millivolts;

    while (1)
    {
        ESP_ERROR_CHECK(adc_oneshot_read(adc_handle, ADC_CHANNEL_0, &value));
        ESP_ERROR_CHECK(adc_cali_raw_to_voltage(cali_handle, value, &millivolts));

        // VREF = 3.3 v = 3300 mv
        value = (int)map(millivolts, 0, 3300, 0, 1 << LEDC_DUTY_RES);

        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, value));
        ESP_ERROR_CHECK(ledc_update_duty(LEDC_MODE, LEDC_CHANNEL));
    }
}
