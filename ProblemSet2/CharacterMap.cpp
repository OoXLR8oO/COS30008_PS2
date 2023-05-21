#include "CharacterMap.h"


CharacterMap::CharacterMap(unsigned char aCharacter, int aFrequency) noexcept:
	fCharacter(aCharacter),
	fFrequency(aFrequency)
{}

void CharacterMap::increment() noexcept
{
	fFrequency += 1;
}
void CharacterMap::setCharacter(unsigned char aCharacter) noexcept
{
	fCharacter = aCharacter;
}

bool CharacterMap::operator<(const CharacterMap& aOther) const noexcept
{
	return frequency() < aOther.frequency();
}

unsigned char CharacterMap::character() const noexcept
{
	return fCharacter;
}
size_t CharacterMap::frequency() const noexcept
{
	return fFrequency;
}