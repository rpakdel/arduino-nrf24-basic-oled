#pragma once

#include <Arduino.h>
#include <RF24.h>

static byte RFAddress[][6] = { "1Door" };

class Radio
{
public:
    Radio(uint16_t _cepin, uint16_t _cspin);
    ~Radio();

    void Setup(Print& print);
    void Read(void* buf, uint8_t len);
    bool Available();

private:
    RF24 mRadio;
};
