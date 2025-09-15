#include "ProteinDatabase.h"
#include <fstream>
#include <functional>

using namespace std;
namespace seneca {

    void ProteinDatabase::set() {
        p_uids = nullptr;
        p_sequence = nullptr;
        p_proteinsStored = 0;
    }
    ProteinDatabase::ProteinDatabase() { set(); }
	
    ProteinDatabase::ProteinDatabase(string filename) {
        ifstream file(filename);
        if (!file) cout << "Cannot open file: " + filename;

        // --- 1st pass: count number of sequences ---
        int count = 0;
        string line;
        while (getline(file, line)) {
            if (!line.empty() && line[0] == '>') count++;
        }

        // --- allocate arrays ---
        p_uids = new string[count];
        p_sequence = new string[count];

        // --- 2nd pass: read sequences and IDs ---
        file.clear();
        file.seekg(0);

        int idx = -1;
        string current_sequence;

        while (getline(file, line)) {
            if (line.empty()) continue;

            if (line[0] == '>') {
                // store previous sequence if exists
                if (idx >= 0) p_sequence[idx] = current_sequence;

                current_sequence.clear(); // start new sequence
                idx++;

                // extract UniqueIdentifier between first and second '|'
                size_t first = line.find('|');
                size_t second = line.find('|', first + 1);
                if (first != string::npos && second != string::npos) {
                    p_uids[idx] = line.substr(first + 1, second - first - 1);
                }
                else {
                    p_uids[idx] = "UnknownUID";
                }
            }
            else {
                current_sequence += line; // accumulate sequence lines
            }
        }

        // store last sequence
        if (idx >= 0) p_sequence[idx] = current_sequence;

        // --- update per-object counter ---
        p_proteinsStored = idx + 1;
    }

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& pb) {
        set();
        *this = pb;
    }

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& pb) {
        if (this != &pb) {
            delete[] p_uids;
            delete[] p_sequence;
            set();
            if (pb.p_uids && pb.p_sequence && pb.p_proteinsStored > 0) {
                p_proteinsStored = pb.p_proteinsStored;
                p_uids = new string[p_proteinsStored];
                p_sequence = new string[p_proteinsStored];
                for (int i = 0; i < p_proteinsStored; i++) {
                    p_uids[i] = pb.p_uids[i];
                    p_sequence[i] = pb.p_sequence[i];
                }
            }
        }
		return *this;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& pb) {
        p_uids = pb.p_uids;
        p_sequence = pb.p_sequence;
        p_proteinsStored = pb.p_proteinsStored;

        pb.p_uids = nullptr;
        pb.p_sequence = nullptr;
        pb.p_proteinsStored = 0;
       }

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& pb) {
        if (this != &pb) {
            delete[] p_uids;
            delete[] p_sequence;

            p_uids = pb.p_uids;
            p_sequence = pb.p_sequence;
            p_proteinsStored = pb.p_proteinsStored;

            pb.p_uids = nullptr;
            pb.p_sequence = nullptr;
            pb.p_proteinsStored = 0;
        }
		return *this;
	}

	size_t ProteinDatabase::size() {
		return p_proteinsStored;
	}

	string ProteinDatabase::operator[](size_t i) {
        if (i >= p_proteinsStored) {
            return "";
        }
        return p_sequence[i];
	}

	string ProteinDatabase::getUID(size_t i) {
        if (i >= p_proteinsStored) {
            return "None";
        }
        else {
            return p_uids[i];
        }
	}

    ProteinDatabase::~ProteinDatabase() {
        delete[] p_uids;
        delete[] p_sequence;
    }
};