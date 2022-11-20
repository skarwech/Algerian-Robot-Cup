# Import libraries
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Set pin 11 as an output, and define as servo1 as PWM pin
GPIO.setup(11,GPIO.OUT)
servo1 = GPIO.PWM(11,50) # pin 11 for servo1, pulse 50Hz
GPIO.setup(12,GPIO.OUT)
servo2 = GPIO.PWM(12,50)
GPIO.setup(13,GPIO.OUT)
servo3 = GPIO.PWM(13,50)
# Start PWM running, with value of 0 (pulse off)
servo1.start(0)
servo2.start(0)
servo3.start(0)
# Loop to allow user to set servo angle. Try/finally allows exit
# with execution of servo.stop and GPIO cleanup :)

try:
    while True:
        #Ask user for angle and turn servo to it
        angle = float(input('Enter angle between 0 & 180 for servo 1: '))
        servo1.ChangeDutyCycle(2+(angle/18))
        time.sleep(0.5)
        servo1.ChangeDutyCycle(0)
        
        angle = float(input('Enter angle between 0 & 180 for servo 2: '))
        servo2.ChangeDutyCycle(2+(angle/18))
        time.sleep(0.5)
        servo2.ChangeDutyCycle(0)
        
        angle = float(input('Enter angle between 0 & 180 for servo 3: '))
        servo3.ChangeDutyCycle(2+(angle/18))
        time.sleep(0.5)
        servo3.ChangeDutyCycle(0)

finally:
    #Clean things up at the end
    servo1.stop()
    servo2.stop()
    servo3.stop()
    GPIO.cleanup()
    print("Goodbye!")


