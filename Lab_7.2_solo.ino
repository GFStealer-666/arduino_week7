
//#define BLYNK_TEMPLATE_ID "TMPLENiWR3X9"
//#define BLYNK_DEVICE_NAME "Supapon Quickstart Template"
//#define BLYNK_AUTH_TOKEN "UaVXsZNtzaFljyeXV-cJ52oEKgxQ5oJ9"
//
//#define BLYNK_TEMPLATE_ID "TMPLMAaYpiUk"
//#define BLYNK_DEVICE_NAME "SiripatsayaQuickstart Template"
//#define BLYNK_AUTH_TOKEN "e8w_d629E_9kVBSTpgpJECXnAdlesMhM"

#define BLYNK_TEMPLATE_ID "TMPLW6KvHQY_"
#define BLYNK_DEVICE_NAME "BlinkYears3"
#define BLYNK_AUTH_TOKEN "WrlqJJWkOhR_sFp2W2STg5THHc6zZhtv"

#define ADCPin A0
int ADCValue;
#define PWM_ML D1
#define in1_ML D2
#define in2_ML D3
#define in1_MR D4
#define in2_MR D5
#define PWM_MR D6
#define IRsensorL D7
#define IRsensorR D8
int Speed = 850;
int LsensorValue,RsensorValue;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "WrlqJJWkOhR_sFp2W2STg5THHc6zZhtv";
char ssid[] = "TOT_2.4 G";
char pass[] = "024967892";


void setup(){
  pinMode(PWM_ML, OUTPUT);
  pinMode(in1_ML , OUTPUT);
  pinMode(in2_ML , OUTPUT);
  pinMode(PWM_MR , OUTPUT);
  pinMode(in1_MR , OUTPUT);
  pinMode(in2_MR , OUTPUT);
  pinMode(IRsensorL , INPUT);
  pinMode(IRsensorR , INPUT);  

}

void loop(){

  LsensorValue = digitalRead(IRsensorL);
  RsensorValue = digitalRead(IRsensorR);
  if(LsensorValue ==1 && RsensorValue ==0){
    TurnLeft();
  }
  else if(LsensorValue ==0 && RsensorValue ==1){
    TurnRight();
  }
   else if(LsensorValue ==0 && RsensorValue ==0){
    ForWard();
  }
  else{
    Stop();
  }
  
}

void ForWard()
{
  //เดินหน้า
  //สั้งให้มอเตอร์ขวา เดินหน้า
  digitalWrite(in1_ML, HIGH);
  digitalWrite(in2_ML ,LOW);
  analogWrite(PWM_ML, Speed);
  //สั่งให้มอเตอร์ซ้าย เดินหน้า
  digitalWrite(in1_MR, HIGH);
  digitalWrite(in2_MR, LOW);
  analogWrite(PWM_MR, Speed);
}
void TurnLeft()
{
  //หมุนซ้าย
  //สั่งให้มอเตอร์ขวา เดินหน้า
  digitalWrite(in1_ML, LOW);
  digitalWrite(in2_ML, HIGH);
  analogWrite(PWM_ML, Speed);
  //สั่งให้มอเตอร์ซ้าย ถอยหลัง
  digitalWrite(in1_MR, HIGH);
  digitalWrite(in2_MR, LOW);
  analogWrite(PWM_MR, Speed);
}
void TurnRight()
{
  //หมุนขวา
  //สั่งให้มอเตอร์ขวา ถอยหลัง
  digitalWrite(in1_ML , HIGH);
  digitalWrite(in2_ML , LOW);
  analogWrite(PWM_ML, Speed);
  //สั้งให้มอเตอร์ซ้าย เดินหน้า
  digitalWrite(in1_MR, LOW);
  digitalWrite(in2_MR, HIGH);
  analogWrite(PWM_MR , Speed); 
}
void Stop()
{
  //สั่งให้มอเตอร์ตัวที่ 1 หยุด
  digitalWrite(in1_ML, LOW);
  digitalWrite(in2_ML , LOW);
  analogWrite(PWM_ML, 0);
  //สั้งให้มอเตอร์ตัวที่ 2 หยุด
  digitalWrite(in1_MR, LOW);
  digitalWrite(in2_MR, LOW);
  analogWrite(PWM_MR , 0);
}
