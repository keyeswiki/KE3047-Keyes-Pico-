//**********************************************************************************
/*  
 * 文件名 : 键盘控制门
 * 描述 : 制作一个简单的密码锁.
 * 作者 : www.keyes-robot.com
*/
#include "Keypad.h"
#include <Servo.h>

Servo  myservo;     // 创建舵机对象来控制舵机
int servoPin = 2;   // 定义舵机引脚
int buzzerPin = 0; // 定义蜂鸣器引脚

String passWord = "1234"; // 保存正确的密码
String keyIn; 

void setup() {
  keyInit();
  myservo.attach(servoPin);  // 将舵机在servoPin上安装到舵机对象上
  myservo.write(0);                     // 设定舵机的初始位置
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  keyIn = "";
  Serial.println(keyIn);
}

void loop() {
  char keyPressed = getKey(0);        // 获取字符输入
  if (keyPressed!='\0') {             // 处理输入字符
    digitalWrite(buzzerPin, HIGH);    // 每次按下该键时发出提示音
    delay(200);
    digitalWrite(buzzerPin, LOW);
    keyIn += keyPressed;              // 保存输入字符
    Serial.println(keyPressed);       // 输入后判断正确性
    if (keyIn.length() == 4) {
      bool isRight = true;            // 保存密码是否正确
      if( passWord != keyIn){
        isRight = !true;
      }
      if (isRight) {                  // 输入的密码是否正确
        myservo.attach(servoPin);
        myservo.write(90);            // 舵机旋转到90°
        delay(2000);                  // 延迟一段时间
        myservo.write(0);             // 舵机旋转到0°
        Serial.println("passWord right!");
      }
      else {                          // 输入密码错误
        digitalWrite(buzzerPin, HIGH);// 输入错误密码提示音
        delay(1000);
        digitalWrite(buzzerPin, LOW);
        Serial.println("passWord error!");
      }
      keyIn = ""; // 将输入字符数重置为0
    }
  }
  delay(200);
}
//**********************************************************************************
