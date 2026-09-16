#define BLYNK_TEMPLATE_ID           "TMPL5peFswYsL"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "l1aa5TlYQvkI_-RuCO3-JoWhc40tC0Mj"
char ssid[] = "Bakir 2019";
char pass[] = "18bakir_349";


#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define relay1 0
#define relay2 16

unsigned long DELAY = 1000; 
unsigned long timer =0;
int state = 0;
bool relay1State = false;
bool relay2State = false;

bool delay_ms(unsigned long DELAY);


void setup() {

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();



  digitalWrite(relay1,relay1State);
  Blynk.virtualWrite(V0,relay1State);

  digitalWrite(relay2,relay2State);
  Blynk.virtualWrite(V1,relay2State);

  Blynk.virtualWrite(V2,DELAY);
}

BLYNK_WRITE(V0){
  relay1State = param.asInt();
}

BLYNK_WRITE(V1){
  relay2State = param.asInt();
}

BLYNK_WRITE(V2){
  DELAY = param.asInt();
}

BLYNK_WRITE(V4){
  state = param.asInt();
}

bool delay_ms(unsigned long u32_delay){
  if(u32_delay<1000){
    u32_delay=1000;
  }
  if(millis()-timer >=u32_delay){
    timer=millis();
    return true;
  }
  else{
    return false;
  }
}
