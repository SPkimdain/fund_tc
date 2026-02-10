
/* RL_005 - RETURN_LOCAL struct example */


struct RL_005_struct{
	int val;
	int val2;
	int* ptr2;	
};

RL_005_struct* RL_005_function(int val, int val2, int* ptr2){
	RL_005_struct str;
	str.val = val;
    str.val2 = val2;
	str.ptr2 = ptr2;
	return &str; //@violation RETURN_LOCAL
}