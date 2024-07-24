//**********************************************************************
/*
 * 文件名 : RGB
 * 描述 : 使用RGBLED显示随机颜色.
 * 作者 : www.keyes-robot.com
*/
int ledPins[] = {18, 17, 16};    //定义红，绿，蓝led引脚
int red, green, blue;
void setup() {
  for (int i = 0; i < 3; i++) {   //设置pwm通道，1KHz,8bit
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  red = random(0, 255);
  green = random(0, 255);
  blue = random(0, 255);
  setColor(red, green, blue);
  delay(1000);
}

void setColor(byte r, byte g, byte b) {
  analogWrite(ledPins[0], 255-r); //共阴极LED，高电平点亮LED.
  analogWrite(ledPins[1], 255-g);
  analogWrite(ledPins[2], 255-b);
}
//*************************************************************************************
