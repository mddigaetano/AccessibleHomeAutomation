import subprocess

from config.config import ARDUINO

#lights management
#command structure: [<OPTIONAL>,<ROOM>,"LIGHTS",<STATE>]
def luci(words):

        ROOMS = {
                "BAGNO" : "BATHROOM",
                "CUCINA" : "KITCHEN",
                "SALONE" : "DINING",
                "CAMERA" : "BEDROOM",
                "CASA" : "ALL"
        }
	STATES = {
		"ACCENDI" : "ON",
		"SPEGNI" : "OFF"
	}

        index = words.index("LUCI")
        try:
                state = words[index - 1]
                #if state.find('(') != -1:
                #        state = state[:state.index('(')]

                room = words[index + 1]
                #if room == "ROOM":
                #        room = words[index - 2]

                string = ('<' + ROOMS[room] + ';' + STATES[state] + '>')
                if room in ROOMS:
                        ARDUINO.write(string)
                        answer = "Le luci in "+ room.lower() + "sono" + state.lower()
			output = subprocess.call(['bash','-c', "pico2wave -w ./audio/answer.wav \"" + answer + "\""])
                        output = subprocess.call(['bash','-c', "play -q ./audio/answer.wav"])
        except:
                output = subprocess.call(['bash','-c', "play -q ./audio/sorry.wav"])
