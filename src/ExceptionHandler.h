/*
    Handle bulksmszw exceptions returned for post request
*/

#ifndef ExceptionHandler_h
#define ExceptionHandler_h

#include <ArduinoJson>

class ExceptionHandler
{
    private:
        void checkError();
        String error_message;
        int error_code;
        long timestamp;
        String smslog_id;
        String recp;

        String http_resp;

    public:
        ExceptionHandler(String resp);
        String error_message();
        int error_code();
        long timestamp_();
        String sms_log();
        String recipient();
};

#endif