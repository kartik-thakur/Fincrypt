#include <iostream>

#include <Error.h>
#include <HashAlgorithm.h>

int main()
{
	try {
		HASH_ALGORITHM::HashAlgorithm algorithm(HASH_ALGORITHM::SHA256);
	}
	catch (InvalidAlgorithmException e) {
		std::cout << e.what();
	}

	return 0;
}
