
/*
    C++ implemenatation based on lcd library by maxsydnet.
    More information at: https://github.com/maxsydney/ESP32-HD44780
    May 2021
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "hd44780.h"

// To use c++ change main.c to main.cpp and add this code
#ifdef __cplusplus

extern "C" {
    #endif
    void app_main(void);
    
    #ifdef __cplusplus
}
#endif

void app_main(void)
{
    LCD_I2C lcd; 

    lcd.init(0x27,21,22,2,16); 

   // lcd.home();
    lcd.clear();
    
    while(1){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Hi there!"); //printing a string
        vTaskDelay(3000/portTICK_PERIOD_MS);
        lcd.clear();

        lcd.println("if you read this"); //using println to print in next line
        lcd.print("Everything works!");
        vTaskDelay(4000/portTICK_PERIOD_MS);
        lcd.clear();

        

         for(int i = 10; i > 0; i-- ){
            lcd.setCursor(5,0);
            lcd.print(':'); //printing chars
            lcd.println(')');

            lcd.print("Restarting in:");
            lcd.print(i); //printing int
            vTaskDelay(1000/portTICK_PERIOD_MS);
            lcd.clear();

        }
        


    }
    

    
}
