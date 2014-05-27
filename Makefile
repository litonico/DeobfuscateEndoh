# scratch: scratchpad.c
# 	gcc -g -Wall -W -pedantic scratchpad.c -o scratch

deobfuscated: endoh1_deobfuscate.c
	gcc -g -Wall -W -pedantic -D_BSD_SOURCE -std=c99 -DGravity=1 -DPressure=4 -DVelocity=4 endoh1_deobfuscate.c -o endoh1_deobfuscate -lm

obfuscated: endoh1.c
	gcc -g -Wall -W -pedantic -D_BSD_SOURCE -std=c99 -DG=1 -DP=4 -DV=4 endoh1.c -o endoh1 -lm

run_obfuscated:
	./endoh1 < endoh1.c 

run:
	@ruby -e "puts 'Can\'t let you do that, Fox!'"
	@ruby -e "puts 'Don\'t run this from Vim or any non-interactive shell- continue? Y/n '"
	@ruby -e "yn = gets;                                \
              if (yn =~ /[Yy](es)?/);                   \
                exec './endoh1_deobfuscate < endoh1.c'  \
              else                                      \
                exit                                    \
              end"
