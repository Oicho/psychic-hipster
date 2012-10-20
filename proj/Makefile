all:
	gcc -W -Wall -Werror -std=c99 -c print_helps.c
	gcc -W -Wall -Werror -std=c99 print_helps.c signal_act.c svwatch.c -o svwatch
#	gcc -W -Wall -Werror -std=c99 svmonitor.c -o svmonitor

clean:
	rm -f svmonitor
	rm -f svwatch
	rm -f print_helps.o

distclean:clean
	rm -f *~ *#