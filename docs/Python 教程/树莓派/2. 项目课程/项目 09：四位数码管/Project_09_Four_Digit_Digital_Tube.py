from machine import Pin, I2C
from TM1650 import TM1650
import time

# 定义IIC接口和频率
i2c=I2C(0, scl=Pin(21),sda=Pin(20), freq=100000)

display = TM1650(i2c)

# 循环显示数字1111-9999
while True:
    display.display(1111)
    time.sleep(1)
    display.display(2222)
    time.sleep(1)
    display.display(3333)
    time.sleep(1)
    display.display(4444)
    time.sleep(1)
    display.display(5555)
    time.sleep(1)
    display.display(6666)
    time.sleep(1)
    display.display(7777)
    time.sleep(1)
    display.display(8888)
    time.sleep(1)
    display.display(9999)
    time.sleep(1)
