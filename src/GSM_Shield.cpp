#include <GSM_Shield.h>
#include <Stream.h>
#include <Arduino.h>

/*
* TODO list:
* - test functions
*   - init
*   - reset
*   - enterpin
*   - enterapn
* - wait for ok on enterpin
* - wait for cell ready on enterpin
* - wait for ok on enterapn
*/

/*
Create the tranceiver object
*/
GSM_Shield::GSM_Shield(Stream *s, uint8_t PIN_CTRL) {

	// serial port for communication with the module
	_s = s;

	// digital control pin connecting the module
	_PIN_CTRL = PIN_CTRL;
}

/*
Initialize the board by setting the pin to output and resetting the module
*/
void GSM_Shield::Init() {
    pinMode(_PIN_CTRL, OUTPUT);
    Reset();
}

/*
Reset the module
*/
void GSM_Shield::Reset() {
  digitalWrite(_PIN_CTRL, HIGH);
  delay(12000);
  digitalWrite(_PIN_CTRL, LOW);
  delay(1000);
}

/*
Enter the pin for the sim card
*/
bool GSM_Shield::EnterPin(String pin) {
    _s->print("AT+CPIN=");
    _s->println(pin);
    
    // wait for ok
    // wait for cell ready
    return 0; // no error
}

/*
Enter provider information
*/
bool GSM_Shield::EnterAPN(String address, String user, String password) {
    _s->print("AT+QIREGAPP=");

    _s->print("\"");
    _s->print(address);
    _s->print("\",");

    _s->print("\"");
    _s->print(user);
    _s->print("\",");
    
    _s->print("\"");
    _s->print(password);
    _s->println("\"");

    // wait for ok
    return 0; // no error
}

/*
Availability of the serial interface
Returns true if at least 1 byte is available
*/
bool GSM_Shield::available() {
	return _s->available();
}

/*
Wait for all data in the serial buffer to be transmitted
*/
void GSM_Shield::flush() {
	_s->flush();
}
