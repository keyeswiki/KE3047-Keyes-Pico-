//**********************************************************************************
/*  
 * 文件名 : 人体感应灯
 * 描述 : 采用光敏传感器和人体红外传感器控制LED.
 * 作者 : www.keyes-robot.com
*/
#define PIN_ADC0  26   //光敏传感器的引脚
#define PIN_LED1   16  // 外接LED的引脚
#define PIN_LED2   25  // Pico板上内置LED的引脚
#define pirPin   2     // 人体红外传感器的引脚
byte pirStat = 0;   // 人体红外传感器的状态
void setup() {
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_ADC0, INPUT);
  pinMode(pirPin, INPUT);
}

void loop() {
  int adcVal = analogRead(PIN_ADC0); //读取光敏传感器的ADC值
  pirStat = digitalRead(pirPin); //读取人体红外传感器的值
  if (adcVal >= 500) {
      digitalWrite(PIN_LED2, HIGH); //点亮Pico板上的内置LED 
      if (pirStat == HIGH){
         digitalWrite(PIN_LED1, HIGH);//点亮外接LED
         } 
      else{
         digitalWrite(PIN_LED1, LOW);//熄灭外接LED灯   
        }
  }
   else{
      digitalWrite(PIN_LED1, LOW);//熄灭外接LED灯
      digitalWrite(PIN_LED2, LOW);//熄灭Pico板上的内置LED
      }
}
//**********************************************************************************
