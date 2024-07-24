from machine import Pin
import time

#使用阵列定义10个连接到LED条形图的GPIO端口，方便操作.
pins = [16, 17, 18, 19, 20, 21, 22, 26, 27, 28]
#使用两个for循环，分别从左到右打开led，然后从右到左返回
def showLed():
    for pin in pins:
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)        
    for pin in reversed(pins):
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)
          
while True:
    showLed()