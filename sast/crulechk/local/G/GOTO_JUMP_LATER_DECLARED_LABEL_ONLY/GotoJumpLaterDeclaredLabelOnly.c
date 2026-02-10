//@checker GOTO_JUMP_LATER_DECLARED_LABEL_ONLY
void non_compliant(int bar){
	int foo = 0;
label1:	//@b-violation GOTO_JUMP_LATER_DECLARED_LABEL_ONLY
	if(bar == 1){
		return;
	}
	goto label1;	//@violation GOTO_JUMP_LATER_DECLARED_LABEL_ONLY
}

void compliant(int bar){
	int foo = 0;
	goto label2;
	int f = 0;
label2:
	if(bar == 1){
		return;
	}
}