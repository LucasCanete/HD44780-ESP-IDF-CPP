/*
    C++ implemenatation based on lcd library by maxsydnet.
    More information at: https://github.com/maxsydney/ESP32-HD44780
    May 2021
*/

#ifndef HD44780_H
#define HD44780_H
#include <string>
#include <ctype.h>

class LCD_I2C{
public:
    LCD_I2C();

    void init(uint8_t addr, uint8_t dataPin, uint8_t clockPin, uint8_t cols, uint8_t rows);
    void setCursor(uint8_t col, uint8_t row);
    void home(void);
    void clear(void);
    void writeChar(char c);
    void print(std::string str);
    void print(int i); 
    void print(char c);

    void println(std::string str);
    void println(int i);
    void println(char c);
private:
    uint8_t cur_col,cur_row;

};


#endif