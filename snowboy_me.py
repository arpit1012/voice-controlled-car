
import snowboydecoder
def detected_callback():
    print "hotword detected"
detector = snowboydecoder.HotwordDetector("forward.pmdl", sensitivity=0.5, audio_gain=1)
detector.start(detected_callback)