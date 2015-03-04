tackle.o : tackle.h tackle.c
	cc -c tackle.h tackle.c
testMain.o : testMain.c
	cc -c testMain.c
GetBashOutput.o : GetBashOutput.h GetBashOutput.c
	cc -c GetBashOutput.h GetBashOutput.c
testMain : testMain.o GetBashOutput.o tackle.o
	cc testMain.o GetBashOutput.o tackle.o -o testMain
Inter:
	rm -f *.o *.gch
Target:
	rm -f testMain Main lib*.so lib*.a
