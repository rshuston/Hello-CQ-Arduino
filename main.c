#include "hw.h"
#include "morse.h"



#define DIT_LENGTH      100
#define DAH_LENGTH      (3 * DIT_LENGTH)
#define SYMBOL_SPACE    (DIT_LENGTH)
#define LETTER_SPACE    (3 * DIT_LENGTH)
#define WORD_SPACE      (7 * DIT_LENGTH)



int main(void)
{
    morseCtrls mCtrls;
    
    mCtrls.dit_ms = DIT_LENGTH;
    mCtrls.dah_ms = DAH_LENGTH;
    mCtrls.symbolSpace_ms = SYMBOL_SPACE;
    mCtrls.letterSpace_ms = LETTER_SPACE;
    mCtrls.wordSpace_ms = WORD_SPACE;
    mCtrls.keyOn = setB5Pin;
    mCtrls.keyOff = clearB5Pin;
    mCtrls.wait_ms = wait_ms;

    setB5ToOutput();
    
    for(;;)
    {
        morseSendText(&mCtrls, "CQ CQ CQ DE WD8NAQ WD8NAQ WD8NAQ");
        morseWaitWordSpace(&mCtrls);
        morseSendProsign(&mCtrls, "AR");
        morseWaitWordSpace(&mCtrls);
        morseWaitWordSpace(&mCtrls);
    }
}
