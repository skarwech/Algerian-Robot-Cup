import cv2

webcam = cv2.VideoCapture(1)
while(1) :
    success, image = webcam.read()
    if success :
        cv2.imshow("image" , image )
    else :
        print("nop")
    
    
    if cv2.waitKey(10) & 0xFF == ord('q') :
        cap.release()
        cv2.destroyAllWindows()
        break