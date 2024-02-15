int green =2;
int yellow =3;
int red = 4;


void setup() {
 pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
 pinMode(red,OUTPUT);

}

void loop() {
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
  delay(10000);
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(red,LOW);
  delay(3000);
  digitalWrite(green,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
  delay(15000);

}
