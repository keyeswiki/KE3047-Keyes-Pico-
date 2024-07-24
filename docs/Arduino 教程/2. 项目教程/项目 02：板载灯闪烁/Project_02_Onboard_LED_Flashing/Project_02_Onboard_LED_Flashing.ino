//**********************************************************************
/*
 * 文件名 : 板载灯闪烁
 * 描述 : 使led闪烁.
 * 作者 : www.keyes-robot.com
*/
#define LED_BUILTIN 25

// 复位或单板上电时，设置功能运行一次
void setup() {
  // 初始化数字引脚LED_BUILTIN作为输出.
  pinMode(LED_BUILTIN, OUTPUT);
}

// 循环函数会一直循环下去
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // 打开LED (HIGH为高电平)
  delay(1000);                       // 延时1秒
  digitalWrite(LED_BUILTIN, LOW);    // 关闭LED(LOW为低电平)
  delay(1000);                       // 延时1秒
}
//*************************************************************************************
