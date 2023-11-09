#define LED_BUILTIN 2

//Libraries in use:
//For LCD display:
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Declaration and initialization of input pins
int Analog_Input = 1; // Analog output of the sensor
int Digital_Input = 3; // Digital output of the sensor
float input_voltage = 3.3;
int LedG_Output = 42;
int LedY_Output = 41;
int LedR_Output = 40;
const int sampleWindow = 50;
unsigned int sample;
unsigned int counter = 0;                  
const int max_loops = 10; 

// Set the LCD I2C address and size (16 characters and 2 lines)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Setup the pins to use
void setup  ( )
{
  pinMode (Analog_Input, INPUT);
  pinMode (Digital_Input, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LedG_Output, OUTPUT);
  pinMode(LedY_Output, OUTPUT);
  pinMode(LedR_Output, OUTPUT);
  digitalWrite(LedG_Output, LOW);
  digitalWrite(LedY_Output, LOW);
  digitalWrite(LedR_Output, LOW);
       
  Serial.begin (115200);
  Serial.print("sig min: ");Serial.print("sig max: ");Serial.print("A_sample: ");Serial.print("A_vol: ");Serial.print("DB: ");
  Serial.print("\n");

  // Initialize the LCD display
  lcd.init();
  // Turn on the LCD backlight.
  lcd.backlight();
  // Print a message to the LCD.
  lcd.print("Hello, World!");
}
  
//  The program reads the current values of the input pins
// and outputs it on the serial output
void loop  ( )
{
  float Analog;
  float Analog_as_voltage;
  int Digital;
  unsigned long startMillis = millis();                  
  float peakToPeak = 0;                                  
  unsigned int signalMax = 0;                            
  unsigned int signalMin = 1024;
  
  //Current values are read out, converted to the voltage value...
  Analog =  analogRead(Analog_Input);
  Analog_as_voltage = Analog * (input_voltage / 1023.0);
  Digital = digitalRead(Digital_Input);   

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow){
    sample = analogRead(Analog_Input);
    if (sample < 1024){
      if (sample > signalMax){
       signalMax = sample;
      }
      else if (sample < signalMin){
        signalMin = sample;                           
      }
    }
  }  
  peakToPeak = signalMax - signalMin;         
  int db = map(peakToPeak, 0, 900, 49, 90);         
  Serial.print(signalMin); Serial.print("\t");
  Serial.print(signalMax); Serial.print("\t");
  Serial.print(Analog); Serial.print("\t");
  Serial.print(Analog_as_voltage, 4); Serial.print("\t"); 
  Serial.print(db,1); // output in decimal
  Serial.print("\n");

  //LCD screen functions
  lcd.setCursor(0, 1); // Set the cursor to the second line
  lcd.print("Noise(dB): ");
  lcd.print(db); // Assuming 'soundSensorValue' is a variable holding the sensor reading
}
  
  // What we need for matlab
  
  
  /*
  Serial.print ("Limit value:");
  if  (Digital == 1) {
      Serial.println ("reached");
      digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
      Serial.println (" not yet reached");
      digitalWrite(LED_BUILTIN, LOW);
  }*/

  /* For degubbing leds
  digitalWrite(LedG_Output, LOW);
  digitalWrite(LedY_Output, LOW);
  digitalWrite(LedR_Output, LOW);
  delay(50);
  digitalWrite(LedG_Output, 1);
  digitalWrite(LedY_Output, 1);
  digitalWrite(LedR_Output, 1);*/

  //Serial.println  ( " ----------------------------------------------------------------") ;

  if (db <= 50) {
    digitalWrite(LedG_Output, HIGH);
    digitalWrite(LedY_Output, LOW);
    digitalWrite(LedR_Output, LOW);
    //Serial.println("It is quiet");
  }
  else if (db > 55 && db < 65) {
    digitalWrite(LedG_Output, LOW);
    digitalWrite(LedY_Output, HIGH);
    digitalWrite(LedR_Output, LOW);
    //Serial.println("It is NOT quiet");
  }
  else if (db >= 65 && db <= 90) {
    digitalWrite(LedG_Output, LOW);
    digitalWrite(LedY_Output, LOW);
    digitalWrite(LedR_Output, HIGH);
    //Serial.println("It is loud");
  }
  else {
    digitalWrite(LedG_Output, LOW);
    digitalWrite(LedY_Output, LOW);
    digitalWrite(LedR_Output, LOW);
    //Serial.println("No sound detected");
  }
  //write(db);
  //delay (200);
  /*
  counter++;
  if (counter >= max_loops){
    Serial.println("break");
  }*/
  delay(100);
}
/*
// write the data 
void write(int data_point)
{
  FILE *filePointer = NULL;
  filePointer = fopen("sound_data.csv", "a"); //a for appending data
  if (filePointer == NULL){
    filePointer = fopen("sound_data.csv", "w");
    if (filePointer == NULL){
        Serial.println("Failed to create file");
        exit(1);
    } else {
        Serial.println("New file created");
    }
  }
  fprintf(filePointer, "%d,\n", data_point);
  fclose(filePointer);
}*/