/*
    * Created by D Chinhuru
    * send_demo_text.ino
    * Created Nov 2019
    * Demo test for sending a text message using ESP8266 using bulksmsweb service api
*/

#include <ESP8266WiFi.h>
#include <BulkSMS.h>

/* Set these to your desired credentials. */
const char *ssid = "your-wifi-name";
const char *password = "your-wifi-password";

// provide auth details
const char *username  = "your-bulksmsweb-name";
const char *web_token = "your-bulksmsweb-token";

//provide numbers here comma seperated, groups start with '#'
String phone_book = "263773xxxxxx, 263712xxxxxx, #iot";

// create a bulksms object
BulkSMS sms(username, web_token);

void setup() {
  Serial.begin(115200);                     // Serial connection
  WiFi.begin(ssid, password);               // WiFi connection

  while (WiFi.status() != WL_CONNECTED)
  {  // Wait for the WiFI connection completion
    delay(500);
    Serial.println("");
    Serial.print("[INFO] Connecting to ");
    Serial.print(ssid);
    Serial.print(" ..");
    Serial.println("");
  }

  // If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("[INFO] Connected to: ");
  Serial.println(ssid);
  Serial.print("[INFO] IP address: ");
  Serial.println(WiFi.localIP());          //IP address assigned to your ESP
}

void loop()
{
 if(WiFi.status() == WL_CONNECTED){   //Check WiFi connection status
    // send a text message
    String message = "Hello from ESP8266! Demo testing bulksmszw library";

    String resp    = sms.send(message, phone_book);

    // check response
    if(sms.status != "OK")
    {
        Serial.println(sms.report());
    }

    // response message
    Serial.println(resp);
 }

 else
 {
    Serial.println("[ERROR] Error in WiFi connection!");
 }

  delay(2000);  //Send a text message every 2 seconds
}