#define enA 9
#define inR1 6
#define enB 10
#define inL1 5

#define centerIR A1
#define leftIR A2
#define rightIR A0

int left = 0;
int right = 0;
int center = 0;
int l_thres = 29;
int r_thres = 30;
int c_thres = 300;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(inR1, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(inL1, OUTPUT);
  
  pinMode(centerIR, INPUT);
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  // Set initial rotation direction
  digitalWrite(inR1, LOW);
  digitalWrite(inL1, LOW);
  
  Serial.begin(9600);  //  setup serial
}
void loop() {
  //analogWrite(enA, 100); // Send PWM signal to L298N Enable pin
  //analogWrite(enB, 100); // Send PWM signal to L298N Enable pin
  
  //digitalWrite(inR1, HIGH);
  //digitalWrite(inL1, HIGH);
  
while(1){
  //line=analogRead(centerIR);
  left=analogRead(leftIR);
  right=analogRead(rightIR);
  center=analogRead(centerIR);

  Serial.println("Left");
  Serial.println(left);
  Serial.println("right");
  Serial.println(right);
  Serial.println("center");
  Serial.println(center);
  
  if(left>=l_thres) //turn left
  {
    Serial.println("Turn left");
    
    Serial.println(left);
    analogWrite(enA, 100); // Send PWM signal to L298N Enable pin  
    digitalWrite(inR1, HIGH);
  }
  else if(right>=r_thres) //turn right
  {
    Serial.println(right);
    Serial.println("Turn Right");
    analogWrite(enB, 100); // Send PWM signal to L298N Enable pin
    digitalWrite(inL1, HIGH);
  }
  else //if(center>c_thres) //move forward
  {
    Serial.println("Move Forward");
    analogWrite(enA, 100); // Send PWM signal to L298N Enable pin
    analogWrite(enB, 100); // Send PWM signal to L298N Enable pin
    digitalWrite(inR1, HIGH);
    digitalWrite(inL1, HIGH);
  }
  delay (500);
}
  
}
