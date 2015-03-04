tackle.o : tackle.h tackle.c
	cc -c tackle.h tackle.c -IVersion1.0/
testMain.o : testMain.c
	cc -c testMain.c -IVersion1.0/
GetBashOutput.o : GetBashOutput.h GetBashOutput.c
	cc -c GetBashOutput.h GetBashOutput.c -IVersion1.0/
testMain : testMain.o GetBashOutput.o tackle.o
	cc testMain.o GetBashOutput.o tackle.o -o testMain -IVersion1.0/
Inter:
	rm -f *.o *.gch
Target:
	rm -f testMain Main lib*.so lib*.a
