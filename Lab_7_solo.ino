#define BLYNK_TEMPLATE_ID "TMPLW6KvHQY_"
#define BLYNK_DEVICE_NAME "BlinkYears3"
#define BLYNK_AUTH_TOKEN "WrlqJJWkOhR_sFp2W2STg5THHc6zZhtv"

#define ADCPin A0
#define IRsensorL D7
#define IRsensorR D8
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "WrlqJJWkOhR_sFp2W2STg5THHc6zZhtv";
char ssid[] = "TOT_2.4 G";
char pass[] = "024967892";
WidgetLCD lcd(V9);
int LsensorValue,RsensorValue;


void setup(){
  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(IRsensorL , INPUT);
  pinMode(IRsensorR , INPUT);  
}

void loop(){
  Blynk.run();
  LsensorValue = digitalRead(IRsensorL);
  RsensorValue = digitalRead(IRsensorR);
  lcd.print(0,0,"Left : ");
  lcd.print(7,0,LsensorValue);
  lcd.print(0,1,"Right : ");
  lcd.print(8,1,RsensorValue);
  delay(1000);
}
