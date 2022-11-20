int echo = 12;
int trig = 13;
long echo_lu;
long dist = 20; 
int motor1pin1 = 14;
int motor1pin2 = 15;
int motor2pin1 = 16;
int motor2pin2 = 17;
int ir1 = 8;
int ir2 = 9;
int ir3 = 10;
int ir1val;
int ir2val;
int ir3val;







void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  echo_lu = pulseIn(echo, HIGH);
  /* dist = (echo_lu / 2) * 0.0343; */
  ir1val = digitalRead(ir1);
  ir2val = digitalRead(ir2);
  ir3val = digitalRead(ir3);
  Serial.print(ir1val);
  Serial.print("\t");
  Serial.print(ir2val);
  Serial.print("\t");
  Serial.print(ir3val);
  Serial.print("\t");
  Serial.print("\n");
  delay(10);
  if(ir2val == 1){
      avancer();
    }
    else{
      if(ir1val == 1){
        gauche();
      }
      else{
        if(ir3val == 1){
          droite();
        }
        else{
         arret();
        }
      }
    }
 /* if (dist > 10){
    if(ir2val == 1){
      avancer();
    }
    else{
      if(ir1val == 1){
        gauche();
      }
      else{
        if(ir3val == 1){
          droite();
        }
        else{
         arret();
        }
      }
    }
    
    
    
  }
  else {
    arret();
    delay(5000);
    droite();
    delay(5000);
    gauche();
    delay(5000);
    gauche();
    delay(5000);
    droite();
    delay(5000);
    avancer();
  }*/

}

void gauche(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void droite(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void arret(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  }

void avancer(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  }
