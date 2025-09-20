/*
Reni Zani, rzani@myseneca.ca, 166082222
Date Completed : 2025/09/20
I declare that this submission is the result of my own work and
I only copied the code that my professor provided to complete my assignments.
This submitted piece of work has not been shared with any other student or 3rd party content provider.
*/
#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include "settings.h"
using namespace std;
namespace seneca {
    Dictionary::Dictionary() : d_words{ nullptr }, d_size{ 0 } {}

    Dictionary::Dictionary(const Dictionary& d) : d_words(nullptr), d_size(d.d_size) {
        if (d_size > 0) {
            d_words = new Word[d_size];
            for (size_t i = 0; i < d_size; i++) {
                d_words[i] = d.d_words[i];
            }
        }
    }

    Dictionary& Dictionary::operator=(const Dictionary& d) {
        if (this != &d) {
            delete[] d_words;
            d_size = d.d_size;
            d_words = nullptr;
            if (d_size > 0) {
                d_words = new Word[d_size];
                for (size_t i = 0; i < d_size; i++) {
                    d_words[i] = d.d_words[i];
                }
            }
        }
        return *this;
    }

    Dictionary::Dictionary(Dictionary&& d) noexcept {
        d_words = d.d_words;
        d_size = d.d_size;
        d.d_words = nullptr;
        d.d_size = 0;
    }

    Dictionary& Dictionary::operator=(Dictionary&& d) noexcept {
        if (this != &d) {
            delete[] d_words;

            d_words = d.d_words;
            d_size = d.d_size;

            d.d_words = nullptr;
            d.d_size = 0;
        }
        return *this;
        }

    Dictionary::Dictionary(const char* filename) : d_words(nullptr), d_size(0) {
        ifstream file(filename);
        if (!file) return;

        d_size = 0;
        string line;
        while (getline(file, line)) {
            if (!line.empty()) d_size++;
        }

        file.clear();
        file.seekg(0);

        d_words = new Word[d_size];
        size_t i = 0;

        while (i < d_size) {
            string name, pos, definition;

            if (!getline(file, name, ',')) break;
            if (!getline(file, pos, ',')) break;
            if (!getline(file, definition)) break;

            d_words[i].m_word = name;
            d_words[i].m_pos = posChecker(pos);
            d_words[i].m_definition = definition;
            i++;
        }
        file.close();
    }

    void Dictionary::searchWord(const char* word) {
        bool found = false;
        bool firstMatch = true;

        const string w = word;
        string indent(w.length(), ' ');

        for (size_t i = 0; i < d_size; i++) {
            if (d_words[i].m_word == word) {
                found = true;

                string pos;
                if (g_settings.m_verbose && d_words[i].m_pos != PartOfSpeech::Unknown) {
                    pos = "(" + posString(d_words[i].m_pos) + ") ";
                }

                if (firstMatch) {
                    cout << w << " - " << pos << d_words[i].m_definition << endl;
                    firstMatch = false;
                }
                else {
                    cout << indent << " - " << pos << d_words[i].m_definition << endl;
                }
                if (!g_settings.m_show_all) break;
            }
        }

        if (!found) {
            cout << "Word '" << word << "' was not found in the dictionary." << endl;
        }
    }

    PartOfSpeech Dictionary::posChecker(const string& pos) {
        if (pos == "n." || pos == "n. pl.") return PartOfSpeech::Noun;
        if (pos == "adv.") return PartOfSpeech::Adverb;
        if (pos == "a.") return PartOfSpeech::Adjective;
        if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") return PartOfSpeech::Verb;
        if (pos == "prep.") return PartOfSpeech::Preposition;
        if (pos == "pron.") return PartOfSpeech::Pronoun;
        if (pos == "conj.") return PartOfSpeech::Conjunction;
        if (pos == "interj.") return PartOfSpeech::Interjection;
        return PartOfSpeech::Unknown;
    }

    string Dictionary::posString(PartOfSpeech pos) {
        switch (pos) {
        case PartOfSpeech::Noun: return "noun";
        case PartOfSpeech::Pronoun: return "pronoun";
        case PartOfSpeech::Adjective: return "adjective";
        case PartOfSpeech::Adverb: return "adverb";
        case PartOfSpeech::Verb: return "verb";
        case PartOfSpeech::Preposition: return "preposition";
        case PartOfSpeech::Conjunction: return "conjunction";
        case PartOfSpeech::Interjection: return "interjection";
        default: return "";
        }
    }

    Dictionary::~Dictionary() {
        delete[] d_words;
    }
}