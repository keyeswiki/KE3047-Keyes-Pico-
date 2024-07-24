from machine import Pin, ADC
import time
# 初始化摇杆模块引脚(ADC功能)
rocker_x = ADC(27)
rocker_y = ADC(26)
button = Pin(28, Pin.IN, Pin.PULL_UP)
 
# 读取X轴的值并返回[0,1023]
def read_x():
    value = int(rocker_x.read_u16() * 1024 / 65536)
    return value
 
# 读取Y轴值并返回[0,1023]
def read_y():
    value = int(rocker_y.read_u16() * 1024 / 65536)
    return value
 
# 读取按钮状态，按下返回True，松开返回False
def btn_state():
    press = False
    if button.value() == 0:
        press = True
    return press
 
# 循环打印X轴、Y轴、Z轴的当前值.
while True:
    value_x = read_x()
    value_y = read_y()
    state = btn_state()
    print("x:%d, y:%d, press:%s" % (value_x, value_y, state))
    time.sleep(0.1)