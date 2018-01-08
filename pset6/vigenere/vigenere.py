# program that encrypts messages using Vigenère’s cipher
import sys

def main():
    key = sys.argv[1]
    string_plaintext = input("plaintext:  ")
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    i = 0
    j = 0
    for i in range(len(string_plaintext)):
        if string_plaintext[i].isalpha():
            if j >= len(sys.argv[1]):
                j = 0
            if string_plaintext[i].islower():
                plain = alphabet.find(string_plaintext[i])
                cipher = alphabet.find(key[j])
                if plain + cipher > 25:
                    print(alphabet[(plain + cipher) % 26], end='')
                    j += 1
                else:
                    print(alphabet[plain + cipher], end='')
                    j += 1
            else:
                plain = alphabet.find(string_plaintext[i].lower())
                cipher = alphabet.find(key[j].lower())
                if plain + j > 25:
                    print(alphabet[(plain+ cipher) % 26].upper(), end='')
                    j += 1
                else:
                    print(alphabet[plain + cipher].upper(), end='')
                    j += 1
        else:
            print(string_plaintext[i], end='')
    print()

if __name__ == "__main__":
    main()