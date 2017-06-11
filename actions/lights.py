import subprocess

from config.config import ARDUINO

#lights management
#command structure: [<OPTIONAL>,<ROOM>,"LIGHTS",<STATE>]
def lights(words):

        ROOMS = {
                "BATHROOM" : "BATHROOM",
                "KITCHEN" : "KITCHEN",
                "DINING" : "DINING",
                "BEDROOM" : "BEDROOM",
                "ALL" : "ALL"
        }

        index = words.index("LIGHTS")
        try:
                state = words[index + 1]
                if state.find('(') != -1:
                        state = state[:state.index('(')]

                room = words[index - 1]
                if room == "ROOM":
                        room = words[index - 2]

                string = ('<LIGHTS;' + room + ';' + state + '>')
                if room in ROOMS:
                        ARDUINO.write(string)
                        answer = room.lower() + " lights are now " + state.lower()
                        output = subprocess.call(['bash','-c', "pico2wave -w ./audio/answer.wav \"" + answer + "\""])
                        output = subprocess.call(['bash','-c', "play -q ./audio/answer.wav"])
		else:
			raise Exception()
	except:
                output = subprocess.call(['bash','-c', "play -q ./audio/sorry.wav"])
