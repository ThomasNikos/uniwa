struct arg_arr {
    int	n;
    int	arr<>;
};

struct mm {
    int arr<2>;
};

struct aprod {
    float a;
    struct arg_arr arr;
};

struct farr {
    float arr<>;
};

program avg_PROG {
    version avg_VERS {
		float avg(arg_arr) = 1;
    } = 1;
} = 0x20000000;

program minmax_PROG {
    version minmax_VERS {
		struct mm minmax(arg_arr) = 1;
    } = 1;
} = 0x20000001;

program prod_PROG {
    version prod_VERS {
		struct farr prod(aprod) = 1;
    } = 1;
} = 0x20000002;
