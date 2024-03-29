import cv2

V_PATH = "rtsp://2909:4228@192.168.0.151/live"

cap = cv2.VideoCapture(V_PATH)
if not cap.isOpened():
    print("ERROR. Video Stream CAN'T BE OPEN")
    exit()

ret, frame = cap.read()
if not ret:
    print("No frame can read.")
    exit()
cv2.imwrite("frame.jpg", frame)

exit()
