
#include <stdio.h>
#include <string.h>
#include "../License/gen_license.h"

#define LICENSE	"license.dat"

int main(int argc, char **argv)
{
	char	mach_info[1024];
	char	version[1024];
	char	lic_file[1024];

	if (argc != 3)
	{
		printf("Usage: GenLicense machine.info  software_version\n");
		return	0;
	}

	strcpy(mach_info, argv[1]);
	strcpy(version, argv[2]);
	strcpy(lic_file, LICENSE);

	gen_license(mach_info, version, lic_file);
	printf("%s is writen!\n", LICENSE);
	return	0;
}
