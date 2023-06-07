#define BLYNK_TEMPLATE_ID "TMPL35tP6Egmf"
#define BLYNK_TEMPLATE_NAME "RAJESH"
#define BLYNK_AUTH_TOKEN "9Y1GzEQts26anAluWLazdHpRCN5v4JI6"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <dht11.h>
dht11 DHT11;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ESPServer_RAJ";
char pass[] = "RAJ@12345";

BlynkTimer timer;
int t,h;
int LED1=D3;
int LED2=D4;
BLYNK_WRITE(V0)
{
  int LED_VAL = param.asInt(); // assigning incoming value from pin V1 to a variable
  if(LED_VAL==HIGH)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    delay(10);
    }
   else
   {
     digitalWrite(LED1,LOW);
     digitalWrite(LED2,LOW);
     delay(10); 
    }
    
}

void READ_SENSOR()
{
  int chk = DHT11.read();
  t=DHT11.temperature;
  h=DHT11.humidity;

   Blynk.virtualWrite(V2, t);
   Blynk.virtualWrite(V1, h);

   }

void setup()
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(100);
  DHT11.attach(D2);
  Blynk.begin(auth, ssid, pass);
  delay(1000);
  timer.setInterval(1000L, READ_SENSOR);
}

void loop() {
  Blynk.run();
  timer.run();
}
