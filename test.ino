#define RED 13
#define BLUE 12
#define GREEN 11
#define MOTOR 10
#define TEMPERATURE 0
int r=0, g=0, b=0;

void setup() {
  Serial.begin(9600); 
    pinMode(MOTOR, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
}

void loop() {
  int temp;
  int res;
  temp = analogRead(TEMPERATURE) * 5.0 / 1024.0;
  res =  temp * 100 - 50;
  Serial.println(res); 
  
   if(res>31) { 
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
    analogWrite(RED, 255);
    analogWrite(MOTOR,HIGH);
  } else if(res<=20) { 
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 255);
    analogWrite(RED, 0);
  } else if(res>=21 && res <= 30){ 
    analogWrite(GREEN, 255);
    analogWrite(BLUE, 0);
    analogWrite(RED, 0);
  } 
 
  delay(1000);
}
