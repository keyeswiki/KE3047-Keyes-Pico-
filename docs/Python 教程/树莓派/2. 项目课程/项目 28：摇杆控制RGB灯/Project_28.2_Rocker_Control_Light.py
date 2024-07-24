from machine import Pin, PWM
import time
import machine
#设置RGB的接口和频率
rgb_r = PWM(Pin(18))
rgb_g = PWM(Pin(17))
rgb_b = PWM(Pin(16))
rgb_b.freq(1000)
rgb_r.freq(1000)
rgb_g.freq(1000)
#设置摇杆的引脚
rocker_y = machine.ADC(26)
rocker_x = machine.ADC(27)
y=500
x=500
while True:
    y = rocker_y.read_u16()#获取摇杆的Y值
    x = rocker_x.read_u16()#获取摇杆的X值
    if x < 6400:    #左
        rgb_b.duty_u16(0)
        rgb_r.duty_u16(65535)
        rgb_g.duty_u16(0)
    elif x > 38400:    #右
        rgb_b.duty_u16(0)
        rgb_r.duty_u16(0)
        rgb_g.duty_u16(65535)
    elif y < 6400:    #下
        rgb_b.duty_u16(65535)
        rgb_r.duty_u16(0)
        rgb_g.duty_u16(0)
    elif y > 38400:    #上
        rgb_b.duty_u16(65535)
        rgb_r.duty_u16(65535)
        rgb_g.duty_u16(65535)
    time.sleep(0.01)