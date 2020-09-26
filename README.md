# Teensy_GSM_Shield
Using the Arduino GSM Shield with a Teensy

This is a PlatformIO project with the "library" included.
You include the GSM_Shield.h and .cpp in your own project.
The main.cpp serves as an example sketch.

A separat login.h is recommended to not store private passwords etc. in the same file.

The login.h in this example is called "hidden.h" and is not pushed to GitHub.
Its contents (I modified them here of corse. Adapting should be relatively easy) are:

    #include <Arduino.h>

    String pin="1234";
    String address="pinternet.interkom.de";
    String ip="123.456.789.12";
    String port="1234";

    char connect[]={0x10, 0x23, 0x00, 0x06, 0x4D, 0x51, 0x49, 0x73, 0x64, 0x70, 0x03, 0xC2, 0x00, 0x3C, 0x00, 0x06, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x00, 0x04, 0x63, 0xA1, 0xB8, 0x6F, 0x00, 0x07, 0x3E, 0xC2, 0x21, 0x11, 0xFF, 0x2D, 0x5A};
    int con_len = 37;

    char publish[]={0x30, 0x0B, 0x00, 0x04, 0x74, 0x65, 0x73, 0x74, 0x68, 0x65, 0x6C, 0x6C, 0x6F};
    int pub_len = 13;