#include <LiquidCrystal.h> // Include the LiquidCrystal library for controlling LCDs.

// Define the pins used for the LCD interface
#define LCD_RS_PIN A5      // Define the LCD register select pin.
#define LCD_E_PIN A4       // Define the LCD enable pin.
#define LCD_D4_PIN 6       // Define the LCD data pin 4.
#define LCD_D5_PIN 7       // Define the LCD data pin 5.
#define LCD_D6_PIN 8       // Define the LCD data pin 6.
#define LCD_D7_PIN 9       // Define the LCD data pin 7.

// Initialize the LiquidCrystal library with the pins defined above
LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

int cursorLine = 0; // Variable to keep track of the current cursor line (0 or 1).

void printUserTextOnDisplay(String text){
  // Validate the text length to ensure it fits on the LCD.
  if(text.length() > 16){
    text = "Text too long"; // Replace text if it is too long.
  }
  // Pad the text with spaces if it is shorter than 16 characters to maintain formatting.
  for(int i = text.length(); i < 16; i++){
    text += " ";
  }
  // Set the cursor to the start of the current line (0 or 1).
  lcd.setCursor(0, cursorLine);
  // Print the text to the LCD.
  lcd.print(text);
  // Toggle cursor line between 0 and 1 for the next message.
  if(cursorLine == 0)
    cursorLine = 1;
  else
    cursorLine = 0;
}
  
void setup() {
  Serial.begin(115200);       // Initialize serial communication at 115200 bits per second.
  Serial.setTimeout(10);      // Set the maximum serial read timeout to 10 milliseconds.
  lcd.begin(16,2);            // Initialize the LCD to be 16 characters wide and 2 lines tall.
}
void loop() {
  // Check if there is any serial input.
  if(Serial.available() > 0){
    String text = Serial.readString(); // Read the string from the serial buffer.
    printUserTextOnDisplay(text);      // Display the text on the LCD.
  }
}
