#include <stddef.h>
#include <ctype.h>

#include "morse.h"



void morseWaitLetterSpace(morseCtrls *ctrls)
{
    ctrls->wait_ms(ctrls->letterSpace_ms);
}



void morseWaitWordSpace(morseCtrls *ctrls)
{
    ctrls->wait_ms(ctrls->wordSpace_ms);
}



void morseSendSymbol(morseCtrls *ctrls, int symbol)
{
    char *s = NULL;
        
    switch ( toupper(symbol) )
    {
        case 'A':
            s = ".-";
            break;
        case 'B':
            s = "-...";
            break;
        case 'C':
            s = "-.-.";
            break;
        case 'D':
            s = "-..";
            break;
        case 'E':
            s = ".";
            break;
        case 'F':
            s = "..-.";
            break;
        case 'G':
            s = "--.";
            break;
        case 'H':
            s = "....";
            break;
        case 'I':
            s = "..";
            break;
        case 'J':
            s = ".---";
            break;
        case 'K':
            s = "-.-";
            break;
        case 'L':
            s = ".-..";
            break;
        case 'M':
            s = "--";
            break;
        case 'N':
            s = "-.";
            break;
        case 'O':
            s = "---";
            break;
        case 'P':
            s = ".--.";
            break;
        case 'Q':
            s = "--.-";
            break;
        case 'R':
            s = ".-.";
            break;
        case 'S':
            s = "...";
            break;
        case 'T':
            s = "-";
            break;
        case 'U':
            s = "..-";
            break;
        case 'V':
            s = "...-";
            break;
        case 'W':
            s = ".--";
            break;
        case 'X':
            s = "-..-";
            break;
        case 'Y':
            s = "-.--";
            break;
        case 'Z':
            s = "--..";
            break;
        case '0':
            s = "-----";
            break;
        case '1':
            s = ".----";
            break;
        case '2':
            s = "..---";
            break;
        case '3':
            s = "...--";
            break;
        case '4':
            s = "....-";
            break;
        case '5':
            s = ".....";
            break;
        case '6':
            s = "-....";
            break;
        case '7':
            s = "--...";
            break;
        case '8':
            s = "---..";
            break;
        case '9':
            s = "----.";
            break;
        case '.':
            s = ".-.-.-";
            break;
        case ',':
            s = "--..--";
            break;
        case '?':
            s = "..--..";
            break;
        case '/':
            s = "-..-.";
            break;
        default:
            s = NULL;
            break;
    }
    
    if (s != NULL)
    {
        char *m;
        
        for (m = s; *m; m++)
        {
            switch (*m)
            {
                case '.':
                    ctrls->keyOn();
                    ctrls->wait_ms(ctrls->dit_ms);
                    ctrls->keyOff();
                    ctrls->wait_ms(ctrls->symbolSpace_ms);
                    break;
                case '-':
                    ctrls->keyOn();
                    ctrls->wait_ms(ctrls->dah_ms);
                    ctrls->keyOff();
                    ctrls->wait_ms(ctrls->symbolSpace_ms);
                    break;
            }
        }
    }
}



void morseSendText(morseCtrls *ctrls, char *text)
{
    int inWord = 0;
    char *s = text;
    
    while (*s)
    {
        if (*s == ' ')
        {
            inWord = 0;
            morseWaitWordSpace(ctrls);
        }
        else
        {
            if (inWord)
            {
                morseWaitLetterSpace(ctrls);
            }
            morseSendSymbol(ctrls, *s);
            inWord = 1;
        }
        
        s++;
    }
}



void morseSendProsign(morseCtrls *ctrls, char *prosign)
{
    char *s = prosign;
    
    while (*s)
    {
        morseSendSymbol(ctrls, *s);
        s++;
    }
}
