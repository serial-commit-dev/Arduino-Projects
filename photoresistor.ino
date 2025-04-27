int lightLevel;
void setup()
{
   Serial.begin(9600);
}

void loop()
{
 lightLevel=analogRead(A0);
  Serial.print("Lightlevel");
  Serial.println(lightLevel);
  delay(1000);
}  