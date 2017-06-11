import subprocess
from lights import lights
from rgb import rgb
from fan import fan

def switch(words):
	if 'LIGHTS' in words:
		lights(words)
	elif 'GARDEN' in words:
		rgb(words)
	elif 'FAN' in words:
		fan(words)
	else:
		output = subprocess.call(['bash','-c', "play -q ./audio/sorry.wav"])
