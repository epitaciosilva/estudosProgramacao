int fatorial(int num) {
	if(num > 1) {
		return num*fatorial(num-1); 
	}

	return 1;
}