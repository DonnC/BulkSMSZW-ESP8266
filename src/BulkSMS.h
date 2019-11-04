/*
 *  BulkSMS.h - Library for bulk sms zw api
 *  Port for python 3 library
 *  Available at https://github.com/DonnC
 *  Connect to bulksms zw getaway and sent a text message
 *  Created by Donald Chinhuru, November 01, 2019
 *
*/

#ifndef BulkSMS_h
#define BulkSMS_h

#include <Arduino.h>
#include <Client.h>
#include <ESP8266HTTPClient>

// include Parse library
#include "Parse.h"
#include "ExceptionHandler.h"

#define BULKSMS_WEBSERVICE_URL  "http://portal.bulksmsweb.com/index.php?app=ws"
#define BULKSMS_WEBSERVICE_PORT 80
#define SEND_SMS_OPERATION      "pv"
#define SMS_CREDIT_OPERATION    "cr"

class BulkSMS
{
    public:
        BulkSMS(String, String);
        String send(String message_body, String contacts_list, bool ret_credits = true);
        String report();
        String status();                       // successful operation flag                                                 // return detailed report in case of error returned
        String resp();      // return message response
        int err_code();     // return error code

    private:
        //Client *client;
        HTTPClient http;
        int HTTP_RET_CODE;
        String phone_book;
        String user_name;                           // bulksms user name
        String web_token;                           // user token for auth
        String data;
        const char* response;
        String stat;

        // utils
        String _text_operation();
        String _credit();
        void _send_req(String, String);

        // misc
        void handleRecipients(String);                    // format phone numbers
        void handleErrors();                        // handle bulksms api errors


};

#endif

/*
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient

  String ADCData, station, postData;
  int adcvalue=analogRead(A0);  //Read Analog value of LDR
  ADCData = String(adcvalue);   //String to interger conversion
  station = "A";

  //Post Data
  postData = "status=" + ADCData + "&station=" + station ;

  http.begin("http://192.168.43.128/c4yforum/postdemo.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  http.end();  //Close connection

  delay(5000);  //Post Data at every 5 seconds
}
*/