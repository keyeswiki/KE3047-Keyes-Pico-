//**********************************************************************************
/*  
 * 文件名  : 温度测量
 * 描述 : 当LM35感应到不同的温度时，不同的led会发光
 * 作者  : www.keyes-robot.com
*/
#define PIN_ADC2       26      //LM35传感器的引脚
#define PIN_GREENLED   22      // 绿色led的引脚
#define PIN_YELLOWLED  21      //黄色led的引脚
#define PIN_REDLED     19      //红色led的引脚
void setup() {
  Serial.begin(115200);
  pinMode(PIN_GREENLED, OUTPUT); //设置PIN_GREENLED为输出
  pinMode(PIN_YELLOWLED, OUTPUT);//设置pin_yellow为输出
  pinMode(PIN_REDLED, OUTPUT);//设置PIN_REDLED为输出
  pinMode(PIN_ADC2, INPUT);//设置PIN_ADC2为输入
}

void loop() {
  int adcVal = analogRead(PIN_ADC2);
  double voltage = adcVal / 1023.0 * 3.3;
  float temperatureC = (voltage * 1000.0) / 10.0 ;
  float temperatureF = (temperatureC * 1.8) + 32.0;
  Serial.print("ADC Value: " + String(adcVal));
  Serial.print("---Voltage Value: " + String(voltage) + "V");
  Serial.print("---temperatureC: " + String(temperatureC) + "℃");
  Serial.println("---temperatureF: " + String(temperatureF) + "F");
  if (temperatureF >= 95) {
    digitalWrite(PIN_GREENLED, LOW);
    digitalWrite(PIN_YELLOWLED, LOW);
    digitalWrite(PIN_REDLED, HIGH);
  }
  else if (temperatureF >= 90 && temperatureF < 95) {
    digitalWrite(PIN_GREENLED, LOW);
    digitalWrite(PIN_YELLOWLED, HIGH);
    digitalWrite(PIN_REDLED, LOW);
  }
  else {
    digitalWrite(PIN_GREENLED, HIGH);
    digitalWrite(PIN_YELLOWLED, LOW);
    digitalWrite(PIN_REDLED, LOW);
  }

  delay(500);
}
//**********************************************************************************
