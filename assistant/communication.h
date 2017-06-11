const byte BUFFER_SIZE = 128;
char buffer[BUFFER_SIZE];

char START_CHAR= '<';
char END_CHAR = '>';

bool newData = false;

void full_receive();
const char * full_read();
