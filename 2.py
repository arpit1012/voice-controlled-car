import wake_word

paths = ['./triggers/go_left_linux.ppn','./triggers/go_right_linux.ppn','./triggers/computer_linux.ppn', './triggers/stop_bot_linux.ppn','./triggers/goahead_linux.ppn', './triggers/hey_raman_linux.ppn','./triggers/go_back_linux.ppn']
out = wake_word.trigger_detect(paths)
print(out)
