Shared Libraries
================

## bluecoinconsensus

The purpose of this library is to make the verification functionality that is critical to Bluecoin's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `bluecoinconsensus.h` located in `src/script/bluecoinconsensus.h`.

#### Version

`bluecoinconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`bluecoinconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `bluecoinconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/bluecoin/bips/blob/master/bip-0016.mediawiki)) subscripts
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/bluecoin/bips/blob/master/bip-0066.mediawiki)) compliance
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/bluecoin/bips/blob/master/bip-0147.mediawiki))
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/bluecoin/bips/blob/master/bip-0065.mediawiki))
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/bluecoin/bips/blob/master/bip-0112.mediawiki))
- `bluecoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/bluecoin/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `bluecoinconsensus_ERR_OK` - No errors with input parameters *(see the return value of `bluecoinconsensus_verify_script` for the verification status)*
- `bluecoinconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `bluecoinconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `bluecoinconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `bluecoinconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used
- `bluecoinconsensus_ERR_INVALID_FLAGS` - Script verification `flags` are invalid (i.e. not part of the libconsensus interface)

### Example Implementations
- [NBluecoin](https://github.com/MetacoSA/NBluecoin/blob/5e1055cd7c4186dee4227c344af8892aea54faec/NBluecoin/Script.cs#L979-#L1031) (.NET Bindings)
- [node-libbluecoinconsensus](https://github.com/bitpay/node-libbluecoinconsensus) (Node.js Bindings)
- [java-libbluecoinconsensus](https://github.com/dexX7/java-libbluecoinconsensus) (Java Bindings)
- [bluecoinconsensus-php](https://github.com/Bit-Wasp/bluecoinconsensus-php) (PHP Bindings)
