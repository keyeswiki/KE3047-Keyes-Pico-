from machine import ADC, Pin
import time
# 将火焰传感器初始化到引脚26 (ADC功能)
adc = ADC(26)

# 读取火焰传感器的模拟值并返回[0,1023]
def get_value():
    return int(adc.read_u16() * 1024 / 65536)
 
# 循环打印火焰传感器的当前模拟值[0, 1023]
while True:
    value = get_value()
    print(value)
    time.sleep(0.1)