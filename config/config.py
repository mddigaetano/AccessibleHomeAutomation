import json, subprocess, time

import alsaaudio
import serial

from sphinxbase.sphinxbase import *
from pocketsphinx.pocketsphinx import *

with open('./config/config.json') as config_file:
	conf = json.load(config_file)

#Mic initialization
INPUT = alsaaudio.PCM(alsaaudio.PCM_CAPTURE, alsaaudio.PCM_NONBLOCK, device = conf['INPUT_DEVICE'])
INPUT.setchannels(1)
INPUT.setrate(16000)
INPUT.setformat(alsaaudio.PCM_FORMAT_S16_LE)
INPUT.setperiodsize(conf['PERIOD_SIZE'])

#Arduino constants and inizialization
ARDUINO = serial.Serial(conf['ARDUINO'])

#Decoder for keyword ack
KEYCONF = Decoder.default_config()
KEYCONF.set_string('-hmm', str(conf['HMM']))
KEYCONF.set_string('-dict', str(conf['DICT']))
KEYCONF.set_string('-logfn', str(conf['KEYWORD_LOG']))
KEYCONF.set_string('-keyphrase', str(conf['ACK_SENTENCE']))
KEYCONF.set_float('-kws_threshold', conf['KWS_TRESHOLD'])

#Decoder for commands ack
CMDCONF = Decoder.default_config()
CMDCONF.set_string('-hmm', str(conf['HMM']))
CMDCONF.set_string('-lm', str(conf['LM']))
CMDCONF.set_string('-dict', str(conf['DICT']))
CMDCONF.set_string('-logfn', str(conf['COMMAND_LOG']))

def decode_audio():
        decoder = Decoder(CMDCONF)
        decoder.start_utt()
        output = subprocess.call(['bash','-c', "play -q ./audio/ack.wav"])

        words = []
        start = time.time()
        while time.time() - start < conf['REC_SEC']:
                l, buf = INPUT.read()
                if l:
                        decoder.process_raw(buf, False, False)
	decoder.end_utt()

        for seg in decoder.seg():
                if seg.word.find('[') and seg.word.find('<'):
		#if utterances or other noises are not found
			words.append(seg.word)

        return words
