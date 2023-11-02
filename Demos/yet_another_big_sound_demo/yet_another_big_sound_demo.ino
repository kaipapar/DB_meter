#define LED_BUILTIN 2
// Declaration and initialization of input pins
int Analog_Input = 1; // Analog output of the sensor
int Digital_Input = 3; // Digital output of the sensor
int Led_Output = 4;
const int sampleWindow =50;
unsigned int sample;

void setup  ( )
{
  pinMode (Analog_Input, INPUT);
  pinMode (Digital_Input, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Led_Output, OUTPUT);
       
  Serial.begin (115200) ;  //  Serial output with 9600 bps
}
  
//  The program reads the current values of the input pins
// and outputs it on the serial output
void loop  ( )
{
  float  Analog;
  float Analog_as_voltage;
  int Digital;

  unsigned long startMillis = millis();                  
  float peakToPeak = 0;                                  
  unsigned int signalMax = 0;                            
  unsigned int signalMin = 1024;                  
    //Current values are read out, converted to the voltage value...
  Analog =  analogRead (Analog_Input);//   *  (5.0 / 1023.0); 
  Analog_as_voltage = Analog *  (3.3 / 1023.0);
  Digital = digitalRead (Digital_Input);   

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(Analog_Input);
    if (sample < 1024)                                  
    {
      if (sample > signalMax)
      {
       signalMax = sample;
      }
      else if (sample < signalMin)
      {
        signalMin = sample;                           
      }
    }
  }  
  peakToPeak = signalMax - signalMin;         
  int db = map(peakToPeak, 0, 900, 49, 90);         
  Serial.print("sig min");Serial.print(signalMin);
  Serial.print("sig max"); Serial.print(signalMax);
  Serial.print("Current analog sample: "); Serial.print(Analog);
  //...  and issued at this point
  Serial.print  ("Analog voltage value:");  Serial.print (Analog_as_voltage,  4) ;   Serial.print  ("V, ");
  Serial.print("DB: "); Serial.print(db,1);  
  Serial.print ("Limit value:");

  if  (Digital == 1) 
  {
      Serial.println ("reached");
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(Led_Output, HIGH);

  }
  else
  {
      Serial.println (" not yet reached");
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(Led_Output, LOW);

  }
  Serial.println  ( " ----------------------------------------------------------------") ;
  delay (200) ;
}