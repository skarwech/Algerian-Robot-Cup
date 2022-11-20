int in1 = 8;
int inval1;
int in2 = 9;
int inval2;
int in3 = 10;
int inval3;



void setup() {
  Serial.begin(9550);
  pinMode(in1,INPUT);
  pinMode(in2,INPUT);
  pinMode(in3,INPUT);
}

void loop() {
  inval1 = digitalRead(in1);
  inval2 = digitalRead(in2);
  inval3 = digitalRead(in3);
  Serial.print(inval1);
  Serial.print("\t");
  Serial.print(inval2);
  Serial.print("\t");
  Serial.print(inval3);
  Serial.print("\t");
  Serial.print("\n");
  delay(1000);
  
}
