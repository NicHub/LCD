#include <Arduino.h>

// LCD Screen
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

/**
 *
 */
void configure_lcd_screen()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
    for (uint8_t cnt = 0; cnt < 4; cnt++)
    {
        lcd.setCursor(cnt * 3, cnt);
        lcd.print("LCD START !");
        delay(500 - cnt * 100);
    }
    delay(500);
}

/**
 *
 */
void configure_serial()
{
    Serial.begin(BAUD_RATE);
    Serial.println(F("\n\n\n# LED\n"));
    Serial.print(F("FILE NAME:        "));
    Serial.println(__FILE__);
    Serial.print(F("PATH:             "));
    Serial.println(PATH);
    Serial.print(F("COMPILATION DATE: "));
    Serial.println(COMPILATION_DATE);
    Serial.print(F("COMPILATION TIME: "));
    Serial.println(COMPILATION_TIME);
    Serial.println("");
}

/**
 *
 */
void setup()
{
    configure_serial();
    configure_lcd_screen();
}

/**
 *
 */
void loop()
{
    if (Serial.available())
    {
        delay(100);
        lcd.clear();
        while (Serial.available() > 0)
        {
            lcd.write(Serial.read());
        }
    }
}