#include "radio.h"

Radio::Radio(uint16_t cepin, uint16_t cspin) :
    mRadio(cepin, cspin)
{
}

Radio::~Radio()
{
}

void Radio::Setup(Print& print)
{
    print.print(F("RADIO_SETUP..."));
    mRadio.begin();
    mRadio.setPALevel(RF24_PA_MAX);
    mRadio.setAutoAck(1);
    mRadio.setRetries(15, 15);
    mRadio.openReadingPipe(0, RFAddress[0]);
    mRadio.startListening();
    // wait until initialized
    delay(1000);
    

    //mRadio.printDetails();
    print.println(F("COMPLETE"));
}

void Radio::Read(void * buf, uint8_t len)
{
    mRadio.read(buf, len);
}

bool Radio::Available()
{
    return mRadio.available();
}
