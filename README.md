##ESP32 Capacitive Touch Gamepad


A custom, 8-button wireless game controller built from scratch using an ESP32, aluminum foil, and scavenged parts, designed to control emulators on an Android phone with a broken screen.

Features
8-Button Layout: D-Pad (Up, Down, Left, Right) and four action buttons (A, B, X, Y).

Wireless Control: Uses Bluetooth HID to connect seamlessly to any Android device as a standard gamepad.

Solder-Free Capacitive Touch: Buttons are made from simple aluminum foil pads that detect touch, requiring no physical switches or soldering.

Ultra-Low-Cost: Built with a "no-buy" philosophy, using scavenged parts and common household materials.

Hardware & Materials
Core: ESP32 DevKit v1

Buttons: Aluminum foil and jumper wires

Chassis: Layered cardboard and a repurposed aluminum foil container

Power: USB Power Bank or a standard USB connection

The Build Story & Challenges
This project was a journey in resourceful DIY electronics. The initial goal was to create a simple controller for a phone with a non-functional touchscreen.

The core of the project is the ESP32's built-in capacitive touch sensors, which allow simple foil pads to act as reliable buttons. The main challenge was not in the software, but in solving the real-world hardware and electrical issues that arose:

"Ghost Touches": The initial build was plagued by phantom button presses. This was a classic hardware problem that was solved by implementing a proper ground plane—a large piece of foil connected to the ESP32's GND pin that the user touches to create a stable electrical reference.

Pin Selection: Early versions of the code used GPIO pins that were not touch-enabled, causing the controller to send a constant stream of junk data. The final design uses 8 carefully selected, labeled, and reliable touch-capable pins.

Sensitivity Calibration: The TOUCH_THRESHOLD was calibrated using the Arduino Serial Monitor to find the perfect value that balanced responsiveness without being too sensitive to noise.

Physical Construction: The chassis was built from layered cardboard for strength, and a physical button connection was made using a simple, solder-free staple method.

This project is a testament to what can be built with minimal resources and a lot of persistence.
