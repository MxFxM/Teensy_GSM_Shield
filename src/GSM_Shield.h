#include <Arduino.h>

// defines go here
#define PIN_RECOVER 20

class Stream;

class GSM_Shield {

public:
	// constructor
	GSM_Shield(Stream *s, uint8_t PIN_CTRL = 6);

	// initialization
	void Init();

	// reset module
	void Reset();

    // methods
    bool EnterPin(String pin);
    bool EnterAPN(String adress, String user, String password);
	bool ActivateGPRS();
	bool TestIP();
	bool ConnectToServer(String protocol, String ip, String port);
	bool SendBytes(char *data, int length);
	bool DisconnectFromServer();
	
	// set methods

	// serial interface pass through
	bool available();
	void flush();
	
	// get methods

private:
	// variable for the serial stream
	Stream*  _s;
    
    // pin to reset module
    uint8_t _PIN_CTRL;
};

