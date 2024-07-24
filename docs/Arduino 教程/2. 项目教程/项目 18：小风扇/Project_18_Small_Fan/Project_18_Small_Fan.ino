//**********************************************************************************
/*
 * 文件名 : 小风扇
 * 描述 : 风机顺时针旋转，停止，逆时针旋转，停止，循环.
 * 作者  : www.keyes-robot.com
*/
#define Motorla    17  // 定义电机的Motor_IN+引脚
#define Motorlb     16  // 定义电机的Motor_IN-引脚

void setup(){
  pinMode(Motorla, OUTPUT);//设置Motorla为OUTPUT
  pinMode(Motorlb, OUTPUT);//将Motorlb设置为OUTPUT
}
void loop(){
//设置逆时针旋转5秒
  digitalWrite(Motorla,HIGH);
  digitalWrite(Motorlb,LOW);
  delay(5000);
//设置停止旋转2秒 
  digitalWrite(Motorla,LOW);
  digitalWrite(Motorlb,LOW);
  delay(2000);
//设置顺时针旋转5秒
  digitalWrite(Motorla,LOW);
  digitalWrite(Motorlb,HIGH);
  delay(5000);
//设置停止旋转2秒 
  digitalWrite(Motorla,LOW);
  digitalWrite(Motorlb,LOW);
  delay(2000);
}
//********************************************************************************
