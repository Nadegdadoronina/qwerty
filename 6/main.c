

void print(){
	int add	= 0xB8000;
	int i;
	for(i=0; i<80*25;++i)
	{
		*((short int *)add) =  0x0000;
		add+=2;
	}

	add = 0xB8000;



	*((short int *)add) =  0x0F00 + '=';
        add+=2;
	*((short int *)add) =  0x0F00 + ')';
	

	return;
}

