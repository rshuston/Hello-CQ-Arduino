# Hello-CQ-Arduino

This project implements a simple Morse code flasher on an Arduino UNO. It uses the onboard
LED to flash a standard amateur radio "Hello CQ" CW sequence with my call sign, WD8NAQ.

To set up for building and programming the board, use MacPorts or Homebrew to install the
following:
- avr-gcc
- avr-libc
- avrdude

The project makefile assumes that the Arduino UNO connects as `/dev/tty.usbmodem14201`
on macOS. You can define a TTY environment variable specifying a different serial device
connection.

The project in the `testing` subdirectory allows for the testing of the `morse` module.
