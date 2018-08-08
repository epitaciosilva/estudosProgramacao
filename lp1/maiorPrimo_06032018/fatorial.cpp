int fatorial(int num) {
	if(num > 1) {
		return num*fatorial(num-1); 
	}

	return 1;
}

//Uma forma de utilizar menos memória
int fatorialCauda(int num, int parcial) {
	if(num == 1) {
		return parcial;
	}

	return fatorialCauda(num-1, num*parcial);
}
