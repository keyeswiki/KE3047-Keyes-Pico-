//**********************************************************************************
/*  
 * 文件名 : 读取热敏电阻模拟值
 * 描述 : 用热敏电阻制作温度计.
 * 作者 : www.keyes-robot.com
*/
#define PIN_ADC1   27
void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(PIN_ADC1);                            // 读ADC引脚
  double voltage = (float)adcValue / 1023.0 * 3.3;                // 计算电压
  double Rt = 10 * voltage / (3.3 - voltage);                     //计算热敏电阻的电阻值
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0); //计算温度(开尔文)
  double tempC = tempK - 273.15;                                  //计算温度(摄氏度)
  Serial.println("Voltage: " + String(voltage) + "V,\t\t" + "Kelvins: " + String(tempK) + "K,\t" + "Temperature: " + String(tempC) + "C");
  delay(1000);
}
//**********************************************************************************
