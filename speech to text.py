import speech_recognition as spreg
#Setup the sampling rate and the data size
sample_rate = 48000
data_size = 8192
recog = spreg.Recognizer()
with spreg.Microphone(sample_rate = sample_rate, chunk_size = data_size) as source:
	recog.adjust_for_ambient_noise(source)
	print('Tell Something: ')
	speech = recog.listen(source)
try:
   text = recog.recognize_google(speech)
   print('You have said: ' + text)
except spreg.UnknownValueError:
   print('Unable to recognize the audio')
except spreg.RequestError as e: 
   print("Request error from Google Speech Recognition service; {}".format(e))