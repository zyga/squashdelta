/**
 * SquashFS delta tools
 * (c) 2014 Michał Górny
 * Released under the terms of the 2-clause BSD license
 */

#pragma once
#ifndef SDT_COMPRESSOR_HXX
#define SDT_COMPRESSOR_HXX 1

#ifdef HAVE_CONFIG_H
#	include "config.h"
#endif

#include <cstdlib>

extern "C"
{
#ifdef HAVE_STDINT_H
#	include <stdint.h>
#endif
}

class Compressor
{
public:
	virtual ~Compressor();

	virtual size_t decompress(void* dest, const void* src,
			size_t length, size_t out_size) const = 0;

	virtual uint32_t get_compression_value() const = 0;
};

#ifdef ENABLE_LZO
class LZOCompressor : public Compressor
{
public:
	LZOCompressor();

	virtual size_t decompress(void* dest, const void* src,
			size_t length, size_t out_size) const;

	virtual uint32_t get_compression_value() const;
};
#endif /*ENABLE_LZO*/

#endif /*!SDT_COMPRESSOR_HXX*/
