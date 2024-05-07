from sys import argv
import cv2

VIDEO_PATH = argv[1]
IMAGE_PATH = argv[2]

cap = cv2.VideoCapture(VIDEO_PATH)
if not cap.isOpened():
    print("OPEN ERROR.")
    exit()

ret, frame = cap.read()
if not ret:
    print("READ ERROR.")
    exit()
cv2.imwrite(IMAGE_PATH, frame)

exit()
