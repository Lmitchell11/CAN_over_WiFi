#Liam Mitchell
#Testing UART functionality for RaspberryPi

from time import sleep
import serial


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
#repeatWriteBytes(serialPort0, b'AT\r\n', 0.01, 200000000)
serialPortLoopBack(serialPort0, b'Testing123456789\r\n', 32, 0.030)
