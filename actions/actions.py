import subprocess
from lights import lights

def switch(words):
	if 'LIGHTS' in words:
		lights(words)
	else:
		output = subprocess.call(['bash','-c', "play -q ./audio/sorry.wav"])
