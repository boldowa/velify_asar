/**
 * Asar function feature test source
 */

#include "functest.h"
#include "asardll.h"

bool vdebug = false;

void putasarerr()
{
	int nums;
	int ctr;

	const struct errordata* err;

	err = asar_geterrors(&nums);

	puterror("Number of errors: %d", nums);
	if(0 == nums)
	{
		puterror("Asm error is nothing! Why did assemble fail?");
	}

	for(ctr=0; ctr<nums; ctr++)
	{
		puterror("%s", err[ctr].fullerrdata);
		puterror("%s", err[ctr].rawerrdata);
	}

}

#define BufLen 32
int main(int argc, char** argv)
{
	int  asarVersion;
	char bin[BufLen];
	int  binLen = 0;
	bool isSuccess;

	if(false == asar_init())
	{
		putfatal("Asar initialize is failed...");
		return -1;
	}

	if (4 != argc)
	{
		printf("Usage: %s <asm1> <asm2> <failasm>\n", argv[0]);
		return -1;
	}

	/* Put asar version */
	asarVersion = asar_version();
	printf("Asar lib version: %d.%d.%d\n",
			asarVersion/10000,
			asarVersion%10000/100,
			asarVersion%100);

	/* clean up ... */
	memset(bin, 0, BufLen);

	/* clean up ... */
	memset(bin, 0, BufLen);
	putinfo("*** First, it assemble the fail case asm.");
	isSuccess = asar_patch(argv[3], bin, 32, &binLen);
	printf("Assemble failcase : %s\n",
			isSuccess ? "SUCCESS" : "FAIL");
	if(true == isSuccess)
	{
		putasarerr();
		puterror(" ***** Invalid test code. *****");
		puterror("    ... this assemble have to be fail.");
		asar_close();
		return -1;
	}

	putinfo("*** Fail check passed, so let's start test.\n");

	/* clean up ... */
	memset(bin, 0, BufLen);

	/**
	 * Notice : Disable comment-out if you plan to clean
	 *          the errored flag when asar_reset() called.
	 */
	//asar_reset();


	isSuccess = asar_patch(argv[1], bin, 32, &binLen);
	printf("Assemble pass1 : %s\n",
			isSuccess ? "SUCCESS" : "FAIL");
	if(false == isSuccess)
	{
		putasarerr();
		puterror(" ***** Probably the errored flag isn't cleaned... *****");
		asar_close();
		return -1;
	}
	putinfo("***** OK, probably errored flag is cleaned.");


	/* clean up ... */
	memset(bin, 0, BufLen);

	putinfo("***** Then, test initialization of user function.");
	isSuccess = asar_patch(argv[1], bin, 32, &binLen);
	printf("Assemble pass2 : %s\n",
			isSuccess ? "SUCCESS" : "FAIL");
	if(false == isSuccess)
	{
		putasarerr();
		putinfo(" --- User functions are not cleaned... ---");
		asar_close();
		return -1;
	}

	/* clean up ... */
	memset(bin, 0, BufLen);

	putinfo("***** Test initialization of user function in another file.");
	isSuccess = asar_patch(argv[2], bin, 32, &binLen);
	printf("Assemble another : %s\n",
			isSuccess ? "SUCCESS" : "FAIL");
	if(false == isSuccess)
	{
		putasarerr();
		putinfo(" --- User functions are not cleaned... ---");
		asar_close();
		return -1;
	}

	asar_close();

	putinfo(" --- Worked fine! Assembled collectly. --- ");
	return 0;
}

