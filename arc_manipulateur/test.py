from gpiozero import Servo
from time import sleep

servo = Servo(5)
val = -1
try :
    while True :
        servo.value = val
        sleep(0.5)
        val = val + 0.1
        if val > 0.8 :
            val = -0.8
except KeyboardInterrupt :
    print ("stopped")