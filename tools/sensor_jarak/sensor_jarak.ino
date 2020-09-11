#include <LiquidCrystal_I2C.h>

#define echopin 12 
#define trig 11

long duration, jarak;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echopin, INPUT);

  //setting up lcd
 lcd.init();
 lcd.backlight();
 lcd.setBacklight(HIGH);
 lcd.setCursor(0,0);
 lcd.print("mettikodeva");
 lcd.setCursor(1,0);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
duration = pulseIn(echopin, HIGH);
jarak = (duration/56);
  Serial.print("durasi :");
  Serial.println(duration);
  lcd.setCursor(0,1);
if ( jarak < 300 )
{
  Serial.print("jaraknya :");
  Serial.print(jarak);
  Serial.println("cm");
  lcd.print("jarak : ");
  lcd.print(jarak);
  lcd.print("cm");
  
}

delay(500);
lcd.clear();
}
