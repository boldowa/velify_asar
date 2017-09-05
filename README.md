# Asar issue verification

This is a project for velify Asar's issue.

## Issues
- ["errored" flag isn't cleaned](https://github.com/boldowa/Asar/issues/2)
- [Userfunc isn't cleaned](https://github.com/RPGHacker/asar/issues/2)


## How to

for Linux (or mingw)

1. Puts the "libasar.so" in **build** directory.
2. Run "build.sh"

**build.sh** will build test exe and check issue.

### Outputs when issues are left
	-- Configuring done
	-- Generating done
	-- Build files have been written to: /home/nullpon/github/verifcation_asarfunc/build
	[ 33%] Building C object CMakeFiles/functest.dir/functest.c.o
	[ 66%] Building C object CMakeFiles/functest.dir/1.50/asardll.c.o
	[100%] Linking C executable functest
	[100%] Built target functest
	Asar lib version: 1.5.0
	[INFO ] \*\*\* First, it assemble the fail case asm.
	Assemble failcase : FAIL
	[INFO ] \*\*\* Fail check passed, so let's start test.
	
	Assemble pass1 : FAIL
	[ERROR] Number of errors: 0
	[ERROR] Asm error is nothing! Why did assemble fail?
	[ERROR]  \*\*\*\*\* Probably the errored flag isn't cleaned... \*\*\*\*\*
	make[2]: \*\*\* [CMakeFiles/ftest.dir/build.make:57: CMakeFiles/ftest] Error 255
	make[1]: \*\*\* [CMakeFiles/Makefile2:68: CMakeFiles/ftest.dir/all] Error 2
	make: \*\*\* [Makefile:84: all] Error 2

### Outputs when issues are closed
	-- Configuring done
	-- Generating done
	-- Build files have been written to: /home/nullpon/github/verifcation_asarfunc/build
	[ 33%] Building C object CMakeFiles/functest.dir/functest.c.o
	[ 66%] Building C object CMakeFiles/functest.dir/1.50/asardll.c.o
	[100%] Linking C executable functest
	[100%] Built target functest
	Asar lib version: 1.5.0
	[INFO ] \*\*\* First, it assemble the fail case asm.
	Assemble failcase : FAIL
	[INFO ] \*\*\* Fail check passed, so let's start test.
	
	Assemble pass1 : SUCCESS
	[INFO ] \*\*\*\*\* OK, probably errored flag is cleaned.
	[INFO ] \*\*\*\*\* Then, test initialization of user function.
	Assemble pass2 : SUCCESS
	[INFO ] \*\*\*\*\* Test initialization of user function in another file.
	Assemble another : SUCCESS
	[INFO ]  --- Worked fine! Assembled collectly. ---
	[100%] Built target ftest


