#include <dht.h>
#include<LiquidCrystal.h>

#define dht_apin A1 // Analog Pin sensor is connected to
int sensorValue;
dht DHT;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup(){
 lcd.begin(16, 2);
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("CO2 Concentration & Humidity & temperature measurements:\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
  
    sensorValue = analogRead(0);       // read analog input pin 0
    Serial.print("CO2 = ");
    Serial.print(sensorValue+350, DEC);  // prints the value read
    Serial.print(" PPM  ");
    lcd.setCursor(0,0);
    lcd.print("CO2 : ");
    lcd.print(sensorValue+350,DEC);
    lcd.print(" PPM");
    delay(1000);
    lcd.clear();
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature);
     
    Serial.println("C  ");
    
    lcd.setCursor(0,1); 
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    delay(2000);
    lcd.clear();
 
}

