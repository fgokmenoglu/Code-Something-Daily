"""
Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells and carries the "instructions" for the development and functioning of living organisms.

If you want to know more: http://en.wikipedia.org/wiki/DNA

In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". Your function receives one side of the DNA (string, except for Haskell); you need to return the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).

More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)

Example: (input --> output)

"ATTGC" --> "TAACG"
"GTAT" --> "CATA"
"""
dna_complementary_map = { 
    'A' : 'T',
    'T' : 'A',
    'C' : 'G',
    'G' : 'C'
}

def DNA_strand(dna):
    return ''.join([dna_complementary_map[c] for c in dna])

# ALTERNATIVE
def DNA_strand(dna):
  return dna.translate(str.maketrans('ATCG', 'TAGC'))

"""
The translate() method returns a string where some specified characters are replaced with the character described in a mapping table. Use the maketrans() method to create a mapping table.
maketrans() creates a mapping table to be used in the translate() method to replace any ? characters with a ? character.
"""
