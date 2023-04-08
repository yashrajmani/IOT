#include <LiquidCrystal.h>    // include the library for the LCD display
#define ledPin 9              // define the pin number for the LED
#define buzzerPin 8          // define the pin number for the buzzer
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // initialize the LCD display
#define aqsensor A0

void setup() {
  pinMode(ledPin, OUTPUT);       // set the LED pin as an output
  pinMode(buzzerPin, OUTPUT);    // set the buzzer pin as an output
  lcd.begin(16, 2);              // initialize the LCD display with 16 columns and 2 rows
  digitalWrite(ledPin, HIGH);               // turn on the LED
  lcd.print("Air Quality");      // print "Air Quality" on the first line of the LCD display
  Serial.begin(9600);            // initialize serial communication at 9600 bits per second
}

void loop() {
  //  int sensorValue = analogRead(sensorPin);
  int ppm = analogRead(aqsensor);

  lcd.setCursor(0, 1);                        // set the cursor to the second line of the LCD display
  lcd.print("PPM: ");                         // print "PPM: " on the LCD display
  lcd.print(ppm);                             // print the ppm value on the LCD display
  digitalWrite(ledPin, HIGH);               // turn on the LED
  Serial.print("PPM: ");                      // print "PPM: " on the serial monitor
  Serial.println(ppm);                        // print the ppm value on the serial monitor
  if (ppm > 200) {                            // if the ppm is greater than 200
    lcd.print(" - Air Quality Bad");          // print " - Air Quality Bad" on the LCD display
    digitalWrite(ledPin, HIGH);               // turn on the LED
    digitalWrite(buzzerPin, HIGH);            // turn on the buzzer
  } else {                                    // if the ppm is less than or equal to 200
    lcd.print(" - Air Quality Good");         // print " - Air Quality Good" on the LCD display
    digitalWrite(ledPin, LOW);                // turn off the LED
    digitalWrite(buzzerPin, LOW);             // turn off the buzzer
  }
  delay(1000);                                //
}
