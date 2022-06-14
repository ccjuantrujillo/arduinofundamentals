#include <ESP8266WiFi.h>                        

const char* ssid = "SA-AP150CECCOS";
const char* password = "Mar.Tru123";

void setup()
{
  Serial.begin(9600);                         
  delay(10);
  
  // Connect to WiFi network
  Serial.println();
  Serial.print("Conectando");
  Serial.println(ssid);

  // Inicio la conexión a la red WiFi
  WiFi.begin(ssid, password);   

  while (WiFi.status() != WL_CONNECTED)         
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Conectado, dirección IP: ");   
  Serial.println(WiFi.localIP());              
}

void loop() {}
