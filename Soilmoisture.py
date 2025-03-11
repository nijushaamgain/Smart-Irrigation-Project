import serial
import time

ser = serial.Serial('COM3', 9600)

state = input("Do you want to water the plant?")

while state == 'y':
    ser.write(b'y')
    time.sleep(1)
else:
    ser.write(b'n')
    time.sleep(1)
