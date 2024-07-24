from machine import Pin,PWM
import utime
from irrecvdata import irGetCMD

#设置RGB的接口和频率
rgb_r = PWM(Pin(19))
rgb_g = PWM(Pin(18))
rgb_b = PWM(Pin(17))
rgb_r.freq(1000)
rgb_g.freq(1000)
rgb_b.freq(1000)

# 初始化蜂鸣器引脚为PWM功能
buzzer=PWM(Pin(15, Pin.OUT))
buzzer.freq(262)
buzzer.duty_u16(0)

# 播放中音的频率1-7
freq = [262, 294, 330, 350, 393, 441, 495]

#配置红外接收引脚和库
recvPin = irGetCMD(16)

# 设置蜂鸣器发出不同的声音,index=[0-7]，其中0是闭合的，1-7分别表示中间C、中间D、中间E、中间F、中间G、中间A、中间B.
# time表示函数延迟时间(一个正整数)，单位为毫秒.
# “auto_off”表示是否在延迟时间后自动关闭蜂鸣器.
def tone(index, time=0, auto_off=False):
    if index == 0:
        buzzer.duty_u16(0)
        utime.sleep_ms(time)
    elif index >= 1 and index <= 7:
        tone_freq = freq[int(index - 1)]
        buzzer.freq(tone_freq)
        buzzer.duty_u16(32768)
        utime.sleep_ms(time)
        if auto_off == True:
            buzzer.duty_u16(0)
        # print("----freq:", index, tone_freq)
    else:
        print("Tones must be 0-7")
 
delay = 0
 
tone(1, 100, True)

while True:
    irValue = recvPin.ir_read() # 读取红外遥控器数据
   # 确定是否有满足需求的按钮 
    if irValue:
        print(irValue)
        if irValue == '0xff6897':   #1
           rgb_r.duty_u16(65535)
           rgb_g.duty_u16(0)
           rgb_b.duty_u16(0)
           tone(1, delay)
        elif irValue == '0xff9867': #2
            rgb_r.duty_u16(0)
            rgb_g.duty_u16(65535)
            rgb_b.duty_u16(0)
            tone(2, delay)
        elif irValue == '0xffb04f': #3
            rgb_r.duty_u16(0)
            rgb_g.duty_u16(0)
            rgb_b.duty_u16(65535)
            tone(3, delay)
        elif irValue == '0xff30cf': #4
            rgb_r.duty_u16(65535)
            rgb_g.duty_u16(65535)
            rgb_b.duty_u16(0)
            tone(4, delay)
        elif irValue == '0xff18e7': #5
            rgb_r.duty_u16(65535)
            rgb_g.duty_u16(0)
            rgb_b.duty_u16(65535)
            tone(5, delay)
        elif irValue == '0xff7a85': #6
            rgb_r.duty_u16(0)
            rgb_g.duty_u16(65535)
            rgb_b.duty_u16(65535)
            tone(6, delay)
        elif irValue == '0xff10ef': #7
            rgb_r.duty_u16(65535)
            rgb_g.duty_u16(65535)
            rgb_b.duty_u16(65535)
            tone(7, delay) 
        else:
            rgb_r.duty_u16(0)
            rgb_g.duty_u16(0)
            rgb_b.duty_u16(0)
            tone(0)