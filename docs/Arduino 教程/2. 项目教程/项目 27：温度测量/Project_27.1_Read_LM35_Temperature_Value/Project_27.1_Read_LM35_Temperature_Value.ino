//**********************************************************************************
/*  
 * 文件名 : 读取LM35温度值
 * 描述 : 将ADC值转换为LM35温度值
 * 作者 : www.keyes-robot.com
*/
#define PIN_ANALOG_IN  26  //温度传感器的引脚

void setup() {
  Serial.begin(115200);
}

//在loop()函数中，调用analogRead来获取ADC0的ADC值，并将其赋给adcVal. 
//通过公式计算测量的电压值，摄氏度和华氏温度值，并通过串口监视器打印这些数据.
void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  double voltage = adcVal / 1023.0 * 3.3;
  float temperatureC = (voltage * 1000.0) / 10.0 ;
  float temperatureF = (temperatureC * 1.8) + 32.0;
  Serial.print("ADC Value: " + String(adcVal));
  Serial.print("---Voltage Value: " + String(voltage) + "V");
  Serial.print("---temperatureC: " + String(temperatureC) + "℃");
  Serial.println("---temperatureF: " + String(temperatureF) + "F");
  delay(500);
}
//**********************************************************************************
