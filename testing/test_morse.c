#include <stdio.h>

#include "morse.h"



#define DIT_LENGTH      100
#define DAH_LENGTH      (3 * DIT_LENGTH)
#define SYMBOL_SPACE    (DIT_LENGTH)
#define LETTER_SPACE    (3 * DIT_LENGTH)
#define WORD_SPACE      (7 * DIT_LENGTH)



static int keyState = 0;

static void keyOn(void)
{
    keyState = 1;
}

static void keyOff(void)
{
    keyState = 0;
}

static void wait_ms(float time_ms)
{
    int n = (time_ms + 0.1 * DIT_LENGTH) / DIT_LENGTH;
    char *s = "";
    
    switch (n)
    {
        case 1:
            s = keyState ? "*" : "_";
            break;
        case 3:
            s = keyState ? "###" : "___";
            break;
        case 7:
            s = keyState ? "" : "_______";
            break;
    }
    
    fputs(s, stdout);
}



int main(void)
{
    morseCtrls mCtrls;
    
    mCtrls.dit_ms = DIT_LENGTH;
    mCtrls.dah_ms = DAH_LENGTH;
    mCtrls.symbolSpace_ms = SYMBOL_SPACE;
    mCtrls.letterSpace_ms = LETTER_SPACE;
    mCtrls.wordSpace_ms = WORD_SPACE;
    mCtrls.keyOn = keyOn;
    mCtrls.keyOff = keyOff;
    mCtrls.wait_ms = wait_ms;
    
    fputc('\n', stdout);

#if 0
    
    morseSendSymbol(&mCtrls, 'C');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, 'Q');
    
    morseWaitWordSpace(&mCtrls);
    
    morseSendSymbol(&mCtrls, 'D');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, 'E');
    
    morseWaitWordSpace(&mCtrls);
    
    morseSendSymbol(&mCtrls, 'W');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, 'D');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, '8');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, 'N');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, 'A');
    morseWaitLetterSpace(&mCtrls);
    morseSendSymbol(&mCtrls, 'Q');
    
#else
    
    morseSendText(&mCtrls, "CQ DE WD8NAQ");
    
#endif
    
    morseWaitWordSpace(&mCtrls);
    morseSendProsign(&mCtrls, "AR");
    
    puts("\n\nEND OF LINE");    
}
