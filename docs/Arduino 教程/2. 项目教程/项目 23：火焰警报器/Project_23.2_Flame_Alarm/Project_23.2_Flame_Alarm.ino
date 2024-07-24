//**********************************************************************************
/*  
 * 文件名  : 火焰报警器
 * 描述 : 通过火焰传感器控制蜂鸣器和LED.
 * 作者 : www.keyes-robot.com
*/
#define PIN_ADC0      26  //火焰传感器的引脚
#define PIN_LED       16  // LED的引脚
#define PIN_BUZZER    17  // 蜂鸣器的引脚

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_ADC0, INPUT);
}

void loop() {
  int adcVal = analogRead(PIN_ADC0); //读取火焰传感器的ADC值
  if (adcVal >= 500) {
    digitalWrite (PIN_BUZZER, HIGH); //蜂鸣器鸣叫
    digitalWrite(PIN_LED, HIGH); // 点亮LED
    delay(500); // 延时0.5秒.
    digitalWrite(PIN_LED, LOW); // 熄灭 LED
    delay(500); // 延时0.5秒
  }
  else
  {
    digitalWrite(PIN_LED, LOW);  //熄灭LED
    digitalWrite (PIN_BUZZER, LOW); //关闭蜂鸣器
  }
}
//**********************************************************************************
