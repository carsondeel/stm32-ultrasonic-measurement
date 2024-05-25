#include "main.h" // Include your main project header
#include "stm32f4xx_hal.h" 
#include "lcd_i2c.h" 

#define TRIG_PIN GPIO_PIN_12
#define TRIG_PORT GPIOC
#define ECHO_PIN GPIO_PIN_13
#define ECHO_PORT GPIOC

void setup() {
    // GPIO initialization
    // OUTPUT (TRIG_PIN) and INPUT (ECHO_PIN)

    // I2C and LCD initialization
    lcd.init();
    lcd.backlight();

    // Initial LCD message (optional)
    lcd.setCursor(0, 0);
    lcd.print("Distance Sensor");
    HAL_Delay(2000); // Show message for 2 seconds
    lcd.clear();
}

void loop() {
    // Trigger ultrasonic sensor
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);
    HAL_Delay(2); // 2 microsecond delay
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
    HAL_Delay(10); // 10 microsecond delay
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

    // Measure pulse duration
    uint32_t startTime = 0;
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == GPIO_PIN_RESET); // Wait for rising edge
    startTime = HAL_GetTick(); // Start timer
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == GPIO_PIN_SET);  // Wait for falling edge

    uint32_t duration = HAL_GetTick() - startTime; // Calculate pulse duration in milliseconds

    // Calculate distance in centimeters
    uint32_t distance = (duration * 1000 * 0.0343) / 2; // Sound speed: 343 m/s

    // Error handling and display
    if (distance >= MAX_DISTANCE || distance <= 0) {
        lcd.setCursor(0, 0);
        lcd.print("Out of range ");
    } else {
        lcd.setCursor(0, 0);
        lcd.print("Distance: ");
        lcd.print(distance);
        lcd.print(" cm   "); // Add extra spaces to clear previous value
    }

    HAL_Delay(300); // Adjust delay for smoother updates
}