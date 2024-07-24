from machine import ADC, Pin
import time

# 初始化LM35温度传感器引脚26 (ADC功能)
# 选择ADC0 (GPIO26)
sensor_temp = ADC(26)
conversion_factor = 3.3 / (65535)

while True:
    reading = sensor_temp.read_u16() * conversion_factor 
    temperature = reading * 102.4 
    print(temperature)
    time.sleep(1)