/*
    * This project is not affiliated by the official BulkSms Zimbabwe services
    * The Company has no library for Embedded devices for IoT projects
    * It is provided free of charge to anyone who finds it useful.
    * It is distributed under Open Source

*/

#include "BulkSMS.h"

BulkSMS::BulkSMS(String name, String token, Client &client)
{
  this.user_name = name;
  this.web_token = token;
  this->client   = &client;
}

String BulkSMS::_text_operation()
{
  // return url with username and token for 'text' operation only
  // TODO Handle unprovided username and token and return an error
  String text_op_details = "";
  text_op_details += "&u=" + this.user_name;
  text_op_details += "&h=" + this.web_token;
  text_op_details += "&op=" + SEND_SMS_OPERATION;

  String web_service_url = BULKSMS_WEBSERVICE_URL + text_op_details;

  return web_service_url;
}

String BulkSMS::_credit()
{
  // return url for credit retrieval
  // TODO Handle unprovided username and token and return an error
  String text_op_details = "";
  text_op_details += "&u=" + this.user_name;
  text_op_details += "&h=" + this.web_token;
  text_op_details += "&op=" + SMS_CREDIT_OPERATION;

  String web_service_url = BULKSMS_WEBSERVICE_URL + text_op_details;

  return web_service_url;
}

void BulkSMS::_send_req(String text, String operation)
{
  // parse and quote payload and do http req
  Parse parse(operation, text, this.phone_book);
  String url = parse.url();

  // do post request
}

String BulkSMS::send(String message_body, String contacts_list, bool ret_credits = true)
{
  // TODO: Schedule message to send at a specific time, YYYY-MM-DD hh:mm:ss
  // TODO: Handle max characters to send - 160

  this.handleRecipients(contacts_list);

  if(ret_credits)
  {
    // retrieve number of credits left per each 'send' request
    this._send_req(message_body, this._credit());
  }

  else
  {
    // send text only
    this._send_req(message_body, this._text_operation());
  }

}

void BulkSMS::handleErrors()
{
  // handle json errors returned
  int ret = 0;
}

void BulkSMS::handleRecipients(String recipients)
{
  // TODO Add working with arrays of phone-numbers
  // TODO Add working with SPIFFS files [ File I/O ] to get phone-numbers saved from file
  // TODO: Validate phone number formats

  // comma seperated list of numbers. "263778xxxxxx, 26371xxxxxxx, #devteam"
  this.phone_book = recipients;
}

String BulkSMS::report()
{
  // generate report of errors and error codes text
  return "report";
}