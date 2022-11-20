import cv2
import numpy as np
#import conveyor_lib
import time 
from shapedetector import ShapeDetector
import imutils
import pandas as pd
from picamera.array import PiRGBArray
from picamera import PiCamera


camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(640, 480))
# allow the camera to warmup
time.sleep(0.1)

liste_cnt = [0]

for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    image = frame.array
    
    # Belt
    belt = image[0: 480, 0: 480]
    gray_belt = cv2.cvtColor(belt, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray_belt, (5, 5), 0)
    _, threshold = cv2.threshold(blurred, 5, 255, cv2.THRESH_BINARY) #_INV)   50 , 255 
    
    contours = cv2.findContours(threshold.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = imutils.grab_contours(contours)
    sd = ShapeDetector()
    for cnt in contours:
        #(x, y, w, h) = cv2.boundingRect(cnt)
        
        # Calculate area
        cnt = cnt.astype("int")
        area = cv2.contourArea(cnt)
        

        if area > 500 :
            if area < 5842568 :
                shape = sd.detect(cnt)
                cv2.drawContours(belt, [cnt], -1, (0, 255, 0), 2)
                liste_cnt.append(shape)
                if len(liste_cnt) == 200:
                    df = pd.DataFrame(liste_cnt)
                    most_repeated_shape = df.mode()
                    print(len(liste_cnt))
                    print(most_repeated_shape)
                    liste_cnt= [0]
                else :
                    continue 
        else :
            #print('nothing')
            pass 

            #cv2.rectangle(belt, (x, y), (x + w, y + h), (0, 0, 255), 2)
            
            # Stop belt
            #relay.turn_off()
            
        #elif 100 < area < 400:
            #cv2.rectangle(belt, (x, y), (x + w, y + h), (255, 0, 0), 2)
            
        #cv2.putText(belt, str(area), (x, y), 1, 1, (0, 255, 0))
    
    
    #cv2.imshow("Frame", image)
    cv2.imshow("belt", belt)
    #cv2.imshow("gray belt", gray_belt)
    cv2.imshow("threshold", threshold)
    rawCapture.truncate(0)
    
    key = cv2.waitKey(1)
    if key == 27:
        break
    #elif key == ord("n"):
        #relay.turn_on()
    #elif key == ord("m"):
        #relay.turn_off()
    
    
cv2.destroyAllWindows()