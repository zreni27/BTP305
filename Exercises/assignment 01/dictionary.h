/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include <string>
namespace seneca {
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};
	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};

	class Dictionary {
		Word* d_words;
		size_t d_size;
	public:
		Dictionary();

		Dictionary(const Dictionary&);
		Dictionary& operator=(const Dictionary&);

		Dictionary(Dictionary&&) noexcept;
		Dictionary& operator=(Dictionary&&) noexcept;

		Dictionary(const char*);
		void searchWord(const char*);

		PartOfSpeech posChecker(const std::string&);
		std::string posString(PartOfSpeech);

		~Dictionary();
	};
}
#endif