import subprocess

from config.config import ARDUINO

def rgb(words):

	COLORS = [
		"RED",
		"ORANGE",
		"YELLOW",
		"GREEN",
		"BLUE",
		"PURPLE",
		"INDIGO",
		"WHITE",
		"OFF",
		"FADE"
	]

	index = words.index("GARDEN")
	try:
		color = words[index + 1]
		if color.find('(') != -1:
			color = color[:color.index('(')]

		string = ('<RGB;' + color + '>')
		if color in COLORS:
			ARDUINO.write(string)
			answer = "garden lights is now " + color.lower()
			output = subprocess.call(['bash','-c', "pico2wave -w ./audio/answer.wav \"" + answer + "\""])
                        output = subprocess.call(['bash','-c', "play -q ./audio/answer.wav"])
		else:
			raise Exception()
	except:
		output = subprocess.call(['bash','-c', "play -q ./audio/sorry.wav"])
