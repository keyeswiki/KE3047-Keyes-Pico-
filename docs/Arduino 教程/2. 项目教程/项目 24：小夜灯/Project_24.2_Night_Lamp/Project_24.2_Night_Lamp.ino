//**********************************************************************************
/*  
 * 文件名 : 小夜灯
 * 描述 : 光敏传感器控制LED的亮度.
 * 作者 : www.keyes-robot.com
*/
#define PIN_ADC0    26  // 光敏传感器的引脚
#define PIN_LED     16  // LED的引脚

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_ADC0, INPUT);
}

void loop() {
  int adcVal = analogRead(PIN_ADC0); //读取光敏传感器的ADC值
  analogWrite(PIN_LED, map(adcVal, 0, 1023, 0, 255));//将ADC映射到PWM占空比来控制LED亮度.
  delay(10);
}
//**********************************************************************************
