#include <BleGamepad.h>


BleGamepad bleGamepad("ESP32 8-Button Controller", "DIY", 100);

// --- PIN DEFINITIONS (8-BUTTON ALL-TOUCH LAYOUT) ---
#define UP_PIN      4   // Labeled D4
#define DOWN_PIN    15  // Labeled D15
#define LEFT_PIN    13  // Labeled D13
#define RIGHT_PIN   12  // Labeled D12

#define A_BUTTON_PIN 33  // Labeled D33
#define B_BUTTON_PIN 32  // Labeled D32
#define X_BUTTON_PIN 2   // Labeled D2
#define Y_BUTTON_PIN 14  // Labeled D14

// --- TOUCH SENSITIVITY (CALIBRATED) ---
const int TOUCH_THRESHOLD = 800; 

void setup() {
  Serial.begin(115200);
  bleGamepad.begin();
  Serial.println("Bluetooth Gamepad Started. Waiting for connections...");
}

void loop() {
  if(bleGamepad.isConnected()) {
    
    // --- D-PAD CONTROL ---
    if(touchRead(UP_PIN) < TOUCH_THRESHOLD) { bleGamepad.setHat(HAT_UP); } 
    else if (touchRead(DOWN_PIN) < TOUCH_THRESHOLD) { bleGamepad.setHat(HAT_DOWN); } 
    else if (touchRead(LEFT_PIN) < TOUCH_THRESHOLD) { bleGamepad.setHat(HAT_LEFT); } 
    else if (touchRead(RIGHT_PIN) < TOUCH_THRESHOLD) { bleGamepad.setHat(HAT_RIGHT); } 
    else { bleGamepad.setHat(HAT_CENTERED); }

    // --- ACTION BUTTONS (A,B,X,Y are Buttons 1,2,3,4) ---
    if(touchRead(A_BUTTON_PIN) < TOUCH_THRESHOLD) { bleGamepad.press(BUTTON_1); } else { bleGamepad.release(BUTTON_1); }
    if(touchRead(B_BUTTON_PIN) < TOUCH_THRESHOLD) { bleGamepad.press(BUTTON_2); } else { bleGamepad.release(BUTTON_2); }
    if(touchRead(X_BUTTON_PIN) < TOUCH_THRESHOLD) { bleGamepad.press(BUTTON_3); } else { bleGamepad.release(BUTTON_3); }
    if(touchRead(Y_BUTTON_PIN) < TOUCH_THRESHOLD) { bleGamepad.press(BUTTON_4); } else { bleGamepad.release(BUTTON_4); }
  }
  delay(10); 
}
