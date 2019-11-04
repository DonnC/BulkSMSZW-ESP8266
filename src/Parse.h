/*
    * Parse contacts
    * Parse message body provided
    * URL encode message
    * Created by Donald Chinhuru, Nov 2019
*/

#ifndef Parse_h
#define Parse_h

#include <Arduino.h>

class Parse
{
    private:
        String body;
        String contacts;
        String web_url;

        // utilities
        String _body();
        String _recipients();
        String _payload();

        // url encode function
        String QUOTE(String);
        unsigned char QUOTE_INT(char _c);

    public:
        Parse(String api_operation, String msg_body, String numbers);
        String url();

};

#endif