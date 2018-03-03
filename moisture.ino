int   moisture;
int   sensorSoil;

int   f_moisture(int sensorSoil)
{
  int   soilVal;
  long  moisture;
  int   i;
  long   res;

  soilVal = 0;
  moisture = 0;
  i = 0;
  res = 0;
  while (i < 10000)
  {
    soilVal = analogRead(sensorSoil);
    res = map(soilVal, 0, 1023, 255, 0);
    moisture = moisture + res;
    i++;
  }
  moisture = moisture / 10000;
  return (moisture);
}

void  setup(void)
{
  Serial.begin(9600);
  sensorSoil = A0;
  moisture = 0;
}

void  loop(void)
{
  moisture = f_moisture(sensorSoil);
  Serial.print("moisture = ");
  Serial.print(moisture);
  Serial.print("\n");
  //delay(1000);
}
