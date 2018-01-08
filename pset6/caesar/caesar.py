# program that encrypts messages using Caesar’s cipher
import sys

def main():
    key = int(sys.argv[1])
    string_plaintext = input("plaintext:  ")
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    i = 0

    for i in range(len(string_plaintext)):
        if string_plaintext[i].isalpha():
            if string_plaintext[i].islower():
                plain = alphabet.find(string_plaintext[i])
                if plain + key > 25:
                    print(alphabet[(plain+ key) % 26], end='')
                else:
                    print(alphabet[plain + key], end='')
            else:
                plain = alphabet.find(string_plaintext[i].lower())
                if plain + key > 25:
                    print(alphabet[(plain+ key) % 26].upper(), end='')
                else:
                    print(alphabet[plain + key].upper(), end='')
        else:
            print(string_plaintext[i], end='')
    print()

if __name__ == "__main__":
    main()