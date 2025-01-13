#ifndef LCD_H
#define LCD_H

#include <stdint.h>

// Register select (0 for instructions 1 for data)
constexpr uint8_t RS = 0b00000001;
// Read-write bit
constexpr uint8_t RW = 0b00000010;
// Start data read-write bit
constexpr uint8_t E = 0b00000100;
// Backlight bit
constexpr uint8_t BL = 0b00001000;

constexpr uint8_t POWER_ON_DELAY = 50; //milliseconds
constexpr uint8_t INIT_DELAY1 = 5; //milliseconds
constexpr uint8_t INIT_DELAY2 = 120; //microseconds
constexpr uint8_t COMMAND_DELAY = 40; //microseconds
constexpr uint8_t HOME_CLEAR_DELAY = 2; //milliseconds

constexpr uint8_t INIT_BYTE = 0b00000011;

// See 44780 datasheet page 25-27 for symbol explanations
constexpr uint8_t ENTRY_MODE = 0b00000100;
constexpr uint8_t ID =         0b00000010;
constexpr uint8_t S =          0b00000001;

constexpr uint8_t DISPLAY_CONTROL = 0b00001000;
constexpr uint8_t D =               0b00000100;
constexpr uint8_t C =               0b00000010;
constexpr uint8_t B =               0b00000001;

constexpr uint8_t CURSOR_SHIFT = 0b00010000;
constexpr uint8_t SC =           0b00001000;
constexpr uint8_t RL =           0b00000100;

constexpr uint8_t FUNCTION_SET = 0b00100000;
constexpr uint8_t DL =           0b00010000;
constexpr uint8_t N =            0b00001000;
constexpr uint8_t F =            0b00000100;

constexpr uint8_t SET_DDRAM_ADDR = 0b10000000;

constexpr uint8_t CLEAR = 0b00000001;
constexpr uint8_t HOME = 0b00000010;

constexpr char BLANK_LINE[] = "                ";

void lcd_baseInit();
void _lcd_write(uint8_t command, uint8_t rs);
void lcd_writeCommand(uint8_t command);
void lcd_writeCharacter(uint8_t character);
void lcd_writeString(char string[]);
void lcd_setCursor(uint8_t x, uint8_t y);
void lcd_writeLines(char lineOne[], char lineTwo[], bool clear);

#endif // LCD_H
