#include "protein_translation.h"

#include <map>

namespace protein_translation {
const string STOP_PROTEIN = "STOP";
const string UNKNOWN_PROTEIN = "UNKNOWN";
const map<string, string> CODON_MAP = {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"},
    {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"},
    {"UUG", "Leucine"},
    {"UCU", "Serine"},
    {"UCC", "Serine"},
    {"UCA", "Serine"},
    {"UCG", "Serine"},
    {"UAU", "Tyrosine"},
    {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"},
    {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", STOP_PROTEIN},
    {"UAG", STOP_PROTEIN},
    {"UGA", STOP_PROTEIN},
};

string translate_codon(string codon) {
    if (CODON_MAP.count(codon) != 0) {
        return CODON_MAP.at(codon);
    }
    return UNKNOWN_PROTEIN;
}

vector<string> proteins(string rna) {
    vector<string> ans;

    for (size_t i = 0; i < rna.size(); i += 3) {
        string codon = rna.substr(i, 3);
        string protein = translate_codon(codon);
        if (protein == UNKNOWN_PROTEIN) {
            continue;
        }
        if (protein == STOP_PROTEIN) {
            break;
        }
        ans.emplace_back(protein);
    }

    return ans;
}
}  // namespace protein_translation
