#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_sleep.h"

void app_main() {
    printf("ESP32 Sleep Mode Test\n");

    while (1) {
        printf("Running in active mode...\n");

        // Perform your application tasks here in active mode.
        // all of our custom tasks can be plced here. 

        // Delay for a few seconds before entering sleep mode.
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        printf("Entering light sleep mode...\n");

        // light sleep 
        esp_light_sleep_start();

        // After waking up from light sleep, execution continues here.
        // You can add code to restore the device's state if necessary.
        printf("Waking up from light sleep mode...\n");

        // Delay for a few seconds before entering deep sleep mode.
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        printf("Entering deep sleep mode...\n");

        //  timer for deep sleep (ex 10 (in microseconds)seconds).
        esp_sleep_enable_timer_wakeup(10 * 1000000);

        // entering deep sleep mode and wake up after 10 seconds.
        esp_deep_sleep_start();

        // after exiting the deep sleep mode, hthe program will again start from the aapp main. becuse the device is going to be reset after the deep sleep release. 
      // maybe w can configure some external interrupt pin to exit from the deep sleep mode. 
    }
}
