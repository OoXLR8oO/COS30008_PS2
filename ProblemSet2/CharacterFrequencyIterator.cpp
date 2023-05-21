#include "CharacterFrequencyIterator.h"
#include <cassert>
#include <algorithm>

CharacterFrequencyIterator::CharacterFrequencyIterator(const CharacterCounter* aCollection) noexcept:
	fCollection(aCollection),
	fIndex(0)
{
	mapIndices(); 
}

void CharacterFrequencyIterator::mapIndices() noexcept
{
	for (size_t i = 0; i < 256; ++i)
	{
		fMappedIndices[i] = static_cast<unsigned char>(i);
	}

	// Sort the character maps in descending order based on frequency using insertion sort
	for (size_t i = 0; i < 256; i++)
	{
		size_t j = i;
		while (j > 0 && (*fCollection)[fMappedIndices[j - 1]].frequency() < (*fCollection)[fMappedIndices[j]].frequency())
		{
			if ((*fCollection)[fMappedIndices[j - 1]].frequency() != (*fCollection)[fMappedIndices[j]].frequency())
			{
				// Swap the mapped indices
				std::swap(fMappedIndices[j - 1], fMappedIndices[j]);
				--j;
			}
		}
	}
}

const CharacterMap& CharacterFrequencyIterator::operator*() const noexcept
{
	return (*fCollection)[fMappedIndices[fIndex]];
}

CharacterFrequencyIterator& CharacterFrequencyIterator::operator++() noexcept
{
	if ((*fCollection)[fMappedIndices[fIndex + 1]].frequency() == 0)
	{
		fIndex = 256;
	}
	else
	{
		fIndex++;
	}
	return *this;
}

CharacterFrequencyIterator CharacterFrequencyIterator::operator++(int) noexcept
{
	CharacterFrequencyIterator lCFIterator = *this; 
	++(*this);
	return lCFIterator;  
}

bool CharacterFrequencyIterator::operator==(const CharacterFrequencyIterator& aOther) const noexcept
{
	return fCollection == aOther.fCollection && fIndex == aOther.fIndex; 
}
bool CharacterFrequencyIterator::operator!=(const CharacterFrequencyIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

CharacterFrequencyIterator CharacterFrequencyIterator::begin() const noexcept
{
	CharacterFrequencyIterator lCopy = *this; 
	lCopy.fIndex = 0; 
	return lCopy; 
}

CharacterFrequencyIterator CharacterFrequencyIterator::end() const noexcept
{
	CharacterFrequencyIterator lResult = *this; 
	lResult.fIndex = 256; 
	return lResult; 
}