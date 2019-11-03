#include "Parse.h"

Parse::Parse(String api_operation, String msg_body, String numbers)
{
    this.contacts = numbers;
    this.body     = msg_body;
    this.web_url  = api_operation;
}

String Parse::_body()
{
    return QUOTE(this.body);
}

String Parse::url()
{
    // return 'quoted' or parsed payload url
    return this.web_url + this._payload();
}

String Parse::_recipients()
{
    return QUOTE(this.contacts);
}

String Parse::_payload()
{
    // return web payload
    String url_payload = "";
    url_payload += "&to=" + this._recipients();
    url_payload += "&msg=" + this._body();

    return url_payload;
}

unsigned char Parse::QUOTE_INT(char c_)
{
    if (c_ >= '0' && c_ <= '9')
    {
        return((unsigned char)c_ - '0');
    }

    if (c_ >= 'a' && c_ <= 'f')
    {
        return((unsigned char)c_ - 'a' + 10);
    }

    if (c_ >= 'A' && c_ <= 'F')
    {
        return((unsigned char)c_ - 'A' + 10);
    }

    return(0);
}

String Parse::QUOTE(String str)
{
    // 'quote' given 'str' body
    String encodedString = "";
    char c;
    char code0;
    char code1;

    for (int i = 0; i < str.length(); i++)
    {
        c = str.charAt(i);

      if (c == '+')
      {
        encodedString += ' ';
      }

      else if (c == '%')
      {
        i++;
        code0 = str.charAt(i);
        i++;

        code1 = str.charAt(i);

        c = (QUOTE_INT(code0) << 4) | QUOTE_INT(code1);

        encodedString += c;
      }

      else
      {

        encodedString+=c;
      }

      yield();
    }

   return encodedString;
}