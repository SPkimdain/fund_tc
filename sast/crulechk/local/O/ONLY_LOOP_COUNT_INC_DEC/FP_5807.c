//@checker ONLY_LOOP_COUNT_INC_DEC
// There should be no alarms here!
void foo(char* entries, unsigned int entrylen){
	char const *entry;
	for (entry = entries; *entry; entry += entrylen + 1) {
		// something
	}
}
