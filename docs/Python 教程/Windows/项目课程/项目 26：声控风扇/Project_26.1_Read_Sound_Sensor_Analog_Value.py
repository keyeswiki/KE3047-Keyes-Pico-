from machine import ADC, Pin
import time
# 初始化声音传感器引脚28 (ADC功能)
adc = ADC(28)

# 读取声音传感器当前模拟值并返回[0,1023]
def get_value():
    return int(adc.read_u16() * 1024 / 65536)
 
# 循环打印声音传感器的当前模拟值，量程=[0, 1023]
while True:
    value = get_value()
    print(value)
    time.sleep(0.1)