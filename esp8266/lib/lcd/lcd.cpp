#include "lcd.h"

byte bell[8] = BELL;
byte note[8] = NOTE;
byte clock2[8] = CLOCK;
byte heart[8] = HEART;
byte duck[8] = DUCK;
byte check[8] = CHECK;
byte cross[8] = CROSS;
byte retarrow[8] = RETARROW;

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned int lcdRowIndex = 0;

void LCD::configure()
{
    lcd.init(D4, D3); // initialize the lcd
    lcd.backlight();

    lcd.createChar(0, bell);
    lcd.createChar(1, note);
    lcd.createChar(2, clock2);
    lcd.createChar(3, heart);
    lcd.createChar(4, duck);
    lcd.createChar(5, check);
    lcd.createChar(6, cross);
    lcd.createChar(7, retarrow);
    lcd.home();

    lcd.print("Hello world...");
    lcd.setCursor(0, 1);
    lcd.print(" i ");
    lcd.printByte(3);
    lcd.print(" arduinos!");
}

void LCD::print(String message)
{
    LCD::checkIndex();
    lcd.setCursor(0, lcdRowIndex);
    lcd.print(message);
    lcdRowIndex++;
}

void LCD::clear()
{
    lcdRowIndex = 0;
    lcd.clear();
}

void LCD::checkIndex()
{
    if (lcdRowIndex >= 4)
    {
        LCD::clear();
    }
}
