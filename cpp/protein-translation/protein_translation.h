#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <string>
#include <vector>

using namespace std;

namespace protein_translation {
string translate_codon(string codon);
vector<string> proteins(string rna);
}  // namespace protein_translation

#endif  // PROTEIN_TRANSLATION_H
