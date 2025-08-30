

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ITO = analogRead(A0);
  int pwm = map (ITO, 0, 1023, 0, 100);

  Serial.print("Value Analog : ");
  Serial.println(ITO);
  Serial.print("Value PWM : ");
  Serial.println(pwm);

  analogWrite(5, 0);
  analogWrite(4, 0);
  analogWrite(3, 0);
  
  if(pwm >= 0 && pwm <= 33){
    analogWrite(5, 255);
  } else if (pwm >= 34 && pwm <= 66){
    analogWrite(5, 255);
    analogWrite(4, 255);
  }else if (pwm >= 67 && pwm <= 99){
    analogWrite(5, 255);
    analogWrite(4, 255);
    analogWrite(3, 255);
  } else if (pwm == 100){
    analogWrite(5, 0);
    analogWrite(4, 0);
    analogWrite(3, 0);
    delay(500);
    analogWrite(5, 255);
    analogWrite(4, 255);
    analogWrite(3, 255);
  }
  
  delay(500);
}
