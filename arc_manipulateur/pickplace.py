# Import libraries
import RPi.GPIO as GPIO
import time

# Set GPIO numbering mode
GPIO.setmode(GPIO.BOARD)

# Set pin 11 as an output, and define as servo1 as PWM pin
GPIO.setup(11,GPIO.OUT)
servo1 = GPIO.PWM(11,50) # pin 11 for servo1, pulse 50Hz
GPIO.setup(12,GPIO.OUT)
servo3 = GPIO.PWM(12,50)
GPIO.setup(13,GPIO.OUT)
servo2 = GPIO.PWM(13,50)
# Start PWM running, with value of 0 (pulse off)
servo1.start(0)
servo2.start(0)
servo3.start(0)

time.sleep(3)

servo1.ChangeDutyCycle(2)
time.sleep(0.5)
servo1.ChangeDutyCycle(0)
time.sleep(1)

time.sleep(3)
print("servo 1 pos initial")


servo1.ChangeDutyCycle(2+(20/18))
time.sleep(0.5)
servo1.ChangeDutyCycle(0)
time.sleep(1)

servo1.ChangeDutyCycle(2+(40/18))
time.sleep(0.5)
servo1.ChangeDutyCycle(0)
time.sleep(1)

servo1.ChangeDutyCycle(2+(60/18))
time.sleep(0.5)
servo1.ChangeDutyCycle(0)
time.sleep(1)

servo1.ChangeDutyCycle(2+(75/18))
time.sleep(0.5)
servo1.ChangeDutyCycle(0)

time.sleep(2)
print("servo 1 pos final")

# Wait for 2 seconds
time.sleep(2)

servo2.ChangeDutyCycle(2)
time.sleep(0.5)
servo2.ChangeDutyCycle(0)
time.sleep(1)


#servo2.ChangeDutyCycle(2+(30/18))
#time.sleep(0.5)
#servo2.ChangeDutyCycle(0)
#time.sleep(1) 


time.sleep(1)
print("servo 2 pos finale")





servo3.ChangeDutyCycle(2+(10/18))
time.sleep(0.5)
servo3.ChangeDutyCycle(0)
time.sleep(1)

time.sleep(1)
print("servo 3 pos initial")

servo3.ChangeDutyCycle(2+(20/18))
time.sleep(0.5)
servo3.ChangeDutyCycle(0)
time.sleep(1)

servo3.ChangeDutyCycle(2+(35/18))
time.sleep(0.5)
servo3.ChangeDutyCycle(0)
time.sleep(1)

print("servo 3 pos finale")


servo1.stop()
servo2.stop()
servo3.stop()
GPIO.cleanup()
print("Goodbye!")







