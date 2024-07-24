//**********************************************************************
/*
 * 文件名 : 温湿度仪表
 * 描述 : LCD显示温度值和湿度值.
 * 作者  : www.keyes-robot.com
*/
//在使用dht11之前，我们需要包含一个头文件. 
//申请一个DHT对象，定义控制DHT的引脚为GPIO22.
#include <dht.h>
dht DHT;
#define DHT11_PIN 22
//LCD128*32的库文件和lCD128*32的引脚
#include "lcd128_32_io.h"
lcd lcd(20, 21); //创建lCD128*32引脚，sda->20， scl->21

void setup(){
  lcd.Init(); //初始化
  lcd.Clear();  //清除
}
char string[10];

//LCD显示湿度值和温度值
void loop(){
  int chk = DHT.read11(DHT11_PIN);//Read11()用于读取DHT11数据，并将返回值赋给变量chk.
  lcd.Cursor(0,0); //设置显示位置
  lcd.Display("Temper:"); //设置显示参数
  lcd.Cursor(0,8);
  lcd.DisplayNum(DHT.temperature);
  lcd.Cursor(0,11);
  lcd.Display("C");
  lcd.Cursor(2,0); 
  lcd.Display("humid:");
  lcd.Cursor(2,8);
  lcd.DisplayNum(DHT.humidity);
  lcd.Cursor(2,11);
  lcd.Display("%");
  delay(200);
}
//********************************************************************************
