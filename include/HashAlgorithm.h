#ifndef __HASH_ALGORITHM_H__
#define __HASH_ALGORITHM_H__

#include <sha.h>
#include <string>

#include <Error.h>

#define NUM_HASH_ALGORITHMS	20

namespace HASH_ALGORITHM {
	enum {
		BLAKE2S,
		BLAKE2B,
		KECCAK,
		MD2,
		MD4,
		MD5,
		RIPEMD160,
		RIPEMD320,
		RIPEMD128,
		RIPEMD256,
		SHA1,
		SHA224,
		SHA256,
		SHA3,
		SHA384,
		SHA512,
		SIPHASH,
		SM3,
		TIGER,
		WHIRLPOOL,
	};

	class HashAlgorithm {
	public:
		HashAlgorithm(unsigned int);
		~HashAlgorithm();
		int generate(std::string, std::string);
	private:
		unsigned int	algorithm;
		union {
			CryptoPP::SHA1		sha1;
			CryptoPP::SHA224	sha224;
			CryptoPP::SHA256	sha256;
			CryptoPP::SHA384	sha384;
			CryptoPP::SHA512	sha512;
		};

		bool valid();

		typedef int (*HashGenerator)(std::string, std::string);
		HashGenerator implementations[NUM_HASH_ALGORITHMS];
	};
}
#endif
