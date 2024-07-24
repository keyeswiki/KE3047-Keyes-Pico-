from machine import ADC, Pin
import time
# 将电位器初始化到引脚26 (ADC功能)
adc = ADC(26)

# 循环打印电位器的当前adc值 
# 循环打印电位器的电流电压值
try:
    while True:
        adcValue = adc.read_u16() # 读取电位器的ADC值
        voltage = adcValue / 65535.0 * 3.3
        print("ADC Value:", adcValue, "Voltage:", voltage, "V")
        time.sleep(0.1)
except:
    pass