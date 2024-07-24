//**********************************************************************
/*
 * 文件名 : 外接灯闪烁
 * 描述 : 使led闪烁.
 * 作者 : www.keyes-robot.com
*/
#define PIN_LED   16   //定义led引脚

// 复位或单板上电时，设置功能运行一次
void setup() {
  // 初始化数字引脚LED作为输出.
  pinMode(PIN_LED, OUTPUT);
}

// 循环函数会一直循环下去
void loop() {
  digitalWrite(PIN_LED, HIGH);   // 打开LED (HIGH为高电平)
  delay(500);                       // 延时0.5秒
  digitalWrite(PIN_LED, LOW);    // 关闭LED (LOW为低电平)
  delay(500);                       // 延时0.5秒
}
//*************************************************************************************
