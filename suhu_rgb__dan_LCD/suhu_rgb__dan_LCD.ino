
#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2

//var
  
  OneWire onewire(ONE_WIRE_BUS);
  DallasTemperature sensor(&onewire);
  

  
// ini alamat I2C dari LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   sensor.begin();
   
  
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
 
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

//mencetak di lcd
  

  
  delay(200);
}

void loop() {
 sensor.requestTemperatures();
 float suhu = sensor.getTempCByIndex(00);

 if (suhu >= 50) {
   digitalWrite(A3, HIGH);
   digitalWrite(A4, LOW);
   digitalWrite(A5, LOW);
   }
 else if ( suhu >= 20 ) {
   digitalWrite(A3, LOW);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
   }
 else {
   digitalWrite(A3, LOW);
   digitalWrite(A4, LOW);
   digitalWrite(A5, HIGH);
 }
  if (suhu > 50.00) {
   Serial.println("panas");
   }
 else if (suhu >=20) {
   Serial.println("sedang");
   }
 else{
   Serial.println("dingin");
   }
   
  lcd.setCursor(0,0);
  lcd.print("Mettikodeva");
  lcd.setCursor(0,1);
  lcd.print("temp : ");
  lcd.print(suhu);
  lcd.print("C");

 Serial.println(suhu);

}
