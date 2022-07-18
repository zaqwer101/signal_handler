#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
	FILE *file = fopen("/var/log/signal.log","a");
	fprintf(file, "%d", signum);
	fprintf(file, "%s", "\n");
	fclose(file);
}

int main() {
	signal(SIGSEGV, signal_handler);
	signal(SIGINT,  signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGALRM, signal_handler);
	signal(SIGKILL, signal_handler);
  
	while(1) { }

	return 0;
}
