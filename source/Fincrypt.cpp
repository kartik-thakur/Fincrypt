#include <iostream>
#include <string>

#include <Error.h>
#include <HashAlgorithm.h>

int main()
{
	try {
		HASH_ALGORITHM::HashAlgorithm algorithm(HASH_ALGORITHM::SHA512);
		std::string source = "test_file.bin";
		std::string hash = "";

		algorithm.generate(source, hash, true);

		std::cout << hash << std::endl;
	}
	catch (InvalidAlgorithmException e) {
		std::cout << e.what();
	}

	return 0;
}
