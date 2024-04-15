// Include the necessary libraries
#include <IRremote.h>
#include <LiquidCrystal.h>

// Define pins for the LCD
#define LCD_RS_PIN A5
#define LCD_E_PIN A4
#define LCD_D4_PIN 6
#define LCD_D5_PIN 7
#define LCD_D6_PIN 8
#define LCD_D7_PIN 9

// Define pins for the LEDs
#define LED_1_PIN 12 // Red
#define LED_2_PIN 11 // Yellow
#define LED_3_PIN 10 // Green

// Define the IR receiver pin
#define IR_RECEIVE_PIN 5

// Define the IR remote button codes
#define IR_BUTTON_0 12
#define IR_BUTTON_1 16
#define IR_BUTTON_2 17
#define IR_BUTTON_3 18
#define IR_BUTTON_4 22
#define IR_BUTTON_FUNC_STOP 2

// Define the size of the LED array
#define LED_ARRAY_SIZE 3

// Initialize arrays to hold the LED pins and their states
byte LEDArray[LED_ARRAY_SIZE] = {LED_1_PIN, LED_2_PIN, LED_3_PIN};
byte LEDStateArray[LED_ARRAY_SIZE] = {LOW, LOW, LOW};

// Initialize the LCD display with the specified pins
LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

// Function to initialize LED modes to LOW (off)
void initLEDModes(){
  for(int i=0; i<LED_ARRAY_SIZE;i++){
    LEDStateArray[i] = LOW;
    digitalWrite(LEDArray[i], LOW);
  }
}

// Function to turn off all LEDs
void powerOffAllLEDs(){
  for(int i=0; i<LED_ARRAY_SIZE; i++){
    LEDStateArray[i] = LOW;
    digitalWrite(LEDArray[i],LOW);
  }
}

// Function to toggle the state of an LED given its index
void toggleLEDFromIndex(int index){
  if(index >= LED_ARRAY_SIZE){
    return;
  }
  if(LEDStateArray[index] == HIGH){
    LEDStateArray[index] = LOW;
  }else{
    LEDStateArray[index] = HIGH;
  }
  digitalWrite(LEDArray[index], LEDStateArray[index]);
}

// Function to print the command received from the IR remote to the LCD
void printCommandOnLCD(int command){
  lcd.setCursor(0,0);
  lcd.print(command);
  lcd.print("      "); // Clear the rest of the line
}

// Function to print the action performed to the LCD
void printActionOnLCD(String action){
  lcd.setCursor(0,1);
  lcd.print(action);
}

// Setup function to initialize the serial monitor, IR receiver, LED modes, and LCD
void setup(){
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN);
  initLEDModes();
  lcd.begin(16,2);
}

// Main loop to handle IR remote commands
void loop() {
  if(IrReceiver.decode()){
    // Print the raw and command data to the serial monitor
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.println(IrReceiver.decodedIRData.command);
    
    int command = IrReceiver.decodedIRData.command;
    
    // Switch case to handle different button presses
    switch(command){
      case IR_BUTTON_0: {
        powerOffAllLEDs();
        printCommandOnLCD(command);
        printActionOnLCD("Power Off LEDs. ");
        break;
      }
      case IR_BUTTON_1:{
        toggleLEDFromIndex(0);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 1    ");
        break;
      }
      case IR_BUTTON_2:{
        toggleLEDFromIndex(1);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 2    ");
        break;
      }
      case IR_BUTTON_3:{
        toggleLEDFromIndex(2);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 3    ");
        break;
      }
      case IR_BUTTON_4:{
        // Sequence of toggling all LEDs in order and then toggling them off
        toggleLEDFromIndex(0);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 1    ");
        delay(100);
        toggleLEDFromIndex(1);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 2    ");
        delay(100);
        toggleLEDFromIndex(2);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 3    ");
        delay(100);
        toggleLEDFromIndex(0);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 1    ");
        delay(100);
        toggleLEDFromIndex(1);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 2    ");
        delay(100);
        toggleLEDFromIndex(2);
        printCommandOnLCD(command);
        printActionOnLCD("Toggle LED 3    ");
        delay(100);
        break;
      }
      case IR_BUTTON_FUNC_STOP:{
        // Special case to turn off all LEDs
        powerOffAllLEDs();
      }
    }
    
    // Prepare the IR receiver for the next command
    IrReceiver.resume();
  }
}
