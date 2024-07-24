//**********************************************************************
/* 
 * 文件名 : 防窃警报器
 * 文件名 : 人体红外传感器,蜂鸣器和LED模拟防盗报警.
 * 作者 : www.keyes-robot.com
*/
#define buzzerPin   19   // 蜂鸣器的引脚
#define ledPin   22     // LED的引脚
#define pirPin   2     // 人体红外传感器的引脚
byte pirStat = 0;   // 人体红外传感器的状态
void setup() {
 pinMode(buzzerPin, OUTPUT); 
 pinMode(ledPin, OUTPUT);    
 pinMode(pirPin, INPUT);     
}
void loop()
{
 pirStat = digitalRead(pirPin); 
 if (pirStat == HIGH)
 {            // 如果发现有人或动物移动
   digitalWrite(buzzerPin, HIGH);  // 蜂鸣器蜂鸣
   digitalWrite(ledPin, HIGH);  // led灯点亮
   delay(500);
   digitalWrite(buzzerPin, LOW);  // 蜂鸣器不响
   digitalWrite(ledPin, LOW);  // led熄灭
   delay(500);
 } 
 else {
   digitalWrite(buzzerPin, LOW); // 如果没有发现人或动物在移动，关闭蜂鸣器
   digitalWrite(ledPin, LOW);  // led熄灭
 }
}
//*********************************************************************************
