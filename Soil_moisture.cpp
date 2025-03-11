//soil moisture sensor analog pin
 int sensorpin = A0;
//Defining pins connected to RGB LED
 int red = 11;
 int blue = 10;
 int green = 9;
//Defining pin connected to DC Motor
 int motorpin = 13;


 void setup()
 {
 //initializing the RGB LED pin as an output
 pinMode(red, OUTPUT);
 pinMode(blue, OUTPUT);
 pinMode(green, OUTPUT);
  //initializing the DC Motor pin as an output
 pinMode(motorpin, OUTPUT);
  // initializing serial communication at 9600 bits per second
 Serial.begin(9600);
 }

void loop()
 {
 //declaring variables
 float moisture_percentage;
 int sensor_analog;
 //Read analog data from soil moisture sensor
 sensor_analog = analogRead(sensorpin);
 //calculating the moisture %
 moisture_percentage = (sensor_analog/876.00)*100;
 //Printing moisture % in serial monitor
 Serial.print("Moisture Percentage = ");
 Serial.print(moisture_percentage);
 Serial.print("%\n\n");
 //control LED based on moisture %
  if(moisture_percentage >= 70)
  {
   setRGB(0, 0, 500); // Blue Color
   digitalWrite(blue, HIGH);
   digitalWrite(motorpin, LOW);//motor is off
  }
  else if(moisture_percentage >= 30)
  {
   setRGB(0, 500, 0); // Green Color
   digitalWrite(green, HIGH);
   delay(1500); // Wait for 1.5s
   digitalWrite(green, LOW);
   delay(1500); // Wait for 1.5s
   digitalWrite(motorpin, LOW);//motor is off
  }
  else if(moisture_percentage < 30)
  {
   setRGB(500, 0, 0); // Red Color
   digitalWrite(red, HIGH);

delay(500); // Wait for 0.5s
   digitalWrite(red, LOW);
   delay(500); // Wait for 0.5s
  
   if(moisture_percentage < 15)
   {
    digitalWrite(motorpin, HIGH);//motor is on
   }
   else
   {
    digitalWrite(motorpin, LOW);//motor is off
   }
 }
  char state;
  //checking data to read from serial port
  if (Serial.available())
  {
   //reading data
   state = Serial.read();
   if (state == 'y')
   {
    digitalWrite(motorpin, HIGH);//motor is on
   }
   else
   {
    digitalWrite(motorpin, LOW);//motor is off
   }
  }
  
// Delay for 1 second before next iteration
 delay(1000);
}

// Function to set RGB LED color
 void setRGB(int redValue, int greenValue, int blueValue)
{
 analogWrite(red, redValue);
 analogWrite(green, greenValue);
 analogWrite(blue, blueValue);
}
