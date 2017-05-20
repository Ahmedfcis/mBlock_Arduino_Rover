#include "IRremote_ard.h"
#include "IRremoteExt.h"
#include <Arduino.h>

IRrecv* __irrecv; // an instance of the IR receiver object
decode_results __results; // container for received IR codes

__ir_handler_type 	__ir_handler[2][21];
unsigned long		__ir_handler_code[21];
int   				__ir_handler_count=0;
int					__last_code_H=-1;
unsigned long		__last_code=REPEAT;
unsigned long		__last_Rel_code=REPEAT;
unsigned long		__prev_millis=0;

void beginIRremote(int pin){
	__irrecv = new IRrecv(pin);
	__irrecv->enableIRIn(); // Start the receiver
}

void addPressHandlerIRremote(unsigned long code, __ir_handler_type func){
		
	for(int i=0;i<__ir_handler_count;i++)
		if(__ir_handler_code[i] == code){
			__ir_handler[0][i] = func;
			return;
		}
	
	if(__ir_handler_count >= 21)
		return;
	
	__ir_handler_code[__ir_handler_count] = code;
	__ir_handler[0][__ir_handler_count] = func;
	__ir_handler[1][__ir_handler_count++] = NULL;
}

void addReleaseHandlerIRremote(unsigned long code, __ir_handler_type func){
		
	for(int i=0;i<__ir_handler_count;i++)
		if(__ir_handler_code[i] == code){
			__ir_handler[1][i] = func;
			return;
		}
	
	if(__ir_handler_count >= 21)
		return;
	
	__ir_handler_code[__ir_handler_count] = code;
	__ir_handler[1][__ir_handler_count] = func;
	__ir_handler[0][__ir_handler_count++] = NULL;
}

void handelIRremote(){
	
	if (__irrecv->decode(&__results)) {
		__prev_millis =  millis();
		if(__results.value == REPEAT){
			__irrecv->resume(); // Receive the next value
			return;
		}
		
		__last_code = __results.value;
		
		for(int i=0;i<__ir_handler_count;i++)
			if(__results.value == __ir_handler_code[i]){
				if(__ir_handler[0][i]) __ir_handler[0][i](__results.value);
				__last_code_H = i;
				break;
			}
		
		__irrecv->resume(); // Receive the next value
		return;
	}
	
	unsigned long cur_millis = millis();
	if(__last_code != REPEAT && (cur_millis - __prev_millis) > 200){
		
		if(__last_code_H != -1 && __ir_handler[1][__last_code_H]){
			__ir_handler[1][__last_code_H](__last_code);
			__last_code_H = -1;
		}
		__last_Rel_code = __last_code;
		__last_code = REPEAT;
	}
}

unsigned long getPressedIRremote(){
	return __last_code;
}

bool isReleasedIRremote(unsigned long code){
	if(code == __last_Rel_code){
		__last_Rel_code = REPEAT;
		return true;
	}
	
	return false;
}
