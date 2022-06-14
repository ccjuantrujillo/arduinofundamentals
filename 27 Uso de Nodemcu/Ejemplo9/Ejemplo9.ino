/*
    This sketch demonstrates how to scan WiFi networks.
    The API is almost the same as with the WiFi Shield library,
    the most obvious difference being the different file you need to include:
*/

#include "ESP8266WiFi.h"



void setup() {

  Serial.begin(9600);



  // Set WiFi to station mode and disconnect from an AP if it was previously connected

  WiFi.mode(WIFI_STA);

  WiFi.disconnect();

  delay(100);



  Serial.println("Setup done");

}



void loop() {

  Serial.println("scan start");



  // WiFi.scanNetworks will return the number of networks found

  int n = WiFi.scanNetworks(false, true);

  Serial.println("scan done");

  if (n == 0)

    Serial.println("no networks found");

  else

  {

    Serial.print(n);

    Serial.println(" networks found");

    Serial.println("num\tSSID\t\tRSSI\tBSSID\t\tchannel\tencryption");



    for (int i = 0; i < n; ++i)

    {

      // Print SSID and RSSI for each network found

      Serial.print(i + 1);

      Serial.print("\t");

      Serial.print(muestra_SSID(WiFi.SSID(i)));

      Serial.print("\t");

      Serial.print(WiFi.RSSI(i));

      Serial.print("dBm\t");

      Serial.print(WiFi.BSSIDstr(i));

      Serial.print("\t");

      Serial.print(WiFi.channel(i));

      Serial.print("\t");

      Serial.println((muestra_encriptacion(WiFi.encryptionType(i))));



      delay(10);

    }

  }

  Serial.println("");



  // Wait a bit before scanning again

  delay(5000);

}



String muestra_encriptacion (int wifiEncryp) {

  String encriptacion = "";



  switch (wifiEncryp) {

    case ENC_TYPE_WEP:

      encriptacion = "WEP";

      break;

    case ENC_TYPE_TKIP:

      encriptacion = "WPA/PSK";

      break;

    case ENC_TYPE_CCMP:

      encriptacion = "WPA2/PSK";

      break;

    case ENC_TYPE_NONE:

      encriptacion = "open network";

      break;

    case ENC_TYPE_AUTO:

      encriptacion = "WPA/WPA2/PSK";

      break;

  }

  return encriptacion;

}



String muestra_SSID (String SSID_name) {

  int longitud = SSID_name.length();



  if (SSID_name == "")

    return ("Oculto!!!");

  else if (longitud < 9)

    return SSID_name + "\t";

  else

    return SSID_name;
    }
