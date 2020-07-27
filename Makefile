# Compiler options
CXX              = g++
CFLAGS           = -Werror -std=c++17

# Commands
RM_RF            = rm -rf
MKDIR            = mkdir
MAKE             = make -j$(nproc)
MAKE_C           = $(MAKE) -C

# Build required libraries
# cryptopp
INCLUDE_PATH     = include
LIB_CRYPTOPP_DIR = lib/cryptopp
LIB_CRYPTOPP     = libcryptopp.so
OUT_DIR          = out
OUT_FINCRYPT     = Fincrypt
SOURCE_DIR       = source

# Update include paths
INC              = -I$(INCLUDE_PATH) -I$(LIB_CRYPTOPP_DIR)

LIBS             = -L$(LIB_CRYPTOPP_DIR)

libs:
	$(MAKE_C) $(LIB_CRYPTOPP_DIR) $(LIB_CRYPTOPP)

fincrypt:
	$(MKDIR) $(OUT_DIR)
	$(CXX) $(CFLAGS) $(INC) $(LIBS) \
		-lcryptopp $(SOURCE_DIR)/Fincrypt.cpp \
		-o $(OUT_DIR)/$(OUT_FINCRYPT)

all:
	$(libs)
	$(fincrypt)

clean:
	$(MAKE_C) $(LIB_CRYPTOPP_DIR) clean
	$(RM_RF) $(OUT_DIR)
