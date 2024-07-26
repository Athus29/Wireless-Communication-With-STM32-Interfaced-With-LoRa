void setup() 
{
  pinMode(PC13, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  Serial.println("Hello!");
}
