//**********************************************************************************
/*  
 * 文件名 : 调光灯
 * 描述 : 利用电位器控制LED的亮度.
 * 作者 : www.keyes-robot.com
*/
#define PIN_ADC0    26  //电位器的引脚
#define PIN_LED     16  // LED的引脚

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_ADC0, INPUT);
}

void loop() {
  int adcVal = analogRead(PIN_ADC0); //读取电位器的ADC值
  analogWrite(PIN_LED, map(adcVal, 0, 1023, 0, 255));//将ADC映射到PWM占空比来控制LED亮度.
  delay(10);
}
//**********************************************************************************
