/*
    ExceptionHandler.cpp
    Implementation file
*/

#include "ExceptionHandler.h"

ExceptionHandler::ExceptionHandler(String resp)
{
    // parse response message given
    this.http_resp = resp;
    this.checkError();
}

void ExceptionHandler::checkError()
{
    // check errors encoded json
    const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + 130;
    DynamicJsonDocument doc(capacity);

    deserializeJson(doc, this.http_resp);

    if(doc["error_string"])
    {
        // we have an err message
        this.error_code    = doc["error"];
        this.error_message = doc["error_string"];
    }

    else
    {
        JsonObject data_0  = doc["data"][0];
        this.error_message = data_0["status"];
        this.smslog_id     = data_0["smslog_id"];
        this.recp          = data_0["to"];
    }

    this.timestamp     = doc["timestamp"];
}

int ExceptionHandler::error_code()
{
    return this.error_code;
}

String ExceptionHandler::error_message()
{
    return this.error_message;
}

long ExceptionHandler::timestamp_()
{
    return this.timestamp;
}

String ExceptionHandler::sms_log()
{
    return this.smslog_id;
}

String ExceptionHandler::recipient()
{
    return this.recp;
}