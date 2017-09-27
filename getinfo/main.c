#include "get_localinfo.h"

#define INFOFILE	"machine.info"

int main(int argc, char **argv)
{
	write_machine_info_file(INFOFILE);
	printf("%s is writen for this computer!\n", INFOFILE);
	return	0;
}

