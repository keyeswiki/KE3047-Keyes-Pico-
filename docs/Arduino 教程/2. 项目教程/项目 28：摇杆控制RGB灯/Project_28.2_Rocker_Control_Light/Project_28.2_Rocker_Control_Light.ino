//**********************************************************************************
/*  
 * 文件名 : 摇杆控制RGB
 * 描述 : 摇杆控制RGB亮不同颜色的光.
 * 作者 : www.keyes-robot.com
*/
int xyzPins[] = {27, 26, 28};   //x,y,z 引脚
int ledPins[] = {18, 17, 16};    //定义红，绿，蓝led引脚
void setup() {
  pinMode(xyzPins[0], INPUT); //x 轴. 
  pinMode(xyzPins[1], INPUT); //y 轴. 
  pinMode(xyzPins[2], INPUT_PULLUP);   //z 轴是一个按钮.
  for (int i = 0; i < 3; i++) {   //设置pwm通道,1KHz,8bit
    pinMode(ledPins[i], OUTPUT);
  }
}

// 在loop()中，使用analogRead()读取X轴和Y轴的值，使用digitalRead()读取Z轴的值，然后显示它们.
void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  if (xVal < 200){
     analogWrite(ledPins[0], 255); //共阴极LED，高电平点亮LED.
     analogWrite(ledPins[1], 0);
     analogWrite(ledPins[2], 0);
   }
  else if (xVal > 800){
     analogWrite(ledPins[0], 0); 
     analogWrite(ledPins[1], 255);
     analogWrite(ledPins[2], 0);
   }
  else if (yVal < 200){
     analogWrite(ledPins[0], 0); 
     analogWrite(ledPins[1], 0);
     analogWrite(ledPins[2], 255);
   }
  else if (yVal > 800){
     analogWrite(ledPins[0], 255); 
     analogWrite(ledPins[1], 255);
     analogWrite(ledPins[2], 255);
   }
}
//**********************************************************************************
