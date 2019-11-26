#include "stdafx.h"

Sampler::Sampler() {
}

Sampler::~Sampler() {
	if (this)
		delete this;
}

const char* Sampler::toString(CONFIG_SAMPLER_ENUM i) {
	return CONFIG_SAMPLER_ENUM_STRING[i];
}

CONFIG_SAMPLER_ENUM Sampler::toEnum(const char* i) {
	return mapStringEnum[i];
}