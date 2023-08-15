#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);
int lmt1=3;
int lmt2=5;
int rmt1=6;
int rmt2=11;
int c_sensor;
int r_sensor;
int l_sensor;
byte customChar[8]={
  0b00000,
  0b00001,
  0b00010,
  0b00100,
  0b01000,
  0b11111,
  0b11011,
  0b11111,
}; 
byte customChar3[8]={
  0b00000,
  0b10000,
  0b01000,
  0b00100,
  0b00010,
  0b11111,
  0b11011,
  0b11111,
}; 
byte customChar1[8]={
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
}; 
void setup() {
 pinMode(lmt1,OUTPUT);
 pinMode(lmt2,OUTPUT);
 pinMode(rmt1,OUTPUT);
 pinMode(rmt2,OUTPUT);
 pinMode(r_sensor,INPUT);
 pinMode(l_sensor,INPUT);
 pinMode(c_sensor,INPUT);
 lcd.begin(16,2);
}
 void loop()
  {
  c_sensor=digitalRead(A0);
  l_sensor=digitalRead(10);
 r_sensor=digitalRead(9);

 if(c_sensor==LOW)
{
  stpleft();
lcd.clear();
cc(); 
   for(int i=4;i<10;i++)
{
    lcd.scrollDisplayRight();
  delay(50);
}
}
 if(c_sensor==HIGH)
{
  stpright();
for(int i=4;i<15;i++)
{
    lcd.scrollDisplayRight();
  delay(50);
}}
if(r_sensor==HIGH&&c_sensor==LOW)
{
  stpmt();
  lcd.print("loading goods.......");
    
}
 if(l_sensor==HIGH&&c_sensor==LOW)
{
  stpmt();
  lcd.print("side please.......");
} 
  }
void stpleft()
{
  analogWrite(lmt2,0);
analogWrite(lmt1,0);
analogWrite(rmt1,200);
analogWrite(rmt2,0);
}
void stpright()
{
analogWrite(lmt2,150);
analogWrite(lmt1,0);
analogWrite(rmt1,0);
analogWrite(rmt2,0);
}
void stpmt()
{
analogWrite(lmt2,0);
analogWrite(lmt1,0);
analogWrite(rmt1,0);
analogWrite(rmt2,0);
}
void cc()
{
   lcd.createChar(1,customChar);
      lcd.createChar(2,customChar1);
 lcd.createChar(3,customChar3);                      
  lcd.setCursor(0,1);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.write((byte)3);
}
