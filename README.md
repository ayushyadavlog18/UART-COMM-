This project establishes a UART-based communication between an Arduino and a PC. The Arduino monitors and controls an LED connected to pin 13 based on signals received from the PC. Additionally, the Arduino sends the LED status back to the PC, along with the byte transmission speed in bytes per second (Bps).

Functionality

The PC sends a signal via serial communication:

Sending 'A' → Turns LED ON (Pin 13 HIGH)

Sending 'B' → Turns LED OFF (Pin 13 LOW)

The Arduino responds by sending back:

LED status (ON or OFF)

Byte transmission speed

Circuit Setup

Arduino Pin 13 → LED (+ resistor if needed)

GND → LED GND

USB connection → Used for UART communication with the PC

Communication Protocol

Baud Rate: 2400 baud


PC → Arduino:

'A' → Turn LED ON

'B' → Turn LED OFF

Arduino → PC:

"Byte Speed: X Bps" → Displays byte reception speed

"LED Status: ON" / "LED Status: OFF" → Reports LED status
