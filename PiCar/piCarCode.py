##Liam Mitchell, Spencer Hill
##12/11/2021                                                     #Freaky... but i worked on a very similar project on 12/11/2018 (Coincidence?)
##Runs on SunFounder PiCar -S, or V2
import RPi.GPIO as GPIO                                         #Imports GPIO (Input/Output) Pins and libraries
import time                                                     #Imports time function
import serial
import re                                                       #Imports libraries to read strings, and do string stuff
import os                                                       #Imports libraries to execute cool operations involving folder structures, and more (If needed)
import picar                                                    #imports folder
from SunFounder_PCA9685 import Servo
import filedb
from front_wheels import Front_Wheels                           #Imports front_Wheels() class
from back_wheels import Back_Wheels                             #Imports Back_Wheels() class


#calibrate = True
#calibrate = False                                              #We could calibrate the piCar on startup before our run, but lets not
forward_speed = 80                                              #Ideal forward speed
backward_speed = 70                                             #Ideal backward speed
turning_angle = 'sup'                                              #We could set this as the ideal turn for initialization, then use it to grab data from I2C connection and do calculation'''
#front_wheels.turning_max = 45                                   #We don't want to go over 45*degrees from the initial 90*degrees on the servo, if we go past the +/- 90* we will likely burn up the servos.'''
delay = 0.01                                                    #Delay to help break up small loops, so they don't immediatly execute all the instructions in a loop at once.



#Opens port
serialPort0 = serial.Serial('/dev/serial0',
                            baudrate = 115200,
                            parity = serial.PARITY_NONE,
                            stopbits = serial.STOPBITS_ONE,
                            bytesize = serial.EIGHTBITS,
                            timeout= 1)    


def setSerialPortBaudRate(serialPort, baudrate):
    serialPort.baudrate = baudrate
    return

def serialPortWriteBytes(serialPort, writeBytes):
    serialPort.write(writeBytes)
    return

def serialPortReadBytes(serialPort, maxBytesLength):
    readBytes = serialPort.read(maxBytesLength)
    return readBytes

def serialPortWriteWaitReadBytes(serialPort, writeBytes, maxBytesLength, waitTime):
    serialPort.flushInput()
    serialPort.flushOutput()
    serialPort.write(writeBytes)
    sleep(waitTime)
    readBytes = serialPortReadBytes(serialPort, maxBytesLength)
    print('        bytes written = ', writeBytes) 
    print('        bytes read    = ', readBytes)
    return readBytes

def repeatWriteBytes(serialPort, writeBytes, pauseTimeBetweenBytes, repeatCount):
    print('       Begin repeatWriteOneByte(), ...')
    for i in range(repeatCount):
        serialPortWriteBytes(serialPort, writeBytes)
        sleep(pauseTimeBetweenBytes)
    print('       End   repeatWriteOneByte().')
    return

def serialPortLoopBack(serialPort, writeBytes, maxBytesLength, waitTime):
    serialPortWriteWaitReadBytes(serialPort, writeBytes, maxBytesLength, waitTime)
    print('        End   serialPortLoopBack(), ...')
    return

setSerialPortBaudRate(serialPort0, 115200)

#Driving instructions Function for piCar           
def mergeDrive(chn = 0):                                        #On channel 0 because that is what it is initialized to in the Front_Wheels() Class
    back_wheels = Back_Wheels()                                 #We will want to put these into a class'''
    front_wheels = Front_Wheels(channel = chn)                  #We will want to put these into a class'''
    try:
            while True:                                         #Just a stupid loop for reading terminal/debugging
                    serialPort0.flushInput()
                    turning_angle = serialPortReadBytes(serialPort0, 4) #try reducing
                    turning_angle = turning_angle.replace("\r\n","")
                    turning_angle = int(turning_angle)
#                    time.sleep(0.030)
#                    if (turning_angle >= 75):
#                        turning_angle = 75
#                    print("Sraight")                            #Prints the word "Straight" to terminal for debugging purposes
#                    front_wheels.turn_straight()                #Turns front wheels straight

#                    print("Accelerating")
#                    back_wheels.forward()                       #Allows the piCar to move forward, once speed initilized
#                    for i in range(0, 100):                     #Dont need this, it just shows acceleration'''
#                            back_wheels.speed = i
#                            print("Forward, speed =", i)
#                            time.sleep(delay)


#                    print("Steering Angle")
                    turning_angle += 60

                    print(turning_angle)
                    front_wheels.turn(turning_angle)
                    time.sleep(0.2)
#                    back_wheels.stop()

                            
#                    print("Right")                              #Prints the word "Right" to terminal for debugging purposes
#                    front_wheels.turn_right()                   #Turns front wheels Right for 1 second
#                    time.sleep(1)                               #Delay is to help space out piCar wheel motions for development purposes
#                    back_wheels.stop()                          #Tell piCar to stop

                    
#                    print("Left")                               #Prints the word "Left" to terminal for debugging purposes
#                    front_wheels.turn_left()                    #Turns front wheels Left for 1 second
#                    time.sleep(1)                               #Delay is to help space out piCar wheel motions for development purposes
#                    back_wheels.stop()                          #Tell piCar to stop


#                    print("Sraight")                            #Prints the word "Straight" to terminal for debugging purposes
#                    front_wheels.turn_straight()                #Turns wheels straight so the piCar is at a known position for the next time it decides to move
#                    time.sleep(1)                               #Hit keyboard interrupt at this time so we don't leave wheels spinning after program stops
    except KeyboardInterrupt:                                   #On keyboard interrupt stop/straighten out piCar before exiting
            print("KeyboardInterrupt, motor stop")              
            back_wheels.stop()                                  
            front_wheels.turn_straight()


if __name__ == '__main__':
        try:
                mergeDrive()
                print("go")
                time.sleep(1)
        except KeyboardInterrupt:
                back_wheels.stop()
                front_wheels.turn_straight()
                time.sleep(1)
