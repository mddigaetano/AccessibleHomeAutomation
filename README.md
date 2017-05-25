# AccessibleHomeAutomation

The aim of this project is to build a small prototype of an automated house, using a Raspberry (Pi3 in my case, but everyone else should be fine) and an Arduino-compatible board.

## Aim of the project
The target of the project is to help disabled, old or lazy people to control their own house with easy voice commands.
It can be accomplished with just a few prototyping platforms – meaning it is really inexpensive and simple to implement.

## Dependencies
* CMU Sphinx (https://cmusphinx.github.io/)
 * SphinxBase (https://github.com/cmusphinx/sphinxbase)
 * PocketSphinx (https://github.com/cmusphinx/pocketsphinx)
  * pocketsphinx-python (https://github.com/cmusphinx/pocketsphinx-python)
* PyAlsaAudio (https://github.com/larsimmisch/pyalsaaudio)
* libttspico (debian package)

## Details
### About the dependencies
CMU Sphinx is the only lightweight, open source, offline, supported and with already prepared models speech recognition software I found.
It is really easy to build and use (that is, if you don't want to dwell into language learning...) and it also provides nice python wrappers.

About PyAlsaAudio, it was necessary. Actually, I've started developing with the more famous PyAudio library, but it suffered poor performance on my Raspberry Pi 3. That's why I made the change.

### How to use it
Right now, it doesn't provide any kind of configuration file, that is needed to specify various directory locations, parameters and so on, so if you want to use it, you'll have to edit the first part of the program to make it work.

Anyway, when the program starts, it will continuously listen for a keyword (in this case, "Raspberry", but it could be anything). After a response (pre-made with `pico2wave`), it will listen to a real command for 5 seconds. After that, if it recognizes a command, it will execute the matching function.
