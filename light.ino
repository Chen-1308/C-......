//定义引脚
const int blueLED = 9;
const int greenLED = 10;
const int redLED = 11;

//电位器输入引脚
int potPin = A0;

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = map(potValue,0,1023,0,255);

  if(potValue < 20){
    analogWrite(blueLED,0);
    analogWrite(greenLED,0);
    analogWrite(redLED,0); 
    Serial.println("LEDs OFF - 旋钮处于关闭位置");
  }
  else{
  analogWrite(blueLED,brightness);
  analogWrite(greenLED,100);
  analogWrite(redLED,200);
  delay(300);

  analogWrite(blueLED,88);
  analogWrite(greenLED,brightness);
  analogWrite(redLED,99);
  delay(300);

  analogWrite(blueLED,44);
  analogWrite(greenLED,66);
  analogWrite(redLED,brightness);
  delay(300);

   Serial.print("旋钮值: "); // 串口输出当前旋钮值[7](@ref)
    Serial.println(potValue);
  }
}
