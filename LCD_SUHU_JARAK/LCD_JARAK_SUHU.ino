#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#include <OneWire.h>

#define echopin 12 
#define trig 11
#define ONE 7

long duration, jarak;

OneWire onewire(ONE);
 DallasTemperature sensor(&onewire);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 sensor.begin();
 pinMode(trig, OUTPUT);
 pinMode(echopin, INPUT);

  //setting up lcd
 lcd.init();
 lcd.backlight();
 lcd.setBacklight(HIGH);
 lcd.setCursor(0,0);
 lcd.print("starting");
 delay(300);
 lcd.print(".");
 delay(200);
 lcd.print(".");
 delay(200);
 lcd.print(".");
 delay(500);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("welcome");
 lcd.setCursor(0,1);
 lcd.print("mettikodeva");
 delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensor.requestTemperatures();
 float suhu = sensor.getTempCByIndex(00);
 
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
  lcd.setCursor(0,0);
if ( jarak < 300 )
{
  Serial.print("jaraknya :");
  Serial.print(jarak);
  Serial.println("cm");
  lcd.print("jarak : ");
  lcd.print(jarak);
  lcd.print("cm");
  
}
lcd.setCursor(0,1);
lcd.print("suhu : ");
lcd.print(suhu);
lcd.print("^C");

delay(500);
lcd.clear();
}
