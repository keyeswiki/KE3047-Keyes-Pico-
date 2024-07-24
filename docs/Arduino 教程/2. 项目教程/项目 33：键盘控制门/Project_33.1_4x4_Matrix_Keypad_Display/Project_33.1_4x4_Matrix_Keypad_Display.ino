//**********************************************************************************
/*  
 * 文件名 : 4x4矩阵键盘显示 
 * 描述 : 获取矩阵键盘的值
 * 作者 : www.keyes-robot.com
*/
#include "Keypad.h"

void setup(){
  Serial.begin(115200);
  keyInit();
}

void loop(){
  char keyValue = getKey(0);
  if (keyValue != '\0')
    Serial.println(keyValue);
  delay(50);
}
//**********************************************************************************
