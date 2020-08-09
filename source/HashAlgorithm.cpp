#include <HashAlgorithm.h>

using namespace HASH_ALGORITHM;

HashAlgorithm::HashAlgorithm(unsigned int _algorithm):
	algorithm(_algorithm)
{
	auto unimplemented = [] (std::string source, std::string hash) {
					return -ENOENT;
			      };

	/* Check if provided values are correct.
	 * Throw an InvalidAlgorithmException if algorithm is incorrect.
	 */
	if (!valid())
		throw InvalidAlgorithmException(algorithm);

	implementations[BLAKE2S]	= unimplemented;
	implementations[BLAKE2B]	= unimplemented;
	implementations[KECCAK]		= unimplemented;
	implementations[MD2]		= unimplemented;
	implementations[MD4]		= unimplemented;
	implementations[MD5]		= unimplemented;
	implementations[RIPEMD128]	= unimplemented;
	implementations[RIPEMD160]	= unimplemented;
	implementations[RIPEMD256]	= unimplemented;
	implementations[RIPEMD320]	= unimplemented;
	implementations[SHA1]		= unimplemented;
	implementations[SHA224]		= unimplemented;
	implementations[SHA256]		= unimplemented;
	implementations[SHA3]		= unimplemented;
	implementations[SHA384]		= unimplemented;
	implementations[SHA512]		= unimplemented;
	implementations[SIPHASH]	= unimplemented;
	implementations[SM3]		= unimplemented;
	implementations[TIGER]		= unimplemented;
	implementations[WHIRLPOOL]	= unimplemented;
}

HashAlgorithm::~HashAlgorithm() {}

bool HashAlgorithm::valid()
{
	return algorithm > NUM_HASH_ALGORITHMS ? false : true;
}

int HashAlgorithm::generate(std::string source, std::string hash)
{
	return 0;
}
