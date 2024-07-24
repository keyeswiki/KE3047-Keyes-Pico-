from machine import Pin
import time

buzzer = Pin(16, Pin.OUT)   # 从引脚16创建蜂鸣器对象，设置引脚16为输出

try:
    while True:
        buzzer.value(1)    # 设置蜂鸣器开启
        time.sleep(0.5) # 延时 0.5s
        buzzer.value(0)    # 设置蜂鸣器关闭
        time.sleep(0.5) # 延时 0.5s
except:
    pass