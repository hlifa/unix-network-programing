#include "unp.h"

int main(int argc, char ** argv) {
	int sockfd, n;
	char readline[MAXLINE + 1];
	struct sockaddr_in servaddr;

	if (argc != 2) {
		err_quit("usage: %s <IPaddress>", argv[0]);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		err_sys("socket error");
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	if ((inet_pton(AF_INET, argv[1], &servaddr.sin_addr)) <= 0) {
		err_quit("inet_pton error for %s", argv[1]);
	}

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
		err_sys("connect error");

	int readcnt = 0;
	while ((n = read(sockfd, readline, MAXLINE)) > 0) {
		readline[n] = 0; // null terminate
		if (fputs(readline, stdout) == EOF) {
			err_sys("fputs error");
		}
		readcnt++;
	}

	if (n < 0) {
		err_sys("read error");
	}

	fprintf(stdout, "readcount=%i\n", readcnt);
	exit(0);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
