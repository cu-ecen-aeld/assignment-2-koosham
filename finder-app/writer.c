#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char ** argv) {
	openlog(NULL, 0, LOG_USER);

	if (argc != 3) {
		syslog(LOG_ERR, "Expected 2 arguments but got %u", argc);
		return 1;
	}

	char * write_file = argv[1];
	char * write_str = argv[2];
	FILE *file = fopen(write_file, "w");

	if (file == NULL) {
		syslog(LOG_ERR, "Could not create file %s: %s", write_file, strerror(errno));
		return errno;
	}
	
	if (fputs(write_str, file) == EOF) {
		syslog(LOG_ERR, "Could not write to file %s", write_file);
		return 1;
	}

	syslog(LOG_DEBUG, "Writing %s to %s", write_str, write_file);
	fclose(file);
	
	return 0;
}
