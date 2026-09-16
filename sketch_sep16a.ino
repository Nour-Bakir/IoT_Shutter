#define BLYNK_TEMPLATE_ID           "TMPL5peFswYsL"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "l1aa5TlYQvkI_-RuCO3-JoWhc40tC0Mj"
char ssid[] = "Bakir 2019";
char pass[] = "18bakir_349";


#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#define K1 0
#define Led 2
#define K2 16
unsigned long DELAY = 1000; 
unsigned long time1 =0;
bool LED = false;
int state = 0;

void setup() {
  Serial.begin(115200);

  
  
  pinMode(Led, OUTPUT);
  pinMode(K1, OUTPUT);
  pinMode(K2, OUTPUT);
  digitalWrite(Led, LOW);
  digitalWrite(K1, HIGH);
  digitalWrite(K2, HIGH);
  
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Blynk.virtualWrite(V4,LOW);
  Blynk.virtualWrite(V0,LOW);
  Blynk.virtualWrite(V1,LOW);
  Blynk.virtualWrite(V2,1000);
}

void loop() {
  Blynk.run();
  if(state==0){
    if(millis() - time1 >= DELAY){
      time1 = millis();
      LED = !LED;
      digitalWrite(K1,LED);
      digitalWrite(K2,!LED);
    }
  }
  else
    digitalWrite(Led,false);
}


BLYNK_WRITE(V0) {
  int value = param.asInt(); 
  if(value==1){
    Blynk.virtualWrite(V1,LOW);
    digitalWrite(K2, !LOW);
    if(state==1){
      digitalWrite(K1, !value);
    }
  }
  else
    digitalWrite(K1, !value);
}

BLYNK_WRITE(V1) {
  int value1 = param.asInt(); 
  if(value1==1){
    Blynk.virtualWrite(V0,LOW);
    digitalWrite(K1, !LOW);
    if(state==1){
      digitalWrite(K2, !value1);
    }
  }
  else
     digitalWrite(K2, !value1);
}

BLYNK_WRITE(V2) {
  DELAY = param.asInt();
}

BLYNK_WRITE(V4) {
  state = param.asInt();
  if(state==1){
    digitalWrite(K1, HIGH);
    digitalWrite(K2, HIGH);
    Blynk.virtualWrite(V0,LOW);
    Blynk.virtualWrite(V1,LOW);
  }
}