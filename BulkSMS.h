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
#include <ArduinoJson.h>

// include Parse library
#include "Parse.h"

#define BULKSMS_WEBSERVICE_URL  "http://portal.bulksmsweb.com/index.php?app=ws"
#define BULKSMS_WEBSERVICE_PORT 80
#define SEND_SMS_OPERATION      "pv"
#define SMS_CREDIT_OPERATION    "cr"
#define STATUS_ERROR            "ERR"

class BulkSMS
{
    public:
        BulkSMS(String, String, Client &client);
        String send(String message_body, String contacts_list, bool ret_credits = true);
        String report();                                                                            // return detailed report in case of error returned

    private:
        Client *client;

        String phone_book;
        String user_name;                           // bulksms user name
        String web_token;                           // user token for auth

        // utils
        String _text_operation();
        String _credit();
        void _send_req(String, String);

        // misc
        void handleRecipients(String);                    // format phone numbers
        void handleErrors();                        // handle bulksms api errors


};

#endif