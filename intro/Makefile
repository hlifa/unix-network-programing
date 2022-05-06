include ../Make.defines

PROGS = daytimetcpcli daytimetcpserv

all: ${PROGS}

daytimetcpcli: daytimetcpcli.o
	${CC} ${CFLAGS} -o $@ daytimetcpcli.o ${LIBS} 

daytimetcpserv: daytimetcpserv.o
	${CC} ${CFLAGS} -o $@ daytimetcpserv.o ${LIBS} 

clean:
	rm -rf ${PROGS} ${CLEANFILES}
