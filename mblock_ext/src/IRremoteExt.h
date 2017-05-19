#ifndef IRREMOTEEXT_H
#define IRREMOTEEXT_H

typedef void (*__ir_handler_type)(unsigned long);

extern void beginIRremote(int pin);

void addPressHandlerIRremote(unsigned long code, __ir_handler_type func);
void addReleaseHandlerIRremote(unsigned long code, __ir_handler_type func);

extern void handelIRremote();

#define IR_CODE_PWR		0xFFA25D
#define IR_CODE_MODE	0xFF629D
#define IR_CODE_MUTE	0xFFE21D
#define IR_CODE_PLAY	0xFF22DD
#define IR_CODE_FWD		0xFF02FD
#define IR_CODE_BKD		0xFFC23D
#define IR_CODE_EQ		0xFFE01F
#define IR_CODE_MINUS	0xFFA857
#define IR_CODE_PLUS	0xFF906F
#define IR_CODE_0		0xFF6897
#define IR_CODE_CROSS	0xFF9867
#define IR_CODE_SD		0xFFB04F
#define IR_CODE_1		0xFF30CF
#define IR_CODE_2		0xFF18E7
#define IR_CODE_3		0xFF7A85
#define IR_CODE_4		0xFF10EF
#define IR_CODE_5		0xFF38C7
#define IR_CODE_6		0xFF5AA5
#define IR_CODE_7		0xFF42BD
#define IR_CODE_8		0xFF4AB5
#define IR_CODE_9		0xFF52AD

#endif