/*#######
   Test Hbridge motors read-write
   use one PWM pin for enable and A -B pins for direction of motors
*/

//Define Pins

const int Dig_M1a = 13;
const int Dig_M1b = 12;
const int Dig_M1e = 11;

const int Dig_M2a = 8;
const int Dig_M2b = 7;
const int Dig_M2e = 6;

int analogV1  = 0;
int analogV2  = 0;

byte pwmV1  = 0 ;
byte pwmV2  = 0;

//Initialization
void setup() {
  // put your setup code here, to run once:
  pinMode(Dig_M1a, OUTPUT);
  pinMode(Dig_M1b, OUTPUT);
  pinMode(Dig_M1e, OUTPUT);

  pinMode(Dig_M2a, OUTPUT);
  pinMode(Dig_M2b, OUTPUT);
  pinMode(Dig_M2e, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Dig_M1a, LOW);
  digitalWrite(Dig_M1b, HIGH);
  pwmV1 = 100;
  //Move Motor
  digitalWrite(Dig_M2a, LOW);
  digitalWrite(Dig_M2b, HIGH);
  pwmV2 = 100;

  analogWrite(Dig_M1e, pwmV1);
  analogWrite(Dig_M2e, pwmV2);
  
}
