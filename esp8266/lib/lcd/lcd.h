// LCD.h
#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args) write(args);
#else
#define printByte(args) print(args, BYTE);
#endif

class LCD {
public:
    static void configure();
    static void print(byte* message);
    static void print(String message);
    static void clear();
private:
    static void checkIndex();
};

#endif