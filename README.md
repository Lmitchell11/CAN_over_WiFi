# CAN_over_WiFi


Credits: 
Liam Mitchell, Spencer Hill


Project:
CAN bus data acquisition using "obdlink ex usb" adapter to Laptop. PID data is acquired by a "TI CC3220SF" through Serial communication method.
Ideal CAN bus PID is the steering angle of an EPS (Electric Power Steering) Car, Measurement will be packaged up and sent through wifi to another "TI CC3220SF" microcontroller.
This micro will be powered and connected through UART to a piCar (Raspberry pi) and the pi car will take this data interperate if it is within its servo's ranges and apply
the steering angle transmitted wirelessly from the actual Automobile's CAN bus.


Goal: 
Will be explained later in a youtube video/powerpoint presentation for MSU Masters ECE program.


Note:
This is a work in progress, first commits were ugly because github sucks when it comes to SSH...

