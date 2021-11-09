#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

#define VOLTAGE 230

Adafruit_ADS1115 ads;
const float FACTOR = 30; //30A/1V
//const float multiplier = 0.0625F; // for GAIN_TWO
const float multiplier = 0.03125F; // for GAIN_FOUR

/// Alternative method without ADS
// #include "EmonLib.h" //SCT-013-030 30A/1V
// EnergyMonitor emon1;
// #define PIN A0
// #define MIN_AMP_THRESHOLD 0.03d

void setup() {
    Serial.begin(115200);

    /// Alternative method without ADS
    /// fixed 30 for SCT-013-030 30A/1V, has an internal 62 Ohm resistor - 1800/62 = 29.0
    // emon1.current(PIN, 30);

    ads.setGain(GAIN_FOUR);
    ads.begin();
}

float getCurrent() {
    float voltage;
    float current;
    float sum = 0;
    long time = millis();
    int counter = 0;

    while (millis() - time < 500) {
        voltage = ads.readADC_Differential_0_1() * multiplier;
        current = voltage * FACTOR;
        current /= 1000.0;

        sum += sq(current);
        counter = counter + 1;
    }

    current = sqrt(sum / counter);
    return current;
}

void loop() {
    /// Alternative method without ADS
    //  double currentRMS = emon1.calcIrms(1480);
    //  if(currentRMS <= MIN_AMP_THRESHOLD){
    //    currentRMS = 0;
    //  }

    float currentRMS = getCurrent();
    float powerWatts = currentRMS * VOLTAGE;

    char buf[100];
    Serial.println(buf);

    ///NOTE: printf with floats requires "build_flags = -Wl,-u,vfprintf -lprintf_flt -lm" in platformio.ini
    sprintf(buf, "Current RMS: %.5f A - Power: %.2f Watts", currentRMS, powerWatts);
}
