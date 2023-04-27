#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal LCD(0);

int timer = 150, Out = OUTPUT, In = INPUT;

byte hearticon[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smileicon[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

void setup(){
  pinMode(2, Out); pinMode(A0, In); pinMode(A1, In); pinMode(A2, In);

  // LCD workspace

  LCD.begin(16, 2);
  LCD.setCursor(1, 0);
  LCD.print("Hello! this is");
  delay(timer);
  LCD.setCursor(2, 1);
  LCD.print("Tamim Ahmad.");
  delay(timer);
  LCD.clear();
  LCD.createChar(0, hearticon);
  LCD.setCursor(0, 0);
  LCD.print("Make with ");
  LCD.write(byte(0));
  LCD.setCursor(6, 1);
  LCD.print("Tinkercad!");
  delay(timer+850);
  LCD.clear();
}

void loop(){
  if (digitalRead(A0) == 1) {
    LCD.clear();
    tone(2, 440, 100);
    LCD.setCursor(2, 0);
    LCD.print("You selected");
    LCD.setCursor(5, 1);
    LCD.write((byte)1);
  	LCD.print("Green");
    LCD.write((byte)1);
    delay(timer+350);
    LCD.clear();
    LCD.createChar(0, smileicon);
    LCD.setCursor(8, 0);
    LCD.write(byte(0));
    LCD.setCursor(3, 1);
  	LCD.print("Thank you!");
  	delay(timer);
  }
  
  if (digitalRead(A1) == 1) {
    LCD.clear();
    tone(2, 494, 100);
    LCD.setCursor(2, 0);
    LCD.print("You selected");
    LCD.setCursor(5, 1);
  	LCD.write((byte)1);
  	LCD.print("Blue");
    LCD.write((byte)1);
    delay(timer+350);
    LCD.clear();
    LCD.createChar(0, smileicon);
    LCD.setCursor(8, 0);
    LCD.write(byte(0));
    LCD.setCursor(3, 1);
  	LCD.print("Thank you!");
  	delay(timer);
  }
  
  if (digitalRead(A2) == 1) {
    LCD.clear();
    tone(2, 523, 100);
    LCD.setCursor(2, 0);
    LCD.print("You selected");
    LCD.setCursor(6, 1);
  	LCD.write((byte)1);
  	LCD.print("Red");
    LCD.write((byte)1);
    delay(timer+350);
    LCD.clear();
    LCD.createChar(0, smileicon);
    LCD.setCursor(8, 0);
    LCD.write(byte(0));
    LCD.setCursor(3, 1);
  	LCD.print("Thank you!");
  	delay(timer);
  }
}
