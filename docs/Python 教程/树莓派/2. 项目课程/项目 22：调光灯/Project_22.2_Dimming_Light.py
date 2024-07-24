from machine import ADC, Pin, PWM
import time

adc = ADC(26) # 将电位器初始化到引脚26 (ADC功能)
pwm = PWM(Pin(16)) # 初始化led的PWM引脚16
pwm.freq(1000) # 定义PWM频率为1000
try:
    while True:
        adcValue = adc.read_u16() # 读取电位器的ADC值
        pwm.duty_u16(adcValue) # 映射到PWM占空比来控制led亮度 
        time.sleep(0.1)
except:
    pwm.deinit()