#ifndef MORSE_H
#define MORSE_H


typedef struct morseCtrls
{
    float dit_ms;
    float dah_ms;
    float symbolSpace_ms;
    float letterSpace_ms;
    float wordSpace_ms;
    void (*keyOn)(void);
    void (*keyOff)(void);
    void (*wait_ms)(float time_ms);
}
morseCtrls;


void morseWaitLetterSpace(morseCtrls *ctrls);
void morseWaitWordSpace(morseCtrls *ctrls);
void morseSendSymbol(morseCtrls *ctrls, int symbol);
void morseSendText(morseCtrls *ctrls, char *text);
void morseSendProsign(morseCtrls *ctrls, char *prosign);



#endif
