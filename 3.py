import serial           # import the module
import wake_word
ComPort = serial.Serial('/dev/cu.HC-05-SPPDev') # open COM24
ComPort.baudrate = 9600 # set Baud rate to 9600
ComPort.bytesize = 8    # Number of data bits = 8
ComPort.parity   = 'N'  # No parity
ComPort.stopbits = 1    # Number of Stop bits = 1
# Write character 'A' to serial port
n=0 
wordig=["forward","left","right","stop","backward"]
while n==0:
    print("new")
    out=0
    paths = ['./triggers/forward_mac.ppn']
    out = wake_word.trigger_detect(paths)
    text=wordig[out]
    print(text)
    data = bytearray(text, 'utf-8')
    ComPort.write(data)
    #name=input()
    if text=="s":
        n=1

ComPort.close()    
