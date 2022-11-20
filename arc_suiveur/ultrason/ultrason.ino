//MOTOR1 PINS
int ena = 10;
int in1 = 9;
int in2 = 8;

int in3 = 7;
int in4 = 6;
int enb = 5;

int a;
int b;
int c;
int d;
int e;
int f;

void setup() 
{
  // put your setup code here, to run once:
  // Motors
 pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // IR sensors
  // 0 i/p for white
  // 1 i/p for black
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(1, INPUT);
}

void loop()
{
  read_ir();
  // any intersection where left turn is possible

  if (a == 1 && b == 1 && c == 1 && d == 1)
  {
    sharp_turn_left();
  }
  // intersection where left turn is impossible
  else if (a == 0 && b == 0 && c == 1 && d == 1 && e == 1 && f == 1)
  {
    // go a little forward to check whether forward or right
    forward(100);
    delay(1000);
    read_ir();
    // if forward is possible, then go forward
    if (c == 1 && d == 1)
    {
      forward(100);
    }
    // otherwise take right turn
    else
    {
      right(100);
      delay(1000);
    }
  }
  // reached dead end, take U-turn
  else if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
  {
    u_turn();
  }
  // otherwise follow straight or curved path using proportional control
  else
  {
    motor_p_control();  
  }
}

void read_ir()
{
  // read IR input
  a = digitalRead(13);
  b = digitalRead(12);
  c = digitalRead(11);
  d = digitalRead(3);
  e = digitalRead(2);
  f = digitalRead(1);
}

void left(int spd)
{
  digitalWrite(in1, 0);
  digitalWrite(in2, spd);
  analogWrite(ena, 55);
  digitalWrite(in3, spd);
  digitalWrite(in4, 0);
  analogWrite(enb, 55);
}

void right(int spd)
{
 digitalWrite(in1, spd);
  digitalWrite(in2, 0);
  analogWrite(ena, 55);
  digitalWrite(in3, 0);
  digitalWrite(in4, spd);
  analogWrite(enb, 55);
}

void forward(int spd)
{
  digitalWrite(in1, spd);
  digitalWrite(in2, 0);
  analogWrite(ena, 100);
  digitalWrite(in3, spd);
  digitalWrite(in4, 0);
  analogWrite(enb, 100);
}

void stop_motors()
{
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void motor_p_control()
{
  read_ir();
  // calculate proportional control error using weights as typed
  long int err = (-4 * a) + (-3 * b) + (3 * e) + (4 * f);

  // if err is positive, means line is under right side sensors
  if (err > 0)
  {
    // map and constrain the error to a range of 0 to 255
    // so that it can be applied to motor
    err = map(err, 0, 8, 0, 100);
    err = constrain(err, 0, 100);
    // go left
  digitalWrite(in1, err);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  }
  // if negative, line under left side sensors
  else if (err < 0)
  {
    // map and constrain the error to a range of 0 to 255
    // so that it can be applied to motor
    err = -err;
    err = map(err, 0, 8, 0, 100);
    err = constrain(err, 0, 100);
    // go right
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, err);
  digitalWrite(in4, 0);
  }
  // if zero, line is under central sensors
  else if (err == 0)
  {
    // go straight
  digitalWrite(in1, 100);
  digitalWrite(in2, 0);
  analogWrite(ena, 100);
  digitalWrite(in3, 100);
  digitalWrite(in4, 0);
  analogWrite(enb, 100);
  }
}

void sharp_turn_left()
{
  forward(100);
  delay(600);
  left(100);
  delay(600);
}

void sharp_turn_right()
{
  forward(100);
  delay(600);
  right(100);
  delay(700);
}

void u_turn()
{
  forward(100);
  delay(800);
  while (a == 0)
  {
    left(80);
    read_ir();
  }
  delay(1100);
}
