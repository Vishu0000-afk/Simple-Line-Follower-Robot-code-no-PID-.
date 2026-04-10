#define i1 A0
#define i2 A1
#define i3 A2
#define i4 A3
#define i5 A4
#define i6 A5
#define i7 A6
#define i8 A7
#define Ena 5
#define Enb 6
#define In1 3
#define In2 2
#define In3 8
#define In4 7
#define THRESHOLD 900

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(i1,INPUT);
  pinMode(i2,INPUT);
  pinMode(i3,INPUT);
  pinMode(i4,INPUT);
  pinMode(i5,INPUT);
  pinMode(i6,INPUT);
  pinMode(i7,INPUT);
  pinMode(i8,INPUT);
  pinMode(Ena,OUTPUT);
  pinMode(Enb,OUTPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
}

void straight() {
  digitalWrite(In1, 1);
  digitalWrite(In2,0);
  digitalWrite(In3, 1);
  digitalWrite(In4, 0);
  analogWrite(Ena,115);
  analogWrite(Enb, 115);
}

void left() {
  digitalWrite(In1,0);
  digitalWrite(In2, 1);
  digitalWrite(In3,1);
  digitalWrite(In4, 0);
analogWrite(Ena,0);
analogWrite(Enb,85);
}
void right() {
  digitalWrite(In1, 1);
  digitalWrite(In2,0);
  digitalWrite(In3,0);
  digitalWrite(In4, 1);
analogWrite(Ena,85);
analogWrite(Enb,0);
}

void stopMotor() {
  analogWrite(Ena, 0);
  analogWrite(Enb, 0);
}
void white() {
  digitalWrite(In1, 1);
  digitalWrite(In2,0);
  digitalWrite(In3,0);
  digitalWrite(In4, 0);
analogWrite(Ena,55);
analogWrite(Enb,0);

}

int s1, s2, s3, s4, s5, s6, s7, s8;

void readsensors() {
  s1 = analogRead(i1);
  s2 = analogRead(i2);
  s3 = analogRead(i3);
  s4 = analogRead(i4);
  s5 = analogRead(i5);
  s6 = analogRead(i6);
  s7 = analogRead(i7);
  s8 = analogRead(i8);
}
bool ir[8];
void processsensors() {
  ir[0] = (s1 > THRESHOLD);
  ir[1] = (s2 > THRESHOLD);
  ir[2] = (s3 > THRESHOLD);
  ir[3] = (s4 > THRESHOLD);
  ir[4] = (s5 > THRESHOLD);  
  ir[5] = (s6 > THRESHOLD);
  ir[6] = (s7 > THRESHOLD);                                        
  ir[7] = (s8 > THRESHOLD);
}
void loop() {
  // put your main code here, to run repeatedly:
  readsensors();
  processsensors();
  if(ir[3]||ir[4])
  {
    straight();
  }
  else if(ir[0]||ir[1]||ir[2])
  {
    left();
  }
  else if(ir[5]||ir[6]||ir[7])
  {
    right();
  }

  else if(ir[0]>THRESHOLD&&ir[1]>THRESHOLD&&ir[2]>THRESHOLD&&ir[3]>THRESHOLD&&ir[4]>THRESHOLD&&ir[5]>THRESHOLD&&ir[6]>THRESHOLD&&ir[7]>THRESHOLD)
  {
    stopMotor();
  }
}