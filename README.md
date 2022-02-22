# usb-volume-knob
code for usb volume knob

Software required:
- [Python](https://www.python.org/)
- [Pypi (pip)](https://pypi.org/)
  - [PySerial](https://pypi.org/project/pyserial/)
  - [PySimpleGui](https://pypi.org/project/PySimpleGUI/)
- [Arduino Ide](https://arduino.cc)
  - [HID Project](https://github.com/NicoHood/HID)


## Wiring Diagram
| Arduino | Rotary Encode | Led |
| ------- | ------------- | --- |
| A2      | CLK           |     |
| A1      | DT            |     |
| A0      | SW            |     |
| VCC     | VCC (+)       | VCC with a resistor (the longer pin or the smallest pin inside the led ) |
| GND     | GND           |     |
| A3      |               | GND (the shortest pin or the biggest pin inside the led) |
|||![image](https://user-images.githubusercontent.com/81868987/155099249-4fea0d48-6955-454e-9554-9f0bc0aed553.png)|

### Compiled software 
If you don't have python installed you can get the exe in the [releases](https://github.com/shervain123/usb-volume-knob/releases) section in github
Windows will say it contains virus because I don't have the software certificate
It is fine to run it, I use the compile version everyday.


