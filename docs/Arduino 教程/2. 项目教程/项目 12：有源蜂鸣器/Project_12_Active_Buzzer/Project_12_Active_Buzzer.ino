//**********************************************************************
/* 
 * 文件名 : 有源蜂鸣器
 * 描述 : 有源蜂鸣器发出滴滴声.
 * 作者 : www.keyes-robot.com
*/
#define buzzerPin  16   //蜂鸣器引脚定义

void setup ()
{
  pinMode (buzzerPin, OUTPUT);
}
void loop ()
{
  digitalWrite (buzzerPin, HIGH);
  delay (500);
  digitalWrite (buzzerPin, LOW);
  delay (500);
}
//**********************************************************************************
