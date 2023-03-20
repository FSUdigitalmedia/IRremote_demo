# IR Remote Demo

This is a very simple demo that works with the IR receiver breakout board and the IR remote that come with the Elegoo Super Starter Kit for Arduino UNO.

The [library that this demo is based on](https://github.com/Arduino-IRremote/Arduino-IRremote) is capable of most anything related to sending and receiving IR data, but this demo program is pared down (from an example in the library) to be as minimal as possible.

## Installation

Clone this repo and open the folder with PlatformIO.

## Hardware

The IR receiver breakout board has strange labels on its pins. To connect it to the Arduino, make the following connections:

| IR Breakout | Arduino |
| :---------: | :-----: |
|      G      | Ground  |
|      R      |   5V    |
|      Y      |   D2    |
