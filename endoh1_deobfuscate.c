// Re-assignment:
// G -> Gravity
// P -> Pressure
// V -> Velocity
// These are read in from command line args

// Endoh:
// "Though some assignments may look meaningless, it is actually meaningful;
// it extracts “integer part of real part” from a complex value by assigning
// (and casting) it to an integer-type variable."

// Essential info: in C, a = b EVALUATES to 0, and performs an assignment
// as a 'side effect.' Assignment in the initialization of a for loop will
// make the compiler complain; when he uses this, Mr. Endoh wraps the
// expressions in parens to silence that.


// Use of the comma operator in C:
// For example, in the statement
// *r++ = w, r
//
// The contents of the address pointed to by r is set to w (a complex double).
// The assignment produces a return value of 0, which the comma promptly discards.
// r is returned (a pointer)
// The contents of r are incremented (postfix operator)
//
// Mr. Endoh uses the comma extensively to perform assignment inline.

#include <stdio.h>//  .IOCCC                                         Fluid-  #
#include <unistd.h>  //2012                                         _Sim!_  #
#include <complex.h>  //||||                     ,____.              IOCCC-  #

double complex	a[97687],
// Endoh: "Every five entries of double complex a[] contain information
// of one particle: position, wall-flag, density, force, and velocity in turn."
       *p, *q, *r = a, w = 0, d;

int	x, y;
char b[6856] = "\x1b[2J" //clears the screen (ANSI escape code). '\x1b' is equivalent to ESC.
               "\x1b[1;1H     "; // Moves the cursor to line 1, char 1
                                 //TODO: unclear if whitespace important

char *o = b, *t;

// The character # represents “wall particle” (a particle with fixed position),
// and any other non-space characters represent free particles.

int main(){

    // Endoh: "This program reads a text from standard input, and uses it as 
    // an initial configuration of the particles."
	for (; 0 < (x = getc(stdin));){ // While the end of stdin is not reached
         w = (x > 10 ? (32 < x ? 4[*r++ = w, r] = w + 1, *r = r[5] = x == 35, r += 9 : 0, w - _Complex_I) : (x = w + 2)); // why the heck were there two semicolons

        // Breaking it down!
        //
        // 4[*r++ = w, r] = w + 1,
        //
        // 4[x] is a weird but valid array access: it's the same as x[4] 
        // for any array x.  The expression x[y] is defined to be *((x)+(y)), 
        // so x and y can be swapped (Kernigan and Ritchie).
        //
        // Again, the comma makes this into a multi-statement instruction
        // *r++ = w; // -> returns 0, which is disregarded
        // r[4] = w+1;
        //
        // Note the order of application in `*r++'! To be a little more clear:
        //
        // *(r++) = w;
        // r[4] = w+1;
        //
        //
        // Okay, next bit
        // *r = r[5] = x == 35,
        //
        // Assignment is right-associative, so let's put some parens in
        //
        // (*r = (r[5] = (x == 35))),
        //  
        // Doesn't really look much better, does it? But we can break it down.
        // x == 35 is a boolean: x is the current character, and 35 is the 
        // ASCII code for '#' (the 'hash' symbol), which Mr. Endoh uses to mark
        // a wall in the simulation.
        //
        // Let's rewrite this as an if statement:
        //
        // *r is r[0]; given the context, that's a little clearer
        //
        // if (x == 35) // if x (the current character) is '#'
        //      // This sets the 'wall flag' for unmoveable particles.
        //      r[0] = r[5] = 1;
        // else 
        //      r[0] = r[5] = 0;
        //
        //
        // More verbose, but more comprehensible!
        //
        // r += 9;
        //

        /*
        if (x > 10){
            //  
            w = (32 < x ? 4[*r++ = w, r] = w + 1, *r = r[5] = x == 35, r += 9 : 0, (w - _Complex_I));
            
            if (x > 32){
                w = 4[*r++ = w, r] = w + 1, *r = r[5] = x == 35, r += 9;
            }
            else{
                w = 0, w - _Complex_I;
            }
            //
        }
        else {
            x = w + 2;
            w = x;
        }
        
        */
 
    }

	for (;; puts(o), o = b + 4) { // The SPH algorithm
        // while(true){ 
        // puts(o) // clears the screen, returns 0 (probably- need to check the value of o)
        // the comma discards the return value
        // o = b + 4 // o points to the 4th elem of b

		for (p = a; p[2] = p[1] * 9, p < r; p += 5){
			for (q = a; w = cabs(d = *p - *q) / 2 - 1, q < r; q += 5){
				if (0 < (x = 1 - w)){
					p[2] += w * w;
                }
            }
        }

        // Iterate over the positions(?) of particles
		for (p = a; p[3] = Gravity, p < r; p += 5){
			for (q = a; w = cabs(d = *p - *q) / 2 - 1, q < r; q += 5){
				if (0 < (x = 1 - w)){
					p[3] += w * (d * (3 - p[2] - q[2]) * Pressure + p[4] * Velocity - q[4] * Velocity) / p[2];
                }
            }
        }

		for (x = 011; 2012 - 1 > x++;){ // 011 is ASCII horizontal tab in octal; important?
			b[x] = 0;
        }

		for (p = a; (t = b + 10 + (x = *p * _Complex_I) + 80 * (y = *p / 2), *p += p[4] += p[3] / 10 * !p[1]), p < r; p += 5) {
			x = 0 <= x && x < 79 && 0 <= y && y < 23 ? 1[1[*t |= 8, t] |= 4, t += 80] = 1, *t |= 2 : 0;
        }

		for (x = 011; 2012 - 1 > x++;){ // Render the particles as marching squares
			b[x] = " '`-.|//,\\" "|\\_" "\\/\x23\n"[x % 80 - 9 ? x[b] : 16];; // \x23 is the # (hash) symbol in hex ASCII
            // Maybe uses \x23 instead of # because # is the walls?
            // Uses array offsets to get the appropriate set of chars for the 
            // Marching squares algorithm
            // 0 =  (space)
            // 1 = '
            // 2 = `
            // 3 = - 
            // 4 = 
        }

		usleep(12321);
	} 
    
    return 0;
}
