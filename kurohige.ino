//最終形態
#include <Servo.h>

Servo servo;

float angle = 90;

int fire_B = 8;
int right_B = 11;
int left_B = 12;

int AIN1 = 5;
int AIN2 = 6;



void rampUpMotor() 
{
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
}
void rampDownMotor()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
}
void stopMotor()
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
}



void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
  servo.write(90);

  pinMode(fire_B, INPUT_PULLUP);

  pinMode(right_B, INPUT_PULLUP);
  pinMode(left_B, INPUT_PULLUP);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);


  pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int fire_value;
  int right_value;
  int left_value;
  fire_value = digitalRead(fire_B);
  right_value = digitalRead(right_B);
  left_value = digitalRead(left_B);

  if (fire_value == LOW)
  {
    digitalWrite(13, HIGH);
    rampUpMotor();
    delay(1000);
    stopMotor();
    delay(100);
    rampDownMotor();
    delay(735);
    digitalWrite(13, LOW);
    stopMotor();
  }

  if (right_value == LOW)
  {
    if (angle >= 50)
    {
      angle = angle - 0.25;
    }
    else
    {
      angle = 50;
    }
    delay(10);
  }
  if (left_value == LOW)
  {
    if (angle <= 120)
    {
      angle = angle + 0.25;
    }
    else 
    {
      angle = 120;
    }
    delay(10);
  }
  
  servo.write(angle);


}
