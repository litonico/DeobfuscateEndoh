deobfuscated: endoh1_deobfuscate.c
	gcc -Wall -W -pedantic -D_BSD_SOURCE -std=c99 -DGravity=1 -DPressure=4 -DVelocity=4 endoh1_deobfuscate.c -o endoh1_deobfuscate -lm

obfuscated: endoh1.c
	gcc -Wall -W -pedantic -D_BSD_SOURCE -std=c99 -DG=1 -DP=4 -DV=4 endoh1.c -o endoh1 -lm

run_obfuscated:
	./endoh1 < endoh1.c 

run:
	echo "Can't let you do that, Fox!"
	echo "Don't run this from Vim- continue? Y/n"
	./endoh1_deobfuscate < endoh1.c 
