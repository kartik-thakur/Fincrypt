#ifndef __ERROR_H_
#define __ERROR_H_

#include <exception>

#ifndef ENOENT
#define ENOENT 2
#endif

#ifndef EINVAL
#define EINVAL 22
#endif

class InvalidAlgorithmException : public std::exception {
public:
	unsigned int algorithm;

	InvalidAlgorithmException(unsigned int _algorithm):
		algorithm(_algorithm) {}

	int what() {
		return algorithm;
	}
};

#endif
