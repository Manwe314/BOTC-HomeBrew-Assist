# BOTC-HomeBrew-Assist
simple terminal program to help with making of homebrew characters.

to compile in the terminal run "make" [$> make]
an executable named assistant will be compiled.

to use, in the terminal type: [$> ./assistant <types.txt> <characters.txt>]

to use correctly you must format both files:

1. both must be .txt files!
2. types.txt file must be bult as follows: [positive integer index][period][arbitrary amount of space][The description of type][new line]
3. characters.txt must be bult as follows: [arbitrary amount of space][positive integer index][new line]

there is no limit to amount of lines each file may have.
characters.txt may have more positive integer indexes per line, all spaced out by at least one space ofcourse.

the output.txt file created will match every index in each row of characters.txt to type descriptions of the same index in types.txt.
output will be built as follows: character [number]: [description matching index] | [description matching index] ...

if a match can not be found nothing will be outputed for that index.
if an index is found but has no description an [EMPTY] will be written instead

this program is mainly used to map "types" or "descriptions" to "characters" when trying to build a finite projective map type of interacction between characters.
for more information -> https://en.wikipedia.org/wiki/Projective_plane

the provided char.txt and types.txt contain some example text in the context of Blood on the Clocktower.
to get an example output run: "./assistant types.txt char.txt"
look at ouput.txt to get an idea of what this is used for

makefile also has clean (reamove oject files) and fclean (clean + remove executable) calls
makefile also has re (fclean + make) and all (same as make) calls