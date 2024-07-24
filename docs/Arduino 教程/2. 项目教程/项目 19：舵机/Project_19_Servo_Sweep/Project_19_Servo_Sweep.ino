//**********************************************************************
/*
 * 文件名 : 舵机
 * 描述 : 控制舵机进行清扫
 * 作者 : www.keyes-robot.com
*/
#include <Servo.h>
#define servoPin 16

Servo myServo;  // 创建舵机对象来控制舵机
int pos = 0;    // 创建变量存储舵机位置

void setup() {
  myServo.attach(servoPin);  // 将舵机连接到GP16引脚上
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // 从0°到180°
    // 以1度为阶
    myServo.write(pos);              // 告诉舵机在变量'pos'的位置
    delay(15);                       // 等待15毫秒舵机到达对应位置
  }
  for (pos = 180; pos >= 0; pos -= 1) { // 从180度到0度
    myServo.write(pos);              // 告诉舵机在变量'pos'的位置
    delay(15);                       // 等待15毫秒舵机到达对应位置
  }
}
//********************************************************************************
