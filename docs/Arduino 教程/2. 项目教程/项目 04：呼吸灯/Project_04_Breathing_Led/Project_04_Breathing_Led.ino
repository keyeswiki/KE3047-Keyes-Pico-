//**********************************************************************
/*
 * 文件名 : 呼吸灯
 * 描述 : 让led灯像呼吸一样忽隐忽现.
 * 作者 : www.keyes-robot.com
*/
#define PIN_LED   16   //定义led引脚

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) { //使LED逐渐点亮
    analogWrite(PIN_LED, i);
    delay(5);
  }
  for (int i = 255; i > -1; i--) {  //使LED逐渐熄灭
    analogWrite(PIN_LED, i);
    delay(5);
  }
}
//*************************************************************************************
