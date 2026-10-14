struct intpair {
	int a;
	int b;
};

program CALCULATOR {
		version CALC_VERS {
			int ADD(intpair) = 1;
                        int MULT(intpair) = 2;
	} = 1;
} = 0x234511EF;

