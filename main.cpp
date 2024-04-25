#include <iostream>

#include <string>

#include <map>


class AlKindiCryptanalysis {

private:

    std::map<char, int> frequencyMap;


public:

    std::string analyze(const std::string& ciphertext) {

        for (char c : ciphertext) {

            frequencyMap[c]++;

        }


        char mostFrequentChar = ciphertext[0];

        int maxFrequency = 0;


        for (auto pair : frequencyMap) {

            if (pair.second > maxFrequency) {

                mostFrequentChar = pair.first;

                maxFrequency = pair.second;

            }

        }


        std::string plaintext = "";

        for (int i = 0; i < ciphertext.length(); i++) {

            if (ciphertext[i] == mostFrequentChar) {

                plaintext += 'E';

            } else if (ciphertext[i] > mostFrequentChar) {

                plaintext += ciphertext[i] - 1;

            } else {

                plaintext += ciphertext[i] + 1;

            }

        }


        return plaintext;

    }

};


int main() {

    AlKindiCryptanalysis analyzer;

    std::string ciphertext;


    std::cout << "Enter the ciphertext: ";

    std::getline(std::cin, ciphertext);


    std::string plaintext = analyzer.analyze(ciphertext);


    std::cout << "The decrypted plaintext is: " << plaintext << std::endl;


    return 0;

}