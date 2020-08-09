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
		RIPEMD128,
		RIPEMD160,
		RIPEMD320,
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
		int generate(std::string, std::string &, bool);
	private:
		typedef int (*HashGenerator)(std::string, std::string &, bool);

		unsigned int	algorithm;
		bool		valid();
		HashGenerator	implementations[NUM_HASH_ALGORITHMS];

		void initializeImplementations();
	};
}
#endif
