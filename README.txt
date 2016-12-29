How to generate files:
1) make
2) ./test.out <number of files to create>
3) cat -e toutA toutB toutC etc.

+++
There is a sh script 10_random. . . that will check your executable (a.out) vs. 10
randomly generated files and perform a diff.

This is useful at the end to test against a bunch of random files instead
of creating one off files test with.

Finally, at the top of the main there are a bunch of defines that handle the parameters
for the file sizes.

That's it!
