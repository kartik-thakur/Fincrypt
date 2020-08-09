#include <iostream>

#include <channels.h>
#include <files.h>
#include <filters.h>
#include <hex.h>
#include <HashAlgorithm.h>

using namespace HASH_ALGORITHM;

HashAlgorithm::HashAlgorithm(unsigned int _algorithm):
	algorithm(_algorithm)
{
	/* Check if provided values are correct.
	 * Throw an InvalidAlgorithmException if algorithm is incorrect.
	 */
	if (!valid())
		throw InvalidAlgorithmException(algorithm);

	initializeImplementations();
}

bool HashAlgorithm::valid()
{
	return algorithm > NUM_HASH_ALGORITHMS ? false : true;
}

int HashAlgorithm::generate(std::string source, std::string &hash,
			    bool filesource)
{
	return implementations[algorithm](source, hash, filesource);
}

void HashAlgorithm::initializeImplementations()
{
	auto unimplemented  = [] (std::string source, std::string &hash,
				  bool filesource) {
		return -ENOENT;
	};

	auto sha1 = [] (std::string source, std::string &hash,
			  bool filesource) {
		CryptoPP::SHA1 sha;
		CryptoPP::ChannelSwitch channelSwitch;
		CryptoPP::HashFilter hashFilter(sha, new CryptoPP::HexEncoder(
					new CryptoPP::StringSink(hash)));

		channelSwitch.AddDefaultRoute(hashFilter);

		if (filesource) {
			try {
				CryptoPP::FileSource(source.c_str(), true,
				new CryptoPP::Redirector(channelSwitch));
			}
			catch (const CryptoPP::Exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else {
			CryptoPP::StringSource(source, true,
				new CryptoPP::Redirector(channelSwitch));
		}

		return 0;
	};

	auto sha224 = [] (std::string source, std::string &hash,
			  bool filesource) {
		CryptoPP::SHA224 sha;
		CryptoPP::ChannelSwitch channelSwitch;
		CryptoPP::HashFilter hashFilter(sha, new CryptoPP::HexEncoder(
					new CryptoPP::StringSink(hash)));

		channelSwitch.AddDefaultRoute(hashFilter);

		if (filesource) {
			try {
				CryptoPP::FileSource(source.c_str(), true,
				new CryptoPP::Redirector(channelSwitch));
			}
			catch (const CryptoPP::Exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else {
			CryptoPP::StringSource(source, true,
				new CryptoPP::Redirector(channelSwitch));
		}

		return 0;
	};

	auto sha256 = [] (std::string source, std::string &hash,
			  bool filesource) {
		CryptoPP::SHA256 sha;
		CryptoPP::ChannelSwitch channelSwitch;
		CryptoPP::HashFilter hashFilter(sha, new CryptoPP::HexEncoder(
					new CryptoPP::StringSink(hash)));

		channelSwitch.AddDefaultRoute(hashFilter);

		if (filesource) {
			try {
				CryptoPP::FileSource(source.c_str(), true,
				new CryptoPP::Redirector(channelSwitch));
			}
			catch (const CryptoPP::Exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else {
			CryptoPP::StringSource(source, true,
				new CryptoPP::Redirector(channelSwitch));
		}

		return 0;
	};

	auto sha384 = [] (std::string source, std::string &hash,
			  bool filesource) {
		CryptoPP::SHA384 sha;
		CryptoPP::ChannelSwitch channelSwitch;
		CryptoPP::HashFilter hashFilter(sha, new CryptoPP::HexEncoder(
					new CryptoPP::StringSink(hash)));

		channelSwitch.AddDefaultRoute(hashFilter);

		if (filesource) {
			try {
				CryptoPP::FileSource(source.c_str(), true,
				new CryptoPP::Redirector(channelSwitch));
			}
			catch (const CryptoPP::Exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else {
			CryptoPP::StringSource(source, true,
				new CryptoPP::Redirector(channelSwitch));
		}

		return 0;
	};

	auto sha512 = [] (std::string source, std::string &hash,
			  bool filesource) {
		CryptoPP::SHA512 sha;
		CryptoPP::ChannelSwitch channelSwitch;
		CryptoPP::HashFilter hashFilter(sha, new CryptoPP::HexEncoder(
					new CryptoPP::StringSink(hash)));

		channelSwitch.AddDefaultRoute(hashFilter);

		if (filesource) {
			try {
				CryptoPP::FileSource(source.c_str(), true,
				new CryptoPP::Redirector(channelSwitch));
			}
			catch (const CryptoPP::Exception& e) {
				std::cout << e.what() << std::endl;
			}
		} else {
			CryptoPP::StringSource(source, true,
				new CryptoPP::Redirector(channelSwitch));
		}

		return 0;
	};

	for (HashGenerator implementation: implementations)
		implementation = unimplemented;

	implementations[SHA1]   = sha1;
	implementations[SHA224] = sha224;
	implementations[SHA256] = sha256;
	implementations[SHA384] = sha384;
	implementations[SHA512] = sha512;
}
