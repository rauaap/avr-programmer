#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "i2c.h"
#include "lcd.h"

constexpr uint8_t LCD_ADDR = 0x26;
constexpr uint16_t display_rotation_delay = 500;

int main(void) {
    sei();

    i2c_init(LCD_ADDR);
    lcd_baseInit();
    lcd_writeCommand(CLEAR);

    char* hello[3][2] = {
        {"one two three", "four five six"},
        {"ATmega328P", "running code"},
        {"built with", "avr-gcc"}
    };

    // Configure PD2 as output
    DDRD |= (1 << PD2);

    while (1) {
        // Set PD2 high
        //PORTD |= (1 << PD2);
        //_delay_ms(500);  // Delay 500 milliseconds

        for (size_t i = 0; i < 3; i++) {
            lcd_writeLines(hello[i][0], hello[i][1], true);
            _delay_ms(display_rotation_delay);
        }

        // Set PD2 low
        //PORTD &= ~(1 << PD2);
        //_delay_ms(500);  // Delay 500 milliseconds
    }

    return 0;
}
