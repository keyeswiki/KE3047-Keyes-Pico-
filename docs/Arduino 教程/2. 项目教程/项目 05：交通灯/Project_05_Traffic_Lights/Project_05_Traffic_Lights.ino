//**********************************************************************
/*
 * 文件名 : 交通灯
 * 描述 : 模拟交通灯.
 * 作者 : www.keyes-robot.com
*/
#define PIN_LED_RED   16   //定义红色led引脚
#define PIN_LED_YELLOW   17   //定义黄色led引脚
#define PIN_LED_GREEN  18   //定义绿色led引脚

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop() {
digitalWrite(PIN_LED_GREEN, HIGH);// 点亮绿色led
delay(5000);// 延时5秒
digitalWrite(PIN_LED_GREEN, LOW); // 关闭绿色led
for(int i=0;i<3;i++)// 闪烁3次.
{
delay(500);// 延时0.5秒
digitalWrite(PIN_LED_YELLOW, HIGH);// 点亮黄色led灯
delay(500);// 延时0.5秒
digitalWrite(PIN_LED_YELLOW, LOW);// 关闭黄色led灯
} 
delay(500);// 延时0.5秒
digitalWrite(PIN_LED_RED, HIGH);// 点亮红色led灯
delay(5000);// 延时 5 秒
digitalWrite(PIN_LED_RED, LOW);// 关闭红色led灯
}
//*************************************************************************************
