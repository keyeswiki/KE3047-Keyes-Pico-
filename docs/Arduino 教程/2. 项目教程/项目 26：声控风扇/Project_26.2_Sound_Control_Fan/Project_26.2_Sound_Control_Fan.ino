//**********************************************************************************
/*  
 * 文件名 : 声控风扇
 * 描述 : 通过声音传感器控制风扇.
 * 作者 : www.keyes-robot.com
*/
#define PIN_ADC2   28  //声音传感器的引脚
#define PIN_Motorla    17  // 电机的Motor_IN+引脚
#define PIN_Motorlb    16  // 电机的Motor_IN-引脚
#define PIN_LED    25  // // Pico板上内置LED的引脚

void setup() {
  pinMode(PIN_LED, OUTPUT);//设置PIN_LED为输出
  pinMode(PIN_Motorla, OUTPUT);//设置Motorla为输出
  pinMode(PIN_Motorlb, OUTPUT);//将Motorlb设置为输出
  pinMode(PIN_ADC2, INPUT);//设置PIN_ADC2为输入
}

void loop() {
  int adcVal = analogRead(PIN_ADC2); //读取声音传感器的ADC值
  if (adcVal > 600) {
    digitalWrite(PIN_LED,HIGH); //点亮Pico板上的内置LED
    digitalWrite(PIN_Motorla,HIGH); //旋转
    digitalWrite(PIN_Motorlb,LOW);
    delay(5000); //delay 5S
  }
  else
  {
    digitalWrite(PIN_LED,LOW); //关闭Pico板上的内置LED
    digitalWrite(PIN_Motorla,LOW); //停止转动
    digitalWrite(PIN_Motorlb,LOW); 
  }
}
//**********************************************************************************
