from sys import argv
import os
os.environ["OPENCV_VIDEOIO_MSMF_ENABLE_HW_TRANSFORMS"] = "0"
from time import sleep
import datetime
import cv2

# if len(argv) < 2:
#     print("too frew arguments")
#     exit()

def capture(cap, IMG_PATH):

    ret, frame = cap.read()
    if not ret:
        print("No frame can read.")
        return
    # cv2.imwrite(f"{DATE}/{IMG_PATH}.jpg", frame)
    cv2.imwrite(IMG_PATH, frame)
    print(f"note: captured ({IMG_PATH})")
    return

cap = cv2.VideoCapture(1)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)
if not cap.isOpened():
    print("ERROR. Video Stream CAN'T BE OPEN")
    exit()

while True:
    dt_now = datetime.datetime.now()
    DATE = dt_now.strftime('%Y%m%d')
    TIME = dt_now.strftime('%H%M')
    IMG_PATH = f"{DATE}/{TIME}.jpg"

    try:
        os.mkdir(DATE)
    except FileExistsError:
        print(f"note: dir {DATE} is exist")

    capture(cap, IMG_PATH)
    sleep(60)
