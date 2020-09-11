

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
 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

//mencetak di lcd
  

  
  delay(200);
}

void loop() {
 sensor.requestTemperatures();
 float suhu = sensor.getTempCByIndex(00);

 if (suhu >= 50) {
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
   digitalWrite(10, LOW);
   }
 else if ( suhu >= 20 ) {
   digitalWrite(8, LOW);
   digitalWrite(9, HIGH);
   digitalWrite(10, LOW);
   }
 else {
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
   digitalWrite(10, HIGH);
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
  // PRINT DI LCD
  lcd.setCursor(0,0);
  lcd.print("Mettikodeva");
  lcd.setCursor(0,1);
  lcd.print("temp : ");
  lcd.print(suhu);
  lcd.print("C");

 Serial.println(suhu);

}
