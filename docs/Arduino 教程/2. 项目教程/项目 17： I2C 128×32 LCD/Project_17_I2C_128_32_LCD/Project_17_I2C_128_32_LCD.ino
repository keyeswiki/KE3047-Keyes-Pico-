//**********************************************************************************
/*
 * 文件名 : LCD 128*32
 * 描述 : LCD 128*32 显示字符串
 * 作者  : www.keyes-robot.com
*/
#include "lcd128_32_io.h"

//创建 lCD128 *32 引脚，sda--->20， scl--->21
lcd lcd(20, 21);

void setup() {
  lcd.Init(); //初始化
  lcd.Clear();  //清除
}

void loop() {
  lcd.Cursor(0, 4); //设置显示位置
  lcd.Display("KEYESTUDIO"); //设置显示参数
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}
//**********************************************************************************
