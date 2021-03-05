Assignment104: Assignment104.c
	gcc Assignment104.c -o Assignment104

debug: Assignment104.c
	gcc -o Assignment104 -ggdb3 Assignment104.c

clean: 
	rm -f Assignment104
