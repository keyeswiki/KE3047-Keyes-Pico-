# MicroPython TM1650驱动程序，I2C和SPI接口

import time

COMMAND_I2C_ADDRESS = 0x24
DISPLAY_I2C_ADDRESS = 0x34
SEG = [0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,]


class TM1650():
    def __init__(self, i2c):
        self.i2c = i2c
        self.cmd(3,8,1)
        time.sleep(0.01)

    # 数码管显示数字
    def display_write(self, num,bit):
        self.i2c.writeto(DISPLAY_I2C_ADDRESS+bit, bytearray([SEG[num]]))
        
    def display(self, num):
        if num < 0:
            self.i2c.writeto(DISPLAY_I2C_ADDRESS, 0x40)
        num1 = int(num/1000)
        num2 = int(num%1000/100)
        num3 = int(num%100/10)
        num4 = int(num%10)
        if num > 999:
            self.display_write(num1,0)
        if num > 99:
            self.display_write(num2,1)
        if num > 9:
            self.display_write(num3,2)
        if num >= 0:
            self.display_write(num4,3)
        
    #  数码管显示
    def display_clear(self):
        self.i2c.writeto(DISPLAY_I2C_ADDRESS, bytearray([0]))
        self.i2c.writeto(DISPLAY_I2C_ADDRESS+1, bytearray([0]))
        self.i2c.writeto(DISPLAY_I2C_ADDRESS+2, bytearray([0]))
        self.i2c.writeto(DISPLAY_I2C_ADDRESS+3, bytearray([0]))

    # 数码管灯(0-7)/位(7或8)/开或关(1或0)
    def cmd(self, light, bit, on):
        self.i2c.writeto(COMMAND_I2C_ADDRESS,bytearray([light*16+on+8*(8-bit)]))

