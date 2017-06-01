#!/usr/bin/python

from config.config import KEYCONF, INPUT, decode_audio
from actions.actions import switch

#from sphinxbase.sphinxbase import *
from pocketsphinx.pocketsphinx import Decoder

def main():
	decoder = Decoder(KEYCONF)
        decoder.start_utt()
        while True:
                l, buf = INPUT.read()
                if l:
                        decoder.process_raw(buf, False, False)
                if decoder.hyp() != None:
                        decoder.end_utt()

                        result = decode_audio()

			switch(result)

			decoder.start_utt()

if __name__ == "__main__":
	main()

