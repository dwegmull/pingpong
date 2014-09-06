
// Lights
#define GREEN_LIGHT 11
#define ORANGE_LIGHT 10
#define RED_LIGHT 9
// Sensors
#define GREEN_SENSOR 2
#define ORANGE_SENSOR 3
#define RED_SENSOR 4

// Colors
#define GREEN 0
#define ORANGE 1
#define RED 2

int sensors[3] = {GREEN_SENSOR, ORANGE_SENSOR, RED_SENSOR};
int lights[3] = {GREEN_LIGHT, ORANGE_LIGHT, RED_LIGHT};

void setup() 
{
  int i;
  // Setup the pins
  for(i = 0; i < 3; i++)
  {
    pinMode(sensors[i], INPUT_PULLUP);
    digitalWrite(lights[i], 0);
    pinMode(lights[i], OUTPUT);
  }  
}


void signal(int light)
{
  digitalWrite(light, 1);
  delay(3000);
  digitalWrite(light, 0);
}


void loop() 
{
  int i;
  for(i = 0; i < 3; i++)
  {
    if(0 == digitalRead(sensors[i]))
    {
      signal(lights[i]);
    }
  }
}
