//**********************************************************************************
/*  
 * 文件名  : 温度仪表
 * 描述 : LCD 显示热敏电阻的温度.
 * 作者 : www.keyes-robot.com
*/
#include "lcd128_32_io.h"

#define PIN_ADC1  27

lcd lcd(20, 21); //创建 lCD128 *32 引脚，sda->20， scl->21

void setup()  {
  lcd.Init(); //初始化
  lcd.Clear();  //清除
}
char string[10];

void loop() {
  int adcValue = analogRead(PIN_ADC1);                            //读ADC引脚
  double voltage = (float)adcValue / 1023.0 * 3.3;                //计算电压
  double Rt = 10 * voltage / (3.3 - voltage);                     //计算热敏电阻的电阻值
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0); //计算温度(开尔文)
  double tempC = tempK - 273.15;                                  //计算温度(摄氏度)
  lcd.Cursor(0,0); //设置显示位置
  lcd.Display("Voltage:"); //设置显示参数
  lcd.Cursor(0,8);
  lcd.DisplayNum(voltage);
  lcd.Cursor(0,11);
  lcd.Display("V");
  lcd.Cursor(2,0); 
  lcd.Display("tempC:");
  lcd.Cursor(2,8);
  lcd.DisplayNum(tempC);
  lcd.Cursor(2,11);
  lcd.Display("C");
  delay(200);
}
//**********************************************************************************
