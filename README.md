### Using a [SCT-013-030 30A/1V](https://www.ptrobotics.com/sensor-de-corrente/2144-non-invasive-ac-current-sensor-30a.html) with an
ADS1115 to measure AC Current
- The SCT already has an internal 62 Ohm burden resistor - calibration value is supposed to be 30
- Coil has 1800 turns (1800:1 ratio)
- [Datasheet]( https://www.arduino.cc/documents/datasheets/E000020_Non-invasiveAC%20currentSensor30A.pdf)

Theory and schematics:
- Followed this one: https://www.poweruc.pl/blogs/news/non-invasive-sensor-yhdc-sct013-000-ct-used-with-arduino-sct-013
- https://learn.openenergymonitor.org/electricity-monitoring/ct-sensors/interface-with-arduino

Code example:
https://openenergymonitor.org/forum-archive/node/11221.html

Instructions:
- Connect the ADS1115 to th Uno, I2C pins, plus 5v power and ground;
- Connect the SCT jack tip to the A0 on the ADS and the SCT sleeve to A1;

Note:
On the 3.5 Male jack, the base near the wire is called "sleeve", then there are 1 or 2 middle connector, and the last connector at the end is the "tip".

### Build (using [PlatformIO](https://github.com/platformio/platformio-core))

- Install PlatformIO
- Update port in platformio.ini (check devices with: `pio device list`)
- Upload to device and monitor with: `pio run -t upload -t monitor`

