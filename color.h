#ifndef COLOR_H
#define COLOR_H
char* checkColour(char*);
char* background(char*);
char* textColour(char*);
#endif

#define RED "\x1b[0;31m" 
#define GREEN "\x1b[0;32m"
#define BLUE "\x1b[0;34m"
#define YELLOW "\x1b[0;33m"
#define MAGENTA "\x1b[0;35m"
#define CYAN "\x1b[0;36m"

#define URED "\x1b[4;31m" 
#define UGREEN "\x1b[4;32m"
#define UBLUE "\x1b[4;34m"
#define UYELLOW "\x1b[4;33m"
#define UMAGENTA "\x1b[4;35m"
#define UCYAN "\x1b[4;36m"

#define HRED "\x1b[0;41m" 
#define HGREEN "\x1b[0;42m"
#define HBLUE "\x1b[0;44m"
#define HYELLOW "\x1b[0;43m"
#define HMAGENTA "\x1b[0;45m"
#define HCYAN "\x1b[0;46m"

#define RESET "\x1b[0m"


