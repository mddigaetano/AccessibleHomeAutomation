import subprocess

from config.config import ARDUINO

def fan(words):

	STATES = [
		"ON",
		"OFF"
	]

	index = words.index("FAN")
	try:
		state = words[index + 1]
		if state.find('(') != -1:
			state = state[:state.index('(')]

		string = ('<FAN;' + state + '>')
		if state in STATES:
			ARDUINO.write(string)
			answer = "the fan is now " + state.lower()
			output = subprocess.call(['bash','-c', "pico2wave -w ./audio/answer.wav \"" + answer + "\""])
                        output = subprocess.call(['bash','-c', "play -q ./audio/answer.wav"])
                else:
                        raise Exception()
        except:
                output = subprocess.call(['bash','-c', "play -q ./audio/sorry.wav"])
