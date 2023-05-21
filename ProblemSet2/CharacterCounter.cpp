#include "CharacterCounter.h"

CharacterCounter::CharacterCounter() noexcept :
	fTotalNumberOfCharacters(),
	fCharacterCounts()
{}

void CharacterCounter::count(unsigned char aCharacter) noexcept
{
	fTotalNumberOfCharacters++;
	fCharacterCounts[aCharacter].setCharacter(aCharacter);
	fCharacterCounts[aCharacter].increment();  
}

const CharacterMap& CharacterCounter::operator[](unsigned char aCharacter) const noexcept
{
	return fCharacterCounts[aCharacter];
}